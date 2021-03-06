//
// "$Id$"
//
// Dtk_Slot_List header file for the Dyne Toolkit.
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

#ifndef DTK_SLOT_LIST_H
#define DTK_SLOT_LIST_H


#include <vector>


class Dtk_Template;
class Dtk_Slot;
class Dtk_Layout;
class Fldtk_Slot_Browser;


/** Keep a list of slots.
 */
class Dtk_Slot_List
{
public:
  
  /** 
   * Initialize a slot list.
   *
   * Create an empty slot list and find the slot browser that we
   * will have to manage.
   */
  Dtk_Slot_List(Dtk_Template *tmpl);
  
  /** 
   * Remove a slot list and all referenced slots.
   *
   * Delete all referenced slots, then clear all references to
   * other resources.
   */
  ~Dtk_Slot_List();
  
  /** 
   * Append an existing slot to our list.
   *
   * Add an existing slot to the end of our slot list.
   * If this slot list is visible in the GUI, also add the slot
   * to the Slot Browser.
   */
  void append(Dtk_Slot *slot);
  
  /** 
   * Remove a slot from this list and from the GUI.
   */
  void remove(Dtk_Slot *slot);
  
  /**
   * Remove all slots in this list.
   *
   * Remove and then delete all members of the slot list (last to first).
   */
  void clear();
  
  /**
   * Return the number of slots in the list
   */
  int size();
  
  /**
   * Return the slot at the specified index.
   */
  Dtk_Slot *at(int index);
  
  /**
   * Return the slot with a given key.
   */
  Dtk_Slot *find(const char *key);
  
  /**
   * Return the tamplate that holds this slot list
   */
  Dtk_Template *getTemplate() { return template_; }
  
  /** 
   * Update the entry in the listy that points to the specified slot.
   */
  void updateKey(Dtk_Slot *slot);
  
  /** 
   * Find our layout document.
   */
  Dtk_Layout *getLayout();
  
private:
  
  /// back reference to the template that keeps this list
  Dtk_Template            * template_;
  
  /// stdlib list of documents
  std::vector<Dtk_Slot*>	slotList_;
  
  /// we are in charge of keeping this browser updated and reacting to its messages
  Fldtk_Slot_Browser *browser_;
};


#endif

//
// End of "$Id$".
//
