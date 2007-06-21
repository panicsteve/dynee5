//
// "$Id$"
//
// Dtk_Template implementation for the Dyne Toolkit.
//
// Copyright 2007 by Matthias Melcher.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "flmm@matthiasm.com".
//



#ifdef WIN32
#pragma warning(disable : 4996)
#endif

#include "Dtk_Template_List.h"
#include "Dtk_Layout_Document.h"
#include "Dtk_Slot_List.h"
#include "Dtk_Template.h"
#include "Dtk_Slot.h"
#include "Dtk_Script_Slot.h"
#include "Dtk_Rect_Slot.h"
#include "Dtk_Value_Slot.h"
#include "Dtk_Proto_Slot.h"
#include "Dtk_Script_Writer.h"

#include "flnt/Flnt_Widget.h"

#include "allNewt.h"

#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Group.H>


/*---------------------------------------------------------------------------*/
Dtk_Template::Dtk_Template(Dtk_Layout_Document *layout, Dtk_Template_List *list)
:   layout_(layout),
    list_(list),
    tmplList_(0L),
    slotList_(0L),
    index_(0),
    indent_(0),
    browser_(0L),
    browserName_(0L),
    ntName_(0L),
    ntId_(0L),
    viewBounds_(0L),
    viewJustify_(0L)
{
}


/*---------------------------------------------------------------------------*/
Dtk_Template::~Dtk_Template()
{
    delete ntId_;
    delete ntName_;
    delete browserName_;
    delete slotList_;
    delete tmplList_;
}

/*---------------------------------------------------------------------------*/
int Dtk_Template::load(newtRef node)
{
    // find the name of this template
    newtRef ntName = NewtGetFrameSlot(node, NewtFindSlotIndex(node, NSSYM(__ntName)));
    if (NewtRefIsString(ntName)) ntName_ = strdup(NewtRefToString(ntName));

    // find an ID; this does not mean too much as the ID can be changed later in the UI
    newtRef ntId = NewtGetFrameSlot(node, NewtFindSlotIndex(node, NSSYM(__ntId)));
    if (NewtRefIsSymbol(ntId)) ntId_ = strdup(NewtSymbolGetName(ntId));

    // now load all slots for this template
	newtRef value = NewtGetFrameSlot(node, NewtFindSlotIndex(node, NSSYM(value)));
    if (NewtRefIsFrame(value)) {
        int i, n = NewtFrameLength(value);
        if (n && !slotList_)
            slotList_ = new Dtk_Slot_List(this);
        for (i=0; i<n; i++) {
            uint32_t index;
            newtRef key = NewtGetFrameKey(value, i);
            newtRef slot = NewtGetFrameSlot(value, i);
            if (!NewtRefIsFrame(slot)) 
                continue;
            // the 'stepChildren slot generates a new template list with all children
            if (key==NSSYM(stepChildren)) {
			    newtRef a = NewtGetFrameSlot(slot, NewtFindSlotIndex(slot, NSSYM(value)));
			    if (NewtRefIsArray(a)) {
				    int i, n = NewtArrayLength(a);
                    if (n) {
                        tmplList_ = new Dtk_Template_List(this);
                    }
				    for (i=0; i<n; i++) {
                        Dtk_Template *tmpl = new Dtk_Template(layout_, tmplList_);
                        tmplList_->add(tmpl);
                        tmpl->load(NewtGetArraySlot(a, i));
				    }
			    }
                // everything's handled; now go and read the next slot
                continue;
            }
            // also 'viewBounds, 'viewClass, 'viewFlags, 'viewFormat
            //      'viewJustify, 'viewEffect, 'viewTransferMode, '_proto
            newtRef datatype = NewtGetFrameSlot(slot, NewtFindSlotIndex(slot, NSSYM(__ntDatatype)));
            Dtk_Slot *dSlot = 0L;
            if (NewtRefIsString(datatype)) {
                const char *dt = NewtRefToString(datatype);
                const char *keyname = NewtSymbolGetName(key);
                if (strcmp(dt, "SCPT")==0 || strcmp(dt, "EVAL")==0) {
                    dSlot = new Dtk_Script_Slot(slotList_, keyname, slot);
                } else if (strcmp(dt, "RECT")==0) {
                    dSlot = new Dtk_Rect_Slot(slotList_, keyname, slot);
                } else if (strcmp(dt, "NUMB")==0) {
                    dSlot = new Dtk_Value_Slot(slotList_, keyname, slot);
                } else if (strcmp(dt, "PROT")==0) {
                    dSlot = new Dtk_Proto_Slot(slotList_, keyname, slot);
                } else {
                    // also: RECT, CLAS, NUMB, PICT, PROT, USER, any more?
                    // CLAS is __ntTemplate
                    // PROT is __ntTemplate
                    // USER is __ntTemplate
                    // PICt is icon
                    printf("Unsupported slot datatype \"%s\" (%s)\n", dt, keyname);
                    dSlot = new Dtk_Slot(slotList_, keyname, slot);
                }
            }
            if (key==NSSYM(viewBounds)) {
                viewBounds_ = (Dtk_Rect_Slot*)dSlot;
            } else if (key==NSSYM(viewJustify)) {
                viewJustify_ = (Dtk_Value_Slot*)dSlot;
            }
            if (dSlot) {
                slotList_->add(dSlot);
            }
        }
    }
    return 0;
}


