//
// DyneTK, The Dyne Toolkit
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

// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef Fldtk_Inspector_h
#define Fldtk_Inspector_h
#include <FL/Fl.H>
#include "fltk/Flio_Inspector.h"
#include "fltk/Flmm_Console.h"
#include "main.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Box.H>

class Fldtk_Inspector : public Fl_Group {
public:
  Fldtk_Inspector(int X, int Y, int W, int H, const char *L = 0);
  Fl_Button *wConnect;
private:
  void cb_wConnect_i(Fl_Button*, void*);
  static void cb_wConnect(Fl_Button*, void*);
public:
  Fl_Button *tStopOnThrows;
private:
  void cb_tStopOnThrows_i(Fl_Button*, void*);
  static void cb_tStopOnThrows(Fl_Button*, void*);
public:
  Fl_Button *tTrace;
private:
  void cb_tTrace_i(Fl_Button*, void*);
  static void cb_tTrace(Fl_Button*, void*);
public:
  Fl_Button *tStackTrace;
private:
  void cb_tStackTrace_i(Fl_Button*, void*);
  static void cb_tStackTrace(Fl_Button*, void*);
public:
  Fl_Button *tExitBreakLoop;
private:
  void cb_tExitBreakLoop_i(Fl_Button*, void*);
  static void cb_tExitBreakLoop(Fl_Button*, void*);
public:
  Fl_Choice *tPrintDepth;
  static Fl_Menu_Item menu_tPrintDepth[];
private:
  void cb_0_i(Fl_Menu_*, void*);
  static void cb_0(Fl_Menu_*, void*);
  void cb_1_i(Fl_Menu_*, void*);
  static void cb_1(Fl_Menu_*, void*);
  void cb_2_i(Fl_Menu_*, void*);
  static void cb_2(Fl_Menu_*, void*);
  void cb_3_i(Fl_Menu_*, void*);
  static void cb_3(Fl_Menu_*, void*);
  void cb_4_i(Fl_Menu_*, void*);
  static void cb_4(Fl_Menu_*, void*);
  void cb_5_i(Fl_Menu_*, void*);
  static void cb_5(Fl_Menu_*, void*);
  void cb_6_i(Fl_Menu_*, void*);
  static void cb_6(Fl_Menu_*, void*);
  void cb_7_i(Fl_Menu_*, void*);
  static void cb_7(Fl_Menu_*, void*);
  void cb_8_i(Fl_Menu_*, void*);
  static void cb_8(Fl_Menu_*, void*);
  void cb_9_i(Fl_Menu_*, void*);
  static void cb_9(Fl_Menu_*, void*);
public:
  Flio_Inspector *serial;
  Flmm_Console *console;
  void activate_menus(unsigned int mask);
};
#endif

//
// Copyright (C) 2007 Matthias Melcher
//
