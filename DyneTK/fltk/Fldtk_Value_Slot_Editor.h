//
// "$Id$"
//
// Fldtk_Value_Slot_Editor header file for the FLMM extension to FLTK.
//
// Copyright 2002-2007 by Matthias Melcher.
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

#ifndef FLDTK_VALUE_SLOT_EDITOR_H
#define FLDTK_VALUE_SLOT_EDITOR_H


#include <FL/Fl_Group.H>


class Dtk_Value_Slot;
class Fl_Input;


/** GUI for editing value slots.
 */
class Fldtk_Value_Slot_Editor : public Fl_Group
{
public:
	        Fldtk_Value_Slot_Editor(Fl_Group *container, Dtk_Value_Slot *slot);
    virtual ~Fldtk_Value_Slot_Editor();
    virtual void    value(double v);
    virtual double  value();

protected:
    Dtk_Value_Slot * slot_;
    Fl_Input    *wValue_;
    static void editor_cb(Fldtk_Value_Slot_Editor *w, unsigned int cmd);
};


#endif

//
// End of "$Id$".
//
