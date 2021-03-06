//
// "$Id$"
//
// Dtk_Slot header file for the Dyne Toolkit.
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

#ifndef DTK_SLOT_H
#define DTK_SLOT_H


class Dtk_Slot_List;
class Dtk_Layout;
class Dtk_Script_Writer;
class Dtk_Template;
class Fldtk_Slot_Browser;


extern "C" {
#include "NewtType.h"
}


/** 
 * A Slot is a named set of data within a template.
 * 
 * Slots are manged by Dtk_Slot_List. The Slot List takes care of 
 * adding, removing, and renaming Slots in respect to the GUI.
 * 
 * Slots manage their own slot editor which is specific to the slot type.
 * See derived classes for other slot types.
 */
class Dtk_Slot
{
public:
  
  /** 
   * Initialize a slot
   */
  Dtk_Slot(Dtk_Slot_List *list, const char *key, newtRef slot);
  
  /** 
   * Clear all allocated resources.
   */
  virtual         ~Dtk_Slot();

  /**
   * Close any open connection to the outside world.
   *
   * Derived classes should close the slot editor here.
   */
  virtual void close();
  
  /** 
   * Return the key name of this slot as a C-String
   */
  const char      *key() const { return key_; }
  
  /** 
   * Set the key name of this slot.
   *
   * This call also updates all GUI.
   */
  void            setKey(const char *name);
  
  /** 
   * Pop up the editor for this slot.
   */
  virtual void    edit();
  
  /** 
   * Create a frame that can be saved to a layout file.
   */
  virtual newtRefVar save() { return kNewtRefUnbind; }
  
  /** 
   * Write this slot as a Newt Script.
   *
   * \retval 0 if successful
   * \retval negative if an error occured
   */     
  virtual int		write(Dtk_Script_Writer &sw) { return -1; }
  
  /** 
   * Find the address of the layout that manages this slot.
   */
  Dtk_Layout * layout();
  
  /** 
   * Apply the changes in the editor to the slot.
   */
  virtual void    apply() { }
  
  /** 
   * Revert the changes in the editor to the current slot sttings.
   */
  virtual void    revert() { }
  
  /**
   * Return the template that manages this slot.
   */
  Dtk_Template    * getTemplate();
  
protected:
  
  /// back reference to the slot list
  Dtk_Slot_List   * list_;
  
  /// this is the key name of the slot as a C-String.
  char            * key_;
  
  /// remember the datatype
  char            * datatype_;

  /// this browser manages all slots
  Fldtk_Slot_Browser  *browser_;

};


#endif

//
// End of "$Id$".
//
