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

#include "main_ui.h"

void Fldtk_Main_Window::cb_mFileNewText_i(Fl_Menu_*, void*) {
  NewTextFile();
}
void Fldtk_Main_Window::cb_mFileNewText(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mFileNewText_i(o,v);
}

void Fldtk_Main_Window::cb_mFileOpen_i(Fl_Menu_*, void*) {
  OpenDocument();
}
void Fldtk_Main_Window::cb_mFileOpen(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mFileOpen_i(o,v);
}

void Fldtk_Main_Window::cb_mFileClose_i(Fl_Menu_*, void*) {
  CloseCurrentDocument();
}
void Fldtk_Main_Window::cb_mFileClose(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mFileClose_i(o,v);
}

void Fldtk_Main_Window::cb_mFileSave_i(Fl_Menu_*, void*) {
  SaveCurrentDocument();
}
void Fldtk_Main_Window::cb_mFileSave(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mFileSave_i(o,v);
}

void Fldtk_Main_Window::cb_mFileSaveAs_i(Fl_Menu_*, void*) {
  SaveCurrentDocumentAs();
}
void Fldtk_Main_Window::cb_mFileSaveAs(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mFileSaveAs_i(o,v);
}

void Fldtk_Main_Window::cb_mFileExit_i(Fl_Menu_*, void*) {
  ExitApplication();
}
void Fldtk_Main_Window::cb_mFileExit(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mFileExit_i(o,v);
}

