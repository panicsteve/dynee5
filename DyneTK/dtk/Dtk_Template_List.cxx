//
// "$Id$"
//
// Dtk_Template_List implementation for the Dyne Toolkit.
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
#include "Dtk_Template.h"
#include "Dtk_Layout.h"

#include "fltk/Fldtk_Tmpl_Browser.h"


/*---------------------------------------------------------------------------*/
Dtk_Template_List::Dtk_Template_List(Dtk_Template *parent)
:   parent_(parent)
{
}


/*---------------------------------------------------------------------------*/
Dtk_Template_List::~Dtk_Template_List()
{
  clear();
}


/*---------------------------------------------------------------------------*/
void Dtk_Template_List::append(Dtk_Template *tmpl)
{
  tmplList_.push_back(tmpl);
  tmpl->setList(this);
  /// \todo This class should be a part-owner of the template browser and update the browser to reflect the addition
}


/*---------------------------------------------------------------------------*/
void Dtk_Template_List::remove(Dtk_Template *tmpl) 
{
  tmpl->deleteAllSlots();
  tmpl->deleteAllChildren();
  // search the list for this template
  int i, n = tmplList_.size();
  for (i=n-1; i>=0; --i) {
    if (tmplList_.at(i)==tmpl) {
      // remove the template from the browser
      Dtk_Layout *lyt = tmpl->layout();
      Fldtk_Tmpl_Browser *browser = lyt->templateBrowser();
      if (browser) {
        int j, nb = browser->size();
        for (j=nb; j>0; --j) {
          if (browser->data(j)==tmpl) {
            if (browser->value()==j)
              browser->value(0);
            browser->remove(j);
          }
        }
      }
      // take the template out of the list
      tmplList_.erase(tmplList_.begin()+i);
      // and remove the link back to the list
      tmpl->setList(0L);
      break;
    }
  }
}


/*---------------------------------------------------------------------------*/
void Dtk_Template_List::clear()
{
  int i, n = tmplList_.size();
  for (i=n-1; i>=0; --i) {
    Dtk_Template *tmpl = tmplList_.at(i);
    tmpl->clear();
    remove(tmpl);
    delete tmpl;
  }
}


//
// End of "$Id$".
//
