//
// "$Id$"
//
// Dtk_Layout header file for the Dyne Toolkit.
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
// Please report all bugs and problems to "dtk@matthiasm.com".
//

#ifndef DTK_LAYOUT_H
#define DTK_LAYOUT_H


#include <dtk/Dtk_Document.h>


class Dtk_Template;
class Fldtk_Layout_Editor;
class Fldtk_Slot_Editor_Group;
class Fldtk_Layout_View;
class Fldtk_Tmpl_Browser;
class Fldtk_Slot_Browser;
class Fl_Wizard;

/*---------------------------------------------------------------------------*/
/**
 * A document of the the type Layout.
 */
class Dtk_Layout : public Dtk_Document
  {
  public:
    
    /**
     * Create a new empty Layout Document.
     *
     * To be useful, the layout must be linked to a Document List.
     */
    Dtk_Layout();
    
    /**
     * Clear the layout and all resources used by it.
     */
    virtual ~Dtk_Layout();
    
    /**
     * Clear all references to children.
     * 
     * This call removes all templates from this layout.
     */
    virtual void clear();
    
    void removeTemplates();
    
    virtual int		load();
    virtual int   edit();
    virtual int		save();
    virtual int		saveAs();
    virtual void	close();
    virtual int		getID() { return 0; }
    
    virtual bool    isLayout() { return true; }
    
    /** Write this document type as a Newt Script.
     *
     * Write the header, followed by all templates, followed
     * by the footer.
     *
     * \retval 0 if successful
     * \retval negative if an error occured
     */     
    virtual int		write(Dtk_Script_Writer &sw);
    
    /** Write a script line that will make the main form public.
     *
     * \retval 0 if successful
     * \retval negative if an error occured
     */     
    virtual int		writeTheForm(Dtk_Script_Writer &sw);
    
    /** Return true if there is a layout view and it is visible.
     */
    bool            editViewShown();
    
    /** Call this to update the pulldown menus in the layout editor.
     */ 
    void updateMenus();
    
    void editView();
    Fldtk_Tmpl_Browser * templateBrowser();
    Fldtk_Slot_Browser * slotBrowser();
    Fldtk_Slot_Editor_Group * slotEditor();
    Fldtk_Layout_View * layoutView() { return view_; }
    
    Dtk_Template    * addTemplate(int x, int y, int w, int h, char *proto=0L);
    
    void userChangedSlots();
    
  private:
    
    void            setupEditors(); 
    newtRef	        saveLayoutSettings();
    
    /// The root element of the tree of all templates inside this layout.
    Dtk_Template    * root_;
    
    /// Editor in the document tabs.
    Fldtk_Layout_Editor * editor_;
    
    /// Visual layout editor.
    Fldtk_Layout_View * view_;
    
    /// Visual layout editor.
    // Fldtk_Visual_Layout * visualEditor_;
    
    /// GUI callback whenever a different template is selected
    static void templateBrowser_cb(Fldtk_Tmpl_Browser*, Dtk_Layout*);
    
    /// GUI callback whenever a different slot is selected
    static void slotBrowser_cb(Fldtk_Slot_Browser*, Dtk_Layout*);
  };


#endif

//
// End of "$Id$".
//
