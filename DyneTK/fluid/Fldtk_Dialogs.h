//
// DyneTK, the Dyne Toolkit
// Copyright (C) 2007 Matthias Melcher
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

// generated by Fast Light User Interface Designer (fluid) version 1.0108

#ifndef Fldtk_Dialogs_h
#define Fldtk_Dialogs_h
#include <FL/Fl.H>
#include "allNewt.h"
#include "dtk/Dtk_Project.h"
#include "dtk/Dtk_Template.h"
#include "dtk/Dtk_Platform.h"
#include "main.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>

class Fldtk_New_Slot_Dialog : public Fl_Window {
  void _Fldtk_New_Slot_Dialog();
public:
  Fldtk_New_Slot_Dialog(int X, int Y, int W, int H, const char *L = 0);
  Fldtk_New_Slot_Dialog(int W, int H, const char *L = 0);
  Fl_Box *wTemplateProto;
  Fl_Menu_Button *wSpecific;
private:
  void cb_wSpecific_i(Fl_Menu_Button*, void*);
  static void cb_wSpecific(Fl_Menu_Button*, void*);
public:
  Fl_Menu_Button *wMethods;
private:
  void cb_wMethods_i(Fl_Menu_Button*, void*);
  static void cb_wMethods(Fl_Menu_Button*, void*);
public:
  Fl_Menu_Button *wAttributes;
private:
  void cb_wAttributes_i(Fl_Menu_Button*, void*);
  static void cb_wAttributes(Fl_Menu_Button*, void*);
public:
  Fl_Input *wSlotName;
private:
  void cb_wSlotName_i(Fl_Input*, void*);
  static void cb_wSlotName(Fl_Input*, void*);
public:
  Fl_Choice *wEditor;
  static Fl_Menu_Item menu_wEditor[];
private:
  void cb_Number_i(Fl_Menu_*, char*);
  static void cb_Number(Fl_Menu_*, char*);
public:
  Fl_Box *wHelp;
  Fl_Button *wAdd;
private:
  void cb_wAdd_i(Fl_Button*, void*);
  static void cb_wAdd(Fl_Button*, void*);
public:
  Fl_Button *wDone;
private:
  void cb_wDone_i(Fl_Button*, void*);
  static void cb_wDone(Fl_Button*, void*);
  Dtk_Template *tmpl_; 
public:
  void setTemplate(Dtk_Template *tmpl);
};

class Fldtk_Declare_To_Dialog : public Fl_Window {
  void _Fldtk_Declare_To_Dialog();
public:
  Fldtk_Declare_To_Dialog(int X, int Y, int W, int H, const char *L = 0);
  Fldtk_Declare_To_Dialog(int W, int H, const char *L = 0);
  Fl_Input *wName;
private:
  void cb_wName_i(Fl_Input*, void*);
  static void cb_wName(Fl_Input*, void*);
public:
  Fl_Choice *wParent;
  static Fl_Menu_Item menu_wParent[];
  Fl_Button *wCancel;
private:
  void cb_wCancel_i(Fl_Button*, void*);
  static void cb_wCancel(Fl_Button*, void*);
public:
  Fl_Button *wOK;
private:
  void cb_wOK_i(Fl_Button*, void*);
  static void cb_wOK(Fl_Button*, void*);
  Dtk_Template *tmpl_; 
public:
  void setTemplate(Dtk_Template *tmpl);
};
#endif

//
// DyneTK, the Dyne Toolkit
// Copyright (C) 2007 Matthias Melcher
//