/*---------------------------------------------------------------------------*/
int Dtk_Template::write(Dtk_Script_Writer &sw)
{
    char buf[1024];

    // FIXME run the 'beforeScript

    Dtk_Template *p = parent();
    if (p) {
        sprintf(buf, "_view%03d := /* child of _view??? */\n", sw.viewCount++);
    } else {
        sprintf(buf, "_view%03d :=\n", sw.viewCount++);
    }
    sw.put(buf);
    sw.put("    {\n");

    if (slotList_) {
        int i, n = slotList_->size(), needComma = 0, ret = 0;
        for (i=0; i<n; i++) {
            if (needComma)
                sw.put(",\n");
            int ret = slotList_->at(i)->write(sw);
            needComma = (ret==0) ? 1 : 0;
        }
        if (needComma)
            sw.put("\n");
    }

    sw.put("    };\n\n");

    if (tmplList_) {
        int i, n = tmplList_->size();
        for (i=0; i<n; i++) {
            tmplList_->at(i)->write(sw);
        }
    }

    // FIXME run the 'afterScript

    return 0;
}


/*---------------------------------------------------------------------------*/
void Dtk_Template::updateBrowserLink(Fl_Hold_Browser *browser, int &indent, int &index, bool add)
{
    browser_ = browser;
    indent_ = indent;
    index_ = index++;
    if (add) {
        browser->add(browserName(), this);
	    widget_ = new Flnt_Widget(this);
    }
    if (tmplList_) {
        int i, n = tmplList_->size();
        indent++;
        for (i=0; i<n; i++) {
            Dtk_Template *tmpl = tmplList_->at(i);
            tmpl->updateBrowserLink(browser, indent, index, add);
        }
        indent--;
    }
    if (add) {
	    widget_->end();
    }
}

/*---------------------------------------------------------------------------*/
const char *Dtk_Template::browserName()
{
    if (browserName_)
        return browserName_;

    char *name = ntName_;
    char *id = ntId_;
    if (!id ||!*id)
        id = "-unknown-";

    char buf[512];
    memset(buf, ' ', 511);
    if (name && *name) {
        sprintf(buf+4*indent_, "%s <%s>", name, id);
    } else {
        sprintf(buf+4*indent_, "%s", id);
    }
    // FIXME there can also be a userProto. The Format is then
    //       infoButton <userProto> (protoInfoButton.lyt)
    browserName_ = strdup(buf);
    return browserName_;
}

/*---------------------------------------------------------------------------*/
void Dtk_Template::edit()
{
    Fl_Hold_Browser *slotBrowser = layout()->slotBrowser();
    slotBrowser->clear();
    if (slotList_) {
        int i, n = slotList_->size();
        for (i=0; i<n; i++) {
            Dtk_Slot *slot = slotList_->at(i);
            slotBrowser->add(slot->key(), slot);
        }
    }
}

/*---------------------------------------------------------------------------*/
void Dtk_Template::getSize(int &t, int &l, int &b, int &r)
{
    if (viewBounds_) {
        t = viewBounds_->top();
        l = viewBounds_->left();
        b = viewBounds_->bottom();
        r = viewBounds_->right();
    }
}

/*---------------------------------------------------------------------------*/
unsigned int Dtk_Template::justify()
{
    return viewJustify_ ? (unsigned int)viewJustify_->value() : 0;
}

/*---------------------------------------------------------------------------*/
void Dtk_Template::selectedInView()
{
    int i, n = browser_->size();
    for (i=1; i<=n; ++i) {
        if (browser_->data(i)==this)
            break;
    }
    if (i>n) return; // Ooops?
    browser_->value(i);
    browser_->do_callback();
}

/*---------------------------------------------------------------------------*/
char Dtk_Template::isSelected()
{
    return browser_->value()==index_ ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
Dtk_Template *Dtk_Template::parent()
{
    if (list_)
        return list_->parent();
    return 0L;
}


//
// End of "$Id$".
//
