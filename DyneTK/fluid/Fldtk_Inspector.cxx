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

// generated by Fast Light User Interface Designer (fluid) version 1.0108

#include "Fldtk_Inspector.h"

void Fldtk_Inspector::cb_wConnect_i(Fl_Button*, void*) {
  InspectorConnect();
}
void Fldtk_Inspector::cb_wConnect(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_wConnect_i(o,v);
}

#include <FL/Fl_Pixmap.H>
static const char *idata_toolbox_closed[] = {
"18 17 4 1",
" \tc none",
".\tc #000000",
"+\tc #FF0000",
"@\tc #A7A6AA",
"                  ",
"                  ",
"                  ",
"                  ",
"       ....       ",
"      ..  ..      ",
"   ............   ",
"  .++++++++++++.  ",
" .++++++++++++++. ",
" ................ ",
" .++++@@@@@@++++. ",
" .+++@@++++@@+++. ",
" .++++++++++++++. ",
" .++++++++++++++. ",
" ................ ",
"                  ",
"                  "
};
static Fl_Pixmap image_toolbox_closed(idata_toolbox_closed);

static const char *idata_toolbox_inactive[] = {
"18 17 4 1",
" \tc none",
".\tc #777777",
"+\tc #999999",
"@\tc #bbbbbb",
"                  ",
"                  ",
"                  ",
"                  ",
"       ....       ",
"      ..  ..      ",
"   ............   ",
"  .++++++++++++.  ",
" .++++++++++++++. ",
" ................ ",
" .++++@@@@@@++++. ",
" .+++@@++++@@+++. ",
" .++++++++++++++. ",
" .++++++++++++++. ",
" ................ ",
"                  ",
"                  "
};
static Fl_Pixmap image_toolbox_inactive(idata_toolbox_inactive);

void Fldtk_Inspector::cb_Stop_i(Fl_Button*, void*) {
  InspectorStopOnThrows();
}
void Fldtk_Inspector::cb_Stop(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_Stop_i(o,v);
}

void Fldtk_Inspector::cb_Troff_i(Fl_Button*, void*) {
  InspectorTraceOff();
}
void Fldtk_Inspector::cb_Troff(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_Troff_i(o,v);
}

void Fldtk_Inspector::cb_bt_i(Fl_Button*, void*) {
  InspectorStackTrace();
}
void Fldtk_Inspector::cb_bt(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_bt_i(o,v);
}

void Fldtk_Inspector::cb_Exit_i(Fl_Button*, void*) {
  InspectorExitBreakLoop();
}
void Fldtk_Inspector::cb_Exit(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_Exit_i(o,v);
}

void Fldtk_Inspector::cb_0_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(0);
}
void Fldtk_Inspector::cb_0(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_0_i(o,v);
}

void Fldtk_Inspector::cb_1_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(1);
}
void Fldtk_Inspector::cb_1(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_1_i(o,v);
}

void Fldtk_Inspector::cb_2_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(2);
}
void Fldtk_Inspector::cb_2(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_2_i(o,v);
}

void Fldtk_Inspector::cb_3_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(3);
}
void Fldtk_Inspector::cb_3(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_3_i(o,v);
}

void Fldtk_Inspector::cb_4_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(4);
}
void Fldtk_Inspector::cb_4(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_4_i(o,v);
}

void Fldtk_Inspector::cb_5_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(5);
}
void Fldtk_Inspector::cb_5(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_5_i(o,v);
}

void Fldtk_Inspector::cb_6_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(6);
}
void Fldtk_Inspector::cb_6(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_6_i(o,v);
}

void Fldtk_Inspector::cb_7_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(7);
}
void Fldtk_Inspector::cb_7(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_7_i(o,v);
}

void Fldtk_Inspector::cb_8_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(8);
}
void Fldtk_Inspector::cb_8(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_8_i(o,v);
}

void Fldtk_Inspector::cb_9_i(Fl_Menu_*, void*) {
  InspectorPrintDepth(9);
}
void Fldtk_Inspector::cb_9(Fl_Menu_* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()->user_data()))->cb_9_i(o,v);
}