void Fldtk_Main_Window::cb_mEditPreferences_i(Fl_Menu_*, void*) {
  EditPreferences();
}
void Fldtk_Main_Window::cb_mEditPreferences(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mEditPreferences_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectNew_i(Fl_Menu_*, void*) {
  NewProject();
}
void Fldtk_Main_Window::cb_mProjectNew(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectNew_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectOpen_i(Fl_Menu_*, void*) {
  OpenProject();
}
void Fldtk_Main_Window::cb_mProjectOpen(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectOpen_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectSave_i(Fl_Menu_*, void*) {
  SaveProject();
}
void Fldtk_Main_Window::cb_mProjectSave(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectSave_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectSaveAs_i(Fl_Menu_*, void*) {
  SaveProjectAs();
}
void Fldtk_Main_Window::cb_mProjectSaveAs(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectSaveAs_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectAddWindow_i(Fl_Menu_*, void*) {
  AddCurrentDocToProject();
}
void Fldtk_Main_Window::cb_mProjectAddWindow(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectAddWindow_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectAddFile_i(Fl_Menu_*, void*) {
  AddFileToProject();
}
void Fldtk_Main_Window::cb_mProjectAddFile(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectAddFile_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectRemoveFile_i(Fl_Menu_*, void*) {
  RemoveFileFromProject();
}
void Fldtk_Main_Window::cb_mProjectRemoveFile(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectRemoveFile_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectBuild_i(Fl_Menu_*, void*) {
  BuildPackage();
}
void Fldtk_Main_Window::cb_mProjectBuild(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectBuild_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectDownload_i(Fl_Menu_*, void*) {
  DownloadPackage();
}
void Fldtk_Main_Window::cb_mProjectDownload(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectDownload_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectLaunch_i(Fl_Menu_*, void*) {
  LaunchPackage();
}
void Fldtk_Main_Window::cb_mProjectLaunch(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectLaunch_i(o,v);
}

void Fldtk_Main_Window::cb_mProjectSettings_i(Fl_Menu_*, void*) {
  ShowProjectSettings();
}
void Fldtk_Main_Window::cb_mProjectSettings(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mProjectSettings_i(o,v);
}

void Fldtk_Main_Window::cb_mWindowConnectInspector_i(Fl_Menu_*, void*) {
  InspectorConnect();
}
void Fldtk_Main_Window::cb_mWindowConnectInspector(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mWindowConnectInspector_i(o,v);
}

void Fldtk_Main_Window::cb_mHelpAbout_i(Fl_Menu_*, void*) {
  fl_message("Welcome to the Dyne Toolkit...");
}
void Fldtk_Main_Window::cb_mHelpAbout(Fl_Menu_* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->user_data()))->cb_mHelpAbout_i(o,v);
}

Fl_Menu_Item Fldtk_Main_Window::menu_[] = {
 {"File", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 12, 0},
 {"New Layout", 0x4006e,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"New Proto Template", 0x40074,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"New Text File", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mFileNewText, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {"Open...", 0x4006f,  (Fl_Callback*)Fldtk_Main_Window::cb_mFileOpen, 0, 128, FL_NORMAL_LABEL, 0, 12, 0},
 {"Link Layout...", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Close", 0x40077,  (Fl_Callback*)Fldtk_Main_Window::cb_mFileClose, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Save", 0x40073,  (Fl_Callback*)Fldtk_Main_Window::cb_mFileSave, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Save As...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mFileSaveAs, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Save All", 0x4006d,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Revert", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Print Setup...", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Print One", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Print...", 0x40070,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"1: prev file", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"2: prev file", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"3: prev file", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"4: prev file", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Exit", 0x40071,  (Fl_Callback*)Fldtk_Main_Window::cb_mFileExit, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Edit", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 12, 0},
 {"Undo", 0x4007a,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Redo", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Cut", 0x40078,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Copy", 0x40063,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Paste", 0x40076,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Clear", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Duplicate", 0x40064,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Shift Left", 0x4005b,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Shift Right", 0x4005d,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Select All", 0x40061,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Select Hierarchy", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Select in Layout", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Search...", 0x40072,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Find...", 0x40066,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Find Next", 0x40067,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Find Inherited", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Newt Screen Shot", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Toolkit Preferences...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mEditPreferences, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Project", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 12, 0},
 {"New Project...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectNew, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {"Open Project...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectOpen, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {"Save Project", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectSave, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Save Project As...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectSaveAs, 0, 129, FL_NORMAL_LABEL, 0, 12, 0},
 {"Add Window", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectAddWindow, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Add File...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectAddFile, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Remove File", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectRemoveFile, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Update Files", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Build Package", 0x40031,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectBuild, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Download Package", 0x40032,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectDownload, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Launch Package", 0x40033,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectLaunch, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {"Export Package to Text", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Install Toolkit App", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Mark as Main Layout", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Process Earlier", 0x4ff52,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Process Later", 0x4ff54,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Settings...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mProjectSettings, 0, 1, FL_NORMAL_LABEL, 0, 12, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Layout", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 12, 0},
 {"Layout Size...", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Autogrid On", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Set Grid...", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Move to Front", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Move Forward", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Move to Back", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Move Backward", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Alignment...", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Align", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Preview", 0x40079,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {0,0,0,0,0,0,0,0,0},
 {"Browser", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 12, 0},
 {"Template Info", 0x40069,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"New Slot...", 0x5006e,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Rename Slot...", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Templates by Type", 0,  0, 0, 3, FL_NORMAL_LABEL, 0, 12, 176},
 {"Templates by Hierarchy", 0,  0, 0, 3, FL_NORMAL_LABEL, 0, 12, 176},
 {"Slots by Name", 0,  0, 0, 3, FL_NORMAL_LABEL, 0, 12, 176},
 {"Slots by Type", 0,  0, 0, 3, FL_NORMAL_LABEL, 0, 12, 176},
 {"Show Slot Values", 0,  0, 0, 131, FL_NORMAL_LABEL, 0, 12, 176},
 {"Apply", 0x40065,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Revert", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {0,0,0,0,0,0,0,0,0},
 {"Window", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 12, 0},
 {"Open Inspector", 0,  0, 0, 17, FL_NORMAL_LABEL, 0, 12, 176},
 {"Connect Inspector", 0x4006b,  (Fl_Callback*)Fldtk_Main_Window::cb_mWindowConnectInspector, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {"New Brower", 0x40062,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Open Layout", 0x4006c,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"Cascade", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Tile", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Arrange Icons", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Set Default WIndow Position", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"1: WIndow", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {0,0,0,0,0,0,0,0,0},
 {"Help", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 12, 0},
 {"Contents", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Newton OS Error Codes", 0,  0, 0, 1, FL_NORMAL_LABEL, 0, 12, 176},
 {"Using Help", 0,  0, 0, 129, FL_NORMAL_LABEL, 0, 12, 176},
 {"About Dyne Toolkit...", 0,  (Fl_Callback*)Fldtk_Main_Window::cb_mHelpAbout, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};
Fl_Menu_Item* Fldtk_Main_Window::mFile = Fldtk_Main_Window::menu_ + 0;
Fl_Menu_Item* Fldtk_Main_Window::mFileNewText = Fldtk_Main_Window::menu_ + 3;
Fl_Menu_Item* Fldtk_Main_Window::mFileOpen = Fldtk_Main_Window::menu_ + 4;
Fl_Menu_Item* Fldtk_Main_Window::mFileClose = Fldtk_Main_Window::menu_ + 6;
Fl_Menu_Item* Fldtk_Main_Window::mFileSave = Fldtk_Main_Window::menu_ + 7;
Fl_Menu_Item* Fldtk_Main_Window::mFileSaveAs = Fldtk_Main_Window::menu_ + 8;
Fl_Menu_Item* Fldtk_Main_Window::mFileExit = Fldtk_Main_Window::menu_ + 18;
Fl_Menu_Item* Fldtk_Main_Window::mEdit = Fldtk_Main_Window::menu_ + 20;
Fl_Menu_Item* Fldtk_Main_Window::mEditPreferences = Fldtk_Main_Window::menu_ + 38;
Fl_Menu_Item* Fldtk_Main_Window::mProject = Fldtk_Main_Window::menu_ + 40;
Fl_Menu_Item* Fldtk_Main_Window::mProjectNew = Fldtk_Main_Window::menu_ + 41;
Fl_Menu_Item* Fldtk_Main_Window::mProjectOpen = Fldtk_Main_Window::menu_ + 42;
Fl_Menu_Item* Fldtk_Main_Window::mProjectSave = Fldtk_Main_Window::menu_ + 43;
Fl_Menu_Item* Fldtk_Main_Window::mProjectSaveAs = Fldtk_Main_Window::menu_ + 44;
Fl_Menu_Item* Fldtk_Main_Window::mProjectAddWindow = Fldtk_Main_Window::menu_ + 45;
Fl_Menu_Item* Fldtk_Main_Window::mProjectAddFile = Fldtk_Main_Window::menu_ + 46;
Fl_Menu_Item* Fldtk_Main_Window::mProjectRemoveFile = Fldtk_Main_Window::menu_ + 47;
Fl_Menu_Item* Fldtk_Main_Window::mProjectBuild = Fldtk_Main_Window::menu_ + 49;
Fl_Menu_Item* Fldtk_Main_Window::mProjectDownload = Fldtk_Main_Window::menu_ + 50;
Fl_Menu_Item* Fldtk_Main_Window::mProjectLaunch = Fldtk_Main_Window::menu_ + 51;
Fl_Menu_Item* Fldtk_Main_Window::mProjectSettings = Fldtk_Main_Window::menu_ + 57;
Fl_Menu_Item* Fldtk_Main_Window::mLayout = Fldtk_Main_Window::menu_ + 59;
Fl_Menu_Item* Fldtk_Main_Window::mBrowser = Fldtk_Main_Window::menu_ + 71;
Fl_Menu_Item* Fldtk_Main_Window::mWindow = Fldtk_Main_Window::menu_ + 83;
Fl_Menu_Item* Fldtk_Main_Window::mWindowConnectInspector = Fldtk_Main_Window::menu_ + 85;
Fl_Menu_Item* Fldtk_Main_Window::mHelp = Fldtk_Main_Window::menu_ + 94;
Fl_Menu_Item* Fldtk_Main_Window::mHelpAbout = Fldtk_Main_Window::menu_ + 98;

void Fldtk_Main_Window::cb_tSnapshot_i(Fl_Button*, void*) {
  InspectorSnapshot();
}
void Fldtk_Main_Window::cb_tSnapshot(Fl_Button* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->parent()))->cb_tSnapshot_i(o,v);
}

#include <FL/Fl_Image.H>
static unsigned char idata_camera[] =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,152,152,152,133,144,144,144,199,139,139,139,
208,136,136,136,209,129,129,129,214,120,120,120,220,113,113,113,225,111,111,111,
226,118,118,118,220,136,136,136,144,0,0,0,0,0,0,0,0,92,92,92,51,92,92,92,18,0,0,
0,0,149,149,149,15,152,152,152,255,201,201,201,255,200,200,200,255,198,198,
198,255,196,196,196,255,155,147,127,255,249,224,164,255,243,190,65,255,133,124,
105,255,147,147,146,255,109,109,109,94,92,92,92,241,92,92,92,255,92,92,92,254,
92,92,92,53,109,109,109,219,174,174,174,255,210,210,210,255,176,176,176,255,
163,163,163,255,159,159,159,255,183,183,183,255,152,152,152,255,158,158,158,255,
192,192,192,255,170,170,170,255,114,114,114,255,105,105,105,255,106,106,106,255,
103,103,103,255,83,83,83,216,108,108,108,255,188,188,188,255,166,166,166,255,
188,188,188,255,221,221,221,255,216,216,216,255,213,213,213,255,204,204,204,255,
163,163,163,255,132,132,132,255,151,151,151,255,180,180,180,255,157,157,157,255,
141,141,141,255,136,136,136,255,64,64,64,255,105,105,105,255,166,166,166,255,
186,186,186,255,183,199,218,255,105,154,212,255,94,150,213,255,92,150,213,255,
99,151,209,255,162,179,197,255,150,150,150,255,113,113,113,255,174,174,174,255,
152,152,152,255,104,104,104,255,129,129,129,255,62,62,62,255,103,103,103,255,
155,155,155,255,215,215,215,255,106,154,212,255,98,153,214,255,102,155,215,255,
100,156,215,255,96,153,214,255,99,151,208,255,173,173,173,255,94,94,94,255,169,
169,169,255,146,146,146,255,95,95,95,255,124,124,124,255,59,59,59,255,101,101,
101,255,148,148,148,255,208,208,208,255,94,151,214,255,102,157,217,255,106,159,
217,255,105,158,217,255,101,155,216,255,95,152,214,255,165,165,165,255,86,86,86,
255,163,163,163,255,139,139,139,255,87,87,87,255,117,117,117,255,57,57,57,255,
98,98,98,255,142,142,142,255,199,199,199,255,94,151,214,255,101,156,215,255,
105,158,217,255,106,160,217,255,103,157,216,255,98,154,215,255,155,155,155,255,
80,80,80,255,158,158,158,255,133,133,133,255,78,78,78,255,110,110,110,255,55,
55,55,255,96,96,96,255,135,135,135,255,185,185,185,255,100,150,208,255,97,154,
216,255,103,156,216,255,103,157,216,255,102,156,216,255,104,154,206,255,140,140,
140,255,74,74,74,255,154,154,154,255,128,128,128,255,71,71,71,255,105,105,105,
255,53,53,53,255,94,94,94,255,126,126,126,255,139,139,139,255,149,165,184,255,
100,150,206,255,96,154,214,255,99,155,215,255,104,153,206,255,131,147,163,255,
91,91,91,255,65,65,65,255,149,149,149,255,124,124,124,255,66,66,66,255,100,100,
100,255,51,51,51,255,87,87,87,255,111,111,111,255,103,103,103,255,122,122,122,
255,155,155,155,255,152,152,152,255,147,147,147,255,134,134,134,255,88,88,88,
255,64,64,64,255,100,100,100,255,144,144,144,255,116,116,116,255,97,97,97,255,
90,90,90,255,49,49,49,255,71,71,71,111,55,55,55,246,53,53,53,253,70,70,70,254,
68,68,68,255,65,65,65,255,63,63,63,255,60,60,60,255,52,52,52,254,45,45,45,253,
44,44,44,253,43,43,43,253,43,43,43,253,43,43,43,253,42,42,42,253,42,42,42,182,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0};
static Fl_RGB_Image image_camera(idata_camera, 16, 16, 4, 0);

void Fldtk_Main_Window::cb_Err_i(Fl_Input* o, void*) {
  NewtAlert(atoi(o->value()));
}
void Fldtk_Main_Window::cb_Err(Fl_Input* o, void* v) {
  ((Fldtk_Main_Window*)(o->parent()->parent()))->cb_Err_i(o,v);
}

Fl_Menu_Item Fldtk_Main_Window::menu_1[] = {
 {"newtApplication", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Menu_Item Fldtk_Main_Window::menu_2[] = {
 {"No Custom Protos", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};
Fldtk_Main_Window::Fldtk_Main_Window(int X, int Y, int W, int H, const char *L)
  : Fl_Double_Window(X, Y, W, H, L) {
  _Fldtk_Main_Window();
}

Fldtk_Main_Window::Fldtk_Main_Window(int W, int H, const char *L)
  : Fl_Double_Window(0, 0, W, H, L) {
  clear_flag(16);
  _Fldtk_Main_Window();
}

void Fldtk_Main_Window::_Fldtk_Main_Window() {
this->box(FL_FLAT_BOX);
this->color(FL_BACKGROUND_COLOR);
this->selection_color(FL_BACKGROUND_COLOR);
this->labeltype(FL_NO_LABEL);
this->labelfont(0);
this->labelsize(14);
this->labelcolor(FL_FOREGROUND_COLOR);
this->align(FL_ALIGN_TOP);
this->when(FL_WHEN_RELEASE);
{ Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 785, 25);
  o->box(FL_THIN_UP_BOX);
  o->menu(menu_);
} // Fl_Menu_Bar* o
{ Fl_Group* o = new Fl_Group(0, 25, 785, 35);
  o->box(FL_THIN_DOWN_BOX);
  { Fl_Button* o = new Fl_Button(10, 30, 25, 25, "@filenew");
    o->tooltip("New Layout");
    o->labelsize(11);
    o->labelcolor(FL_GRAY0);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(35, 30, 25, 25, "@filenew");
    o->tooltip("New Proto Template");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(60, 30, 25, 25, "@filenew");
    o->tooltip("New Text File");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(90, 30, 25, 25, "@fileopen");
    o->tooltip("Open");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(115, 30, 25, 25, "@filesave");
    o->tooltip("Save");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(140, 30, 25, 25, "@filesave");
    o->tooltip("Save all open files");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(170, 30, 25, 25, "@undo");
    o->tooltip("Undo");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(195, 30, 25, 25, "@redo");
    o->tooltip("Redo");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(225, 30, 25, 25, "Cut");
    o->tooltip("Cut");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(250, 30, 25, 25, "Copy");
    o->tooltip("Copy");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(275, 30, 25, 25, "Paste");
    o->tooltip("Paste");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(305, 30, 25, 25, "@fileprint");
    o->tooltip("Print");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(335, 30, 25, 25, "@search");
    o->tooltip("Find");
    o->labelsize(11);
    o->deactivate();
  } // Fl_Button* o
  { tSnapshot = new Fl_Button(365, 30, 25, 25);
    tSnapshot->tooltip("Newt Screen Shot");
    tSnapshot->image(image_camera);
    tSnapshot->labelsize(9);
    tSnapshot->callback((Fl_Callback*)cb_tSnapshot);
  } // Fl_Button* tSnapshot
  { Fl_Button* o = new Fl_Button(395, 30, 25, 25, "Bld");
    o->tooltip("Build Package");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(420, 30, 25, 25, "Dnl");
    o->tooltip("Download Package");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(450, 30, 25, 25, "Lyt");
    o->tooltip("Open Layout");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(475, 30, 25, 25, "Brsr");
    o->tooltip("Create New Browser");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(505, 30, 25, 25, "?");
    o->tooltip("Help Index");
    o->labelfont(1);
    o->labelsize(13);
    o->deactivate();
  } // Fl_Button* o
  { Fldtk_Layout_Drop_Box* o = new Fldtk_Layout_Drop_Box(545, 30, 25, 25, ".lyt");
    o->tooltip("Layout Drop Box");
    o->box(FL_UP_BOX);
    o->color(FL_BACKGROUND_COLOR);
    o->selection_color(FL_BACKGROUND_COLOR);
    o->labeltype(FL_NORMAL_LABEL);
    o->labelfont(0);
    o->labelsize(11);
    o->labelcolor(FL_FOREGROUND_COLOR);
    o->align(FL_ALIGN_CENTER);
    o->when(FL_WHEN_RELEASE);
  } // Fldtk_Layout_Drop_Box* o
  { Fl_Input* o = new Fl_Input(595, 31, 45, 23, "Err");
    o->type(2);
    o->labelsize(11);
    o->textsize(12);
    o->callback((Fl_Callback*)cb_Err);
  } // Fl_Input* o
  { Fl_Box* o = new Fl_Box(760, 30, 15, 25);
    o->deactivate();
    Fl_Group::current()->resizable(o);
  } // Fl_Box* o
  o->end();
} // Fl_Group* o
{ Fl_Group* o = new Fl_Group(0, 60, 785, 35);
  o->box(FL_THIN_DOWN_BOX);
  { Fl_Button* o = new Fl_Button(10, 65, 25, 25, "Left");
    o->tooltip("Align Left");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(35, 65, 25, 25, "Right");
    o->tooltip("Align Right");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(60, 65, 25, 25, "Top");
    o->tooltip("Align Top");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(85, 65, 25, 25, "Bot");
    o->tooltip("Align Bottom");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(110, 65, 25, 25, "V.Ctr");
    o->tooltip("Align Vertical Center");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(135, 65, 25, 25, "H.Ctr");
    o->tooltip("CreaAlign Horizontal Center");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(165, 65, 25, 25, "Mode");
    o->tooltip("Select Mode");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(195, 65, 25, 25, "@-2plus");
    o->tooltip("Create Proto");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Button* o = new Fl_Button(405, 65, 25, 25, "@-2plus C");
    o->tooltip("Create Proto");
    o->labelsize(9);
    o->deactivate();
  } // Fl_Button* o
  { Fl_Choice* o = new Fl_Choice(225, 66, 175, 23);
    o->down_box(FL_BORDER_BOX);
    o->labelsize(11);
    o->textsize(11);
    o->deactivate();
    o->menu(menu_1);
  } // Fl_Choice* o
  { Fl_Choice* o = new Fl_Choice(435, 66, 175, 23);
    o->down_box(FL_BORDER_BOX);
    o->labelsize(11);
    o->textsize(11);
    o->deactivate();
    o->menu(menu_2);
  } // Fl_Choice* o
  { Fl_Box* o = new Fl_Box(615, 65, 15, 25);
    o->deactivate();
    Fl_Group::current()->resizable(o);
  } // Fl_Box* o
  o->end();
} // Fl_Group* o
{ center = new Fl_Tile(0, 95, 785, 475);
  center->box(FL_FLAT_BOX);
  center->labelsize(12);
  { Fl_Group* o = new Fl_Group(0, 95, 150, 305);
    o->box(FL_FLAT_BOX);
    { browsers = new Fl_Tabs(3, 98, 144, 299);
      browsers->box(FL_UP_BOX);
      browsers->labelsize(12);
      { documents = new Fldtk_Document_Browser(3, 118, 144, 279, "Files");
        documents->box(FL_NO_BOX);
        documents->color(FL_BACKGROUND2_COLOR);
        documents->selection_color(FL_SELECTION_COLOR);
        documents->labeltype(FL_NORMAL_LABEL);
        documents->labelfont(0);
        documents->labelsize(12);
        documents->labelcolor(FL_FOREGROUND_COLOR);
        documents->textsize(12);
        documents->align(FL_ALIGN_BOTTOM);
        documents->when(FL_WHEN_RELEASE_ALWAYS);
        documents->deactivate();
        Fl_Group::current()->resizable(documents);
      } // Fldtk_Document_Browser* documents
      browsers->end();
      Fl_Group::current()->resizable(browsers);
    } // Fl_Tabs* browsers
    o->end();
  } // Fl_Group* o
  { Fl_Group* o = new Fl_Group(150, 95, 635, 305);
    o->box(FL_FLAT_BOX);
    { document_tabs = new Fldtk_Document_Tabs(153, 98, 629, 299);
      document_tabs->box(FL_UP_BOX);
      document_tabs->color(FL_BACKGROUND_COLOR);
      document_tabs->selection_color(FL_BACKGROUND_COLOR);
      document_tabs->labeltype(FL_NORMAL_LABEL);
      document_tabs->labelfont(0);
      document_tabs->labelsize(12);
      document_tabs->labelcolor(FL_FOREGROUND_COLOR);
      document_tabs->align(FL_ALIGN_TOP);
      document_tabs->when(FL_WHEN_RELEASE);
      document_tabs->end();
      Fl_Group::current()->resizable(document_tabs);
    } // Fldtk_Document_Tabs* document_tabs
    o->end();
  } // Fl_Group* o
  { Fl_Group* o = new Fl_Group(0, 400, 785, 170);
    o->box(FL_FLAT_BOX);
    { consoles = new Fl_Tabs(3, 403, 779, 164);
      consoles->box(FL_UP_BOX);
      consoles->labelsize(12);
      { Fl_Group* o = new Fl_Group(3, 423, 779, 144, "Inspector");
        o->labelsize(12);
        { inspector = new Fldtk_Inspector(5, 425, 775, 139);
          inspector->box(FL_NO_BOX);
          inspector->color(FL_BACKGROUND_COLOR);
          inspector->selection_color(FL_BACKGROUND_COLOR);
          inspector->labeltype(FL_NORMAL_LABEL);
          inspector->labelfont(0);
          inspector->labelsize(12);
          inspector->labelcolor(FL_FOREGROUND_COLOR);
          inspector->align(FL_ALIGN_TOP);
          inspector->when(FL_WHEN_RELEASE);
          inspector->end();
          Fl_Group::current()->resizable(inspector);
        } // Fldtk_Inspector* inspector
        o->end();
        Fl_Group::current()->resizable(o);
      } // Fl_Group* o
      consoles->end();
      Fl_Group::current()->resizable(consoles);
    } // Fl_Tabs* consoles
    o->end();
  } // Fl_Group* o
  { Fl_Box* o = new Fl_Box(150, 95, 635, 305);
    o->hide();
    o->deactivate();
    Fl_Group::current()->resizable(o);
  } // Fl_Box* o
  center->end();
  Fl_Group::current()->resizable(center);
} // Fl_Tile* center
{ Fl_Group* o = new Fl_Group(0, 570, 785, 25, "For Help, press F1");
  o->box(FL_THIN_UP_BOX);
  o->labelsize(11);
  o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
  { Fl_Group* o = new Fl_Group(605, 570, 165, 25);
    { Fl_Box* o = new Fl_Box(620, 573, 40, 19, "CAPS");
      o->box(FL_DOWN_BOX);
      o->labelsize(11);
      o->labelcolor(FL_LIGHT1);
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(665, 573, 40, 19, "NUM");
      o->box(FL_DOWN_BOX);
      o->labelsize(11);
      o->labelcolor(FL_LIGHT1);
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(710, 573, 40, 19, "SCRL");
      o->box(FL_DOWN_BOX);
      o->labelsize(11);
      o->labelcolor(FL_LIGHT1);
    } // Fl_Box* o
    o->end();
  } // Fl_Group* o
  { Fl_Box* o = new Fl_Box(590, 570, 15, 25);
    Fl_Group::current()->resizable(o);
  } // Fl_Box* o
  o->end();
} // Fl_Group* o
end();
}

void Fldtk_Main_Window::activate_menus(unsigned int mask) {
  // bits in the mask have the following meanings:
//	bit 0: a project is loaded
//	bit 1: a document is active for editing
//	bit 2: the active document is part of the project

// mFileNewTex is always active
// mFileOpen is always active
// mFileExit is always active

// mEditPreferences is always active

// mProjectNew is always active
// mProjectOpen is always active

if ( (mask & 0x00000001) == 0x00000001 ) {
  mProjectSave->activate();
  mProjectSaveAs->activate();
  mProjectAddFile->activate();
  mProjectBuild->activate();
  mProjectDownload->activate(); // could depend on existing pkg
  mProjectLaunch->activate(); // could depend on downloaded pkg
  mProjectSettings->activate();
} else {
  mProjectSave->deactivate();
  mProjectSaveAs->deactivate();
  mProjectAddFile->deactivate();
  mProjectBuild->deactivate();
  mProjectDownload->deactivate(); // could depend on existing pkg
  mProjectLaunch->deactivate(); // could depend on downloaded pkg
  mProjectSettings->deactivate();
}

if ( (mask & 0x00000002) == 0x00000002 ) {
  mFileClose->activate();
  mFileSave->activate();
  mFileSaveAs->activate();
} else {
  mFileClose->deactivate();
  mFileSave->deactivate();
  mFileSaveAs->deactivate();
}

if ( (mask & 0x00000007) == 0x00000007 ) {
  mProjectRemoveFile->activate();
} else {
  mProjectRemoveFile->deactivate();
}

if ( (mask & 0x00000007) == 0x00000003 ) {
  mProjectAddWindow->activate();
} else {
  mProjectAddWindow->deactivate();
}
}

static void cb_Cancel(Fl_Button*, void*) {
  InspectorCancelConnect();
}

Fl_Double_Window* create_connect_dialog() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(225, 116, "Progress");
    w = o;
    { Fl_Box* o = new Fl_Box(15, 8, 195, 65, "Tap the Toolkit icon on the Newton device, select \"Connect via Serial\", and\
 tap Connect Inspector.");
      o->labelsize(12);
      o->align(FL_ALIGN_WRAP);
    } // Fl_Box* o
    { Fl_Button* o = new Fl_Button(72, 81, 80, 20, "Cancel");
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_Cancel);
      o->window()->hotspot(o);
    } // Fl_Button* o
    o->set_modal();
    o->end();
  } // Fl_Double_Window* o
  return w;
}

//
// Copyright (C) 2007 Matthias Melcher
//
