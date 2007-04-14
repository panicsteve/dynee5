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

#ifndef main_ui_h
#define main_ui_h
#include <FL/Fl.H>
#include "fltk/Flio_Inspector.h"
#include "fltk/Flmm_Console.h"
#include "fluid/Fldtk_Inspector.h"
#include "fltk/Fldtk_Document_Tabs.h"
#include "fltk/Fldtk_Document_Browser.h"
#include "fltk/Fldtk_Layout_Drop_Box.h"
#include <FL/fl_ask.h>
#include "main.h"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Tabs.H>

class Fldtk_Main_Window : public Fl_Double_Window {
  void _Fldtk_Main_Window();
public:
  Fldtk_Main_Window(int X, int Y, int W, int H, const char *L = 0);
  Fldtk_Main_Window(int W, int H, const char *L = 0);
  static Fl_Menu_Item menu_[];
  static Fl_Menu_Item *mFile;
  static Fl_Menu_Item *mFileNewText;
private:
  void cb_mFileNewText_i(Fl_Menu_*, void*);
  static void cb_mFileNewText(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mFileOpen;
private:
  void cb_mFileOpen_i(Fl_Menu_*, void*);
  static void cb_mFileOpen(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mFileClose;
private:
  void cb_mFileClose_i(Fl_Menu_*, void*);
  static void cb_mFileClose(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mFileSave;
private:
  void cb_mFileSave_i(Fl_Menu_*, void*);
  static void cb_mFileSave(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mFileSaveAs;
private:
  void cb_mFileSaveAs_i(Fl_Menu_*, void*);
  static void cb_mFileSaveAs(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mFileExit;
private:
  void cb_mFileExit_i(Fl_Menu_*, void*);
  static void cb_mFileExit(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mEdit;
  static Fl_Menu_Item *mEditPreferences;
private:
  void cb_mEditPreferences_i(Fl_Menu_*, void*);
  static void cb_mEditPreferences(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProject;
  static Fl_Menu_Item *mProjectNew;
private:
  void cb_mProjectNew_i(Fl_Menu_*, void*);
  static void cb_mProjectNew(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectOpen;
private:
  void cb_mProjectOpen_i(Fl_Menu_*, void*);
  static void cb_mProjectOpen(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectSave;
private:
  void cb_mProjectSave_i(Fl_Menu_*, void*);
  static void cb_mProjectSave(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectSaveAs;
private:
  void cb_mProjectSaveAs_i(Fl_Menu_*, void*);
  static void cb_mProjectSaveAs(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectAddWindow;
private:
  void cb_mProjectAddWindow_i(Fl_Menu_*, void*);
  static void cb_mProjectAddWindow(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectAddFile;
private:
  void cb_mProjectAddFile_i(Fl_Menu_*, void*);
  static void cb_mProjectAddFile(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectRemoveFile;
private:
  void cb_mProjectRemoveFile_i(Fl_Menu_*, void*);
  static void cb_mProjectRemoveFile(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectBuild;
private:
  void cb_mProjectBuild_i(Fl_Menu_*, void*);
  static void cb_mProjectBuild(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectDownload;
private:
  void cb_mProjectDownload_i(Fl_Menu_*, void*);
  static void cb_mProjectDownload(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectLaunch;
private:
  void cb_mProjectLaunch_i(Fl_Menu_*, void*);
  static void cb_mProjectLaunch(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mProjectSettings;
private:
  void cb_mProjectSettings_i(Fl_Menu_*, void*);
  static void cb_mProjectSettings(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mLayout;
  static Fl_Menu_Item *mBrowser;
  static Fl_Menu_Item *mWindow;
  static Fl_Menu_Item *mWindowConnectInspector;
private:
  void cb_mWindowConnectInspector_i(Fl_Menu_*, void*);
  static void cb_mWindowConnectInspector(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *mHelp;
  static Fl_Menu_Item *mHelpAbout;
private:
  void cb_mHelpAbout_i(Fl_Menu_*, void*);
  static void cb_mHelpAbout(Fl_Menu_*, void*);
public:
  Fl_Button *tSnapshot;
private:
  void cb_tSnapshot_i(Fl_Button*, void*);
  static void cb_tSnapshot(Fl_Button*, void*);
  static Fl_Menu_Item menu_1[];
  static Fl_Menu_Item menu_2[];
public:
  Fl_Tile *center;
  Fl_Tabs *browsers;
  Fldtk_Document_Browser *documents;
  Fldtk_Document_Tabs *document_tabs;
  Fl_Tabs *consoles;
  Fldtk_Inspector *inspector;
  void activate_menus(unsigned int mask);
};
Fl_Double_Window* create_connect_dialog();
#endif

//
// Copyright (C) 2007 Matthias Melcher
//