Fl_Menu_Item Fldtk_Inspector::menu_[] = {
 {"0", 0,  (Fl_Callback*)Fldtk_Inspector::cb_0, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"1", 0,  (Fl_Callback*)Fldtk_Inspector::cb_1, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"2", 0,  (Fl_Callback*)Fldtk_Inspector::cb_2, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"3", 0,  (Fl_Callback*)Fldtk_Inspector::cb_3, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"4", 0,  (Fl_Callback*)Fldtk_Inspector::cb_4, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"5", 0,  (Fl_Callback*)Fldtk_Inspector::cb_5, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"6", 0,  (Fl_Callback*)Fldtk_Inspector::cb_6, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"7", 0,  (Fl_Callback*)Fldtk_Inspector::cb_7, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"8", 0,  (Fl_Callback*)Fldtk_Inspector::cb_8, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"9", 0,  (Fl_Callback*)Fldtk_Inspector::cb_9, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

void Fldtk_Inspector::cb_Test_i(Fl_Button*, void*) {
  send_test(1);
}
void Fldtk_Inspector::cb_Test(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_Test_i(o,v);
}

void Fldtk_Inspector::cb_Test1_i(Fl_Button*, void*) {
  send_test(2);
}
void Fldtk_Inspector::cb_Test1(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_Test1_i(o,v);
}

void Fldtk_Inspector::cb_Test2_i(Fl_Button*, void*) {
  send_test(3);
}
void Fldtk_Inspector::cb_Test2(Fl_Button* o, void* v) {
  ((Fldtk_Inspector*)(o->parent()->parent()))->cb_Test2_i(o,v);
}
Fldtk_Inspector::Fldtk_Inspector(int X, int Y, int W, int H, const char *L)
  : Fl_Group(0, 0, W, H, L) {
{ Fl_Group* o = new Fl_Group(0, 0, 775, 35);
  o->box(FL_FLAT_BOX);
  { wConnect = new Fl_Button(5, 5, 25, 25);
    wConnect->tooltip("Connect/Disconnect");
    wConnect->image(image_toolbox_closed);
    wConnect->deimage(image_toolbox_inactive);
    wConnect->labelsize(9);
    wConnect->labelcolor(FL_GRAY0);
    wConnect->callback((Fl_Callback*)cb_wConnect);
    wInspectorConnect = wConnect;
  } // Fl_Button* wConnect
  { Fl_Button* o = new Fl_Button(30, 5, 25, 25, "Stop");
    o->tooltip("Stop on throws");
    o->labelsize(9);
    o->labelcolor(FL_GRAY0);
    o->callback((Fl_Callback*)cb_Stop);
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(55, 5, 25, 25, "Troff");
    o->tooltip("Trace off");
    o->labelsize(9);
    o->labelcolor(FL_GRAY0);
    o->callback((Fl_Callback*)cb_Troff);
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(80, 5, 25, 25, "bt");
    o->tooltip("Stack trace");
    o->labelsize(9);
    o->labelcolor(FL_GRAY0);
    o->callback((Fl_Callback*)cb_bt);
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(105, 5, 25, 25, "Exit");
    o->tooltip("Exit break loop");
    o->labelsize(9);
    o->labelcolor(FL_GRAY0);
    o->callback((Fl_Callback*)cb_Exit);
  } // Fl_Button* o
  { Fl_Choice* o = new Fl_Choice(135, 6, 50, 23);
    o->tooltip("Print Depth");
    o->down_box(FL_BORDER_BOX);
    o->menu(menu_);
  } // Fl_Choice* o
  { Fl_Box* o = new Fl_Box(440, 5, 120, 25);
    Fl_Group::current()->resizable(o);
  } // Fl_Box* o
  { serial = new Flio_Inspector(715, 7, 55, 21);
    serial->box(FL_DOWN_BOX);
    serial->color(FL_BACKGROUND_COLOR);
    serial->selection_color(FL_BACKGROUND_COLOR);
    serial->labeltype(FL_NORMAL_LABEL);
    serial->labelfont(0);
    serial->labelsize(14);
    serial->labelcolor(FL_FOREGROUND_COLOR);
    serial->align(FL_ALIGN_CENTER);
    serial->when(FL_WHEN_RELEASE);
    wInspectorSerial = serial;
  } // Flio_Inspector* serial
  { Fl_Button* o = new Fl_Button(215, 5, 25, 25, "Test\n1");
    o->labelsize(9);
    o->labelcolor(FL_GRAY0);
    o->callback((Fl_Callback*)cb_Test);
    o->hide();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(240, 5, 25, 25, "Test\n2");
    o->labelsize(9);
    o->labelcolor(FL_GRAY0);
    o->callback((Fl_Callback*)cb_Test1);
    o->hide();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(265, 5, 25, 25, "Test\n3");
    o->labelsize(9);
    o->labelcolor(FL_GRAY0);
    o->callback((Fl_Callback*)cb_Test2);
    o->hide();
  } // Fl_Button* o
  o->end();
} // Fl_Group* o
{ Flmm_Console* o = console = new Flmm_Console(0, 35, 775, 104);
  console->tooltip("Connect/Disconnect");
  console->box(FL_DOWN_FRAME);
  console->color(FL_BACKGROUND2_COLOR);
  console->selection_color(FL_SELECTION_COLOR);
  console->labeltype(FL_NORMAL_LABEL);
  console->labelfont(0);
  console->labelsize(14);
  console->labelcolor(FL_FOREGROUND_COLOR);
  console->textfont(4);
  console->textsize(12);
  console->align(FL_ALIGN_TOP);
  console->when(FL_WHEN_ENTER_KEY_ALWAYS);
  Fl_Group::current()->resizable(console);
  o->buffer(new Fl_Text_Buffer);
  wConsole = console;
} // Flmm_Console* console
position(X, Y);
end();
}

//
// Copyright (C) 2007 Matthias Melcher
//
