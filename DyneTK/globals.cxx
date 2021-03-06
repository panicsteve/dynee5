//
// "$Id$"
//
// DyneTK global functions implementation file
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
// Please report all bugs and problems to "dyne@matthiasm.com".
//

#include "main.h"

#include <FL/x.H>
#include <FL/Fl.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/fl_file_chooser.h>

#include "fluid/Fldtk_Prefs.h"
#include "fluid/Fldtk_Proj_Settings.h"
#include "fluid/Fldtk_Snapshot.h"
#include "fluid/Fldtk_Dialogs.h"
#include "fluid/main_ui.h"

#include "dtk/Dtk_Document_List.h"
#include "dtk/Dtk_Document.h"
#include "dtk/Dtk_Layout.h"
#include "dtk/Dtk_Project.h"
#include "dtk/Dtk_Error.h"
#include "dtk/Dtk_Script_Writer.h"
#include "dtk/Dtk_Template.h"
#include "dtk/Dtk_Template_List.h"
#include "dtk/Dtk_Slot.h"


#include "fltk/Flmm_Message.H"
#include "fltk/Flio_Serial_Port.h"
#include "fltk/Fldtk_Editor.h"
#include "fltk/Fldtk_Layout_View.h"
#include "fltk/Fldtk_Slot_Editor_Group.h"
#include "fltk/Fldtk_Slot_Browser.h"
#include "fltk/Fldtk_Tmpl_Browser.h"
#include "fltk/Flio_Inspector_Einstein.h"

#include "globals.h"
#include "allNewt.h"

#include <assert.h>

#ifndef WIN32
# define Sleep(a) sleep((a)/1000)
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#else
# include <winsock2.h>
# include <io.h>
# include <fcntl.h>
#endif

extern Fl_Window *wConnect;

/*-v2------------------------------------------------------------------------*/
int NewLayoutFile(const char *filename) {
  char buffer[2048];
  // create a filename if we have none
  if (!filename) {
    if (dtkProject)
      strcpy(buffer, dtkProject->posix_pathname());
    strcat(buffer, "layout.lyt");
    fl_filename_absolute(buffer, 2047, buffer);
    filename = buffer;
    /// \todo Make sure we choose a unique name here
    /// \todo Add the current path to the filename
    /// \todo Make sure that no file with that path and name exists
  }
  // add the new document to the global docs list
	Dtk_Document *doc = dtkGlobalDocuments->newLayout(filename);
	doc->edit();
  // keep the menubar in sync
	UpdateMainMenu();
	return 0;
}


/*-v2------------------------------------------------------------------------*/
int NewTextFile(const char *filename) {
  char buffer[2048];
  // create a filename if we have none
  if (!filename) {
    if (dtkProject)
      strcpy(buffer, dtkProject->posix_pathname());
    strcat(buffer, "script.txt");
    fl_filename_absolute(buffer, 2047, buffer);
    filename = buffer;
    /// \todo Make sure we choose a unique name here
    /// \todo Add the current path to the filename
    /// \todo Make sure that no file with that path and name exists
  }
  // add the new document to the global docs list
	Dtk_Document *doc = dtkGlobalDocuments->newScript(filename);
	doc->edit();
  // keep the menubar in sync
	UpdateMainMenu();
	return 0;
}


/*-v2------------------------------------------------------------------------*/
int CloseCurrentDocument()
{
  // find the right document
  Dtk_Document *doc = GetCurrentDocument();
  if (!doc)
    return -1;
  // if the document is dirty, we must ask the user before closing
  if (doc->isDirty()) {
    int v = fl_choice(
                      "Save changes to document %s?", 
                      "Abort", "Yes", "No", doc->name());
    switch (v) {
      case 0: // abort
        return -2; 
      case 1: // yes
        doc->save(); break; 
      case 2:  // no
        break;
    }
  }
  // If we are part of a project, only close the editor, else discard the doc.
  if (doc->project()) {
    doc->close();
  } else {
    delete doc;
  }
  // correct menus
  UpdateMainMenu();
  return 0;
}


/*-v2------------------------------------------------------------------------*/
int OpenDocument(const char *filename)
{
	int ret = -1;
  // if there is no file name, pop up a file dialog
  const char *path = 0L;
  if (dtkProject)
    path = dtkProject->posix_pathname();
	if (!filename) {
		filename = fl_file_chooser("Open Document...",
                               "All Files(*)\t"
                               "Layout Files (*.lyt)\tTest Files (*.txt)\tBitmap Files (*.bmp)\t"
                               "Sound Files (*.wav)\tPackage Files (*.pkg)\tBook Files (*.lyt)\t"
                               "Native Module Files (*.ntm)\tStream Files (*.stm)", path);
		if (!filename)
			return -2;
	}
  // go ahead and add the document
  Dtk_Document *doc = dtkGlobalDocuments->add(filename);
  // update the menu bar
	UpdateMainMenu();
  // show an error message if needed
  if (!doc) {
    SystemAlert("Can't open document");
    return -1;
  }
	return ret;
}


/*-v2------------------------------------------------------------------------*/
int SaveCurrentDocument()
{
	int ret = -1;
  // find the current document and save it
	Dtk_Document *doc = GetCurrentDocument();
	if (doc)
		ret = doc->save();
	else 
		ret = -1;
  // activate the correct menus
	UpdateMainMenu();
	return ret;
}


/*-v2------------------------------------------------------------------------*/
int SaveCurrentDocumentAs()
{
	int ret = -1;
  // find the current document and save it
	Dtk_Document *doc = GetCurrentDocument();
	if (doc)
		ret = doc->saveAs();
	else 
		ret = -1;
  // activate the correct menus
	UpdateMainMenu();
	return ret;
}


/*-v2------------------------------------------------------------------------*/
int OpenProject(const char *filename) 
{
  // close any dirty project first
  if (dtkProject && dtkProject->isDirty()) {
    CloseProject();
    // abort if the user decided to not close the project
    if (dtkProject) {
      return -2;
    }
  }
  // open a file chooser if there was no filename given
	if (!filename) {
		filename = fl_file_chooser("Open Toolkit Project", "*.ntk", 0L);
		if (!filename) 
			return -2;
	}
  // now close the existing project, which can not be dirty
	if (dtkProject) {
    CloseProject();
	}
  // create a new project and load it
	dtkProject = new Dtk_Project();
	dtkProject->setFilename(filename);
	int ret = dtkProject->load();
  
	UpdateMainMenu();
	return ret;
}

/*-v2------------------------------------------------------------------------*/
int OpenPreviousProject(const char *filename)
{
  // '<' indicates an adminstrative menu entry like <empty> or <NULL>
  // which we must not load. Pop up a file chooser instead.
  if (filename && filename[0]=='<')
    return OpenProject(0L);
  else
    return OpenProject(filename);
}

/*-v2------------------------------------------------------------------------*/
int SaveAllDocuments()
{
	if (dtkProject) {
    return dtkProject->saveAll();
	}
  return 0;
}

/*-v2------------------------------------------------------------------------*/
int NewProject(const char *filename) 
{
  // give a starting point for creating new projects
  char path[2048]; path[0] = 0;
  if (dtkProject && dtkProject->posix_pathname())
    strcpy(path, dtkProject->posix_pathname());
  // close any dirty project first (clean projects are close later)
  if (dtkProject && dtkProject->isDirty()) {
    CloseProject();
    // abort if the user decided to not close the project
    if (dtkProject) {
      return -2;
    }
  }
  // ask for a new filename where we will save this project, if none was given
  char buf[2048];
	if (!filename) {
		filename = fl_file_chooser("New Toolkit Project", "*.ntk", path);
		if (!filename) 
			return 0;
    const char *ext = fl_filename_ext(filename);
    if (ext==0L || *ext==0) {
      strcpy(buf, filename);
      fl_filename_setext(buf, 2047, ".ntk");
      filename = buf;
    }
	}
  // confirm that we want to overwrite this project file if it exists already
  if (access(filename, 0004)==0) { // R_OK
    int v = fl_choice(
                      "A file with that filename already exist. Creating "
                      "a new project will eventually delete the original file.\n\n"
                      "Do you want to delete the file\n%s?", 
                      "overwrite old project", "cancel new project", 0L, filename);
    if (v==1)
      return -1;
  }
  // if there is still a (non-dirty) project, close it now
  if (dtkProject)
    CloseProject();
  // finally we can create a brand new project 
	dtkProject = new Dtk_Project();
  dtkProject->setFilename(filename);
  dtkProject->setDefaults();
  // make sure the menus show the right settings
	UpdateMainMenu();
	return 0;
}


/*-v2------------------------------------------------------------------------*/
int CloseProject()
{
  // avoid failure
	if (!dtkProject)
		return -1;
  // confirm command if project is dirty
  if (dtkProject->isDirty()) {
    int v = fl_choice(
                      "Save changes to project %s?", 
                      "Abort", "Yes", "No", dtkProject->name());
    switch (v) {
      case 0: // abort
        return -2; 
      case 1: // yes
        dtkProject->saveAll(); break; 
      case 2:  // no
        break;
    }
  }
  // now close the project and remove all references
  dtkProject->close();
	delete dtkProject;
	dtkProject = 0L;
	UpdateMainMenu();
  return 0;
}


/*-v2------------------------------------------------------------------------*/
void ShowProjectSettings()
{
  if (!dtkProject)
    return;
	dtkProjSettings->updateDialog();
	dtkProjSettings->show();
}


/*-v2------------------------------------------------------------------------*/
int AddFileToProject(const char *filename)
{
  if (!dtkProject)
    return -1;
  // if there is no file name, pop up a file dialog
	if (!filename) {
		filename = fl_file_chooser("Open Document...",
                               "All Files(*)\t"
                               "Layout Files (*.lyt)\tTest Files (*.txt)\tBitmap Files (*.bmp)\t"
                               "Sound Files (*.wav)\tPackage Files (*.pkg)\tBook Files (*.lyt)\t"
                               "Native Module Files (*.ntm)\tStream Files (*.stm)", dtkProject->posix_pathname());
		if (!filename)
			return -2;
	}
  // go ahead and add the document to the project
  Dtk_Document *doc = dtkProject->documentList()->add(filename);
  // if this is a layout and there is no main layout yet, use this one
  if (doc->isLayout() && !dtkProject->documentList()->getMainDocument()) {
    dtkProject->documentList()->setMainDocument(doc);
  }
  // update the menu bar
	UpdateMainMenu();
  // show an error message if needed
  if (!doc) {
    SystemAlert("Can't open document");
    return -1;
  }
	return 0;
}

/*-v2------------------------------------------------------------------------*/
int AddCurrentDocToProject()
{
  if (!dtkProject) {
    fl_alert("Can't add document. No project open.");
    return -1;
  }
  // which document are we talking about?
  Dtk_Document *doc = GetCurrentDocument();
  if (!doc) {
    fl_alert("Can't add document. No document selected.");
    return -1;
  }
  // if it is already in the project, don't bother
  if (doc->project()) {
    fl_alert("This document is already part of the project.");
    return 0;
  }
  // save the project to disk first, possibly renaming it
  int ret = doc->save();
  if (ret!=0)
    return -1;
  // remove from globals and reattach to the project
  dtkGlobalDocuments->remove(doc);
  dtkProject->documentList()->append(doc);
  // if this is a layout and there is no main layout yet, use this one
  if (doc->isLayout() && !dtkProject->documentList()->getMainDocument()) {
    dtkProject->documentList()->setMainDocument(doc);
  }
  // update the menus
	UpdateMainMenu();
	return 0;
}


/*-v2------------------------------------------------------------------------*/
int	RemoveFileFromProject(Dtk_Document *doc)
{
  // use the current document if there is none specified
  if (!doc) {
    doc = GetCurrentDocument();
    if (!doc) 
      return -1;
  }
  // see if it is part of a project
  if (!doc->project())
    return -1;
  // if the document is dirty, we must ask the user before deleting
  if (doc->isDirty()) {
    int v = fl_choice(
                      "Save changes to document %s?", 
                      "Abort", "Yes", "No", doc->name());
    switch (v) {
      case 0: // abort
        return -2; 
      case 1: // yes
        doc->save(); break; 
      case 2:  // no
        break;
    }
  }
  // Now we can delete the document. It will unhook itself from lists and the GUI
  delete doc;
  return 0;
}


/*-v2------------------------------------------------------------------------*/
int SaveProject()
{
  if (!dtkProject)
    return -1;
  // save it
	int ret = dtkProject->save();
  if (ret!=0)
    SystemAlert("Unable to save project file!");
  // keep the menus cool
	UpdateMainMenu();
	return ret;
}


/*-v2------------------------------------------------------------------------*/
int SaveProjectAs()
{
  if (!dtkProject)
    return -1;
  // get the filename form the user
  char buf[2048];
	const char *filename = fl_file_chooser("Save Toolkit Project", "*.ntk", dtkProject->filename());
	if (!filename) 
		return -2;
  const char *ext = fl_filename_ext(filename);
  if (ext==0L || *ext==0) {
    strcpy(buf, filename);
    fl_filename_setext(buf, 2047, ".ntk");
    filename = buf;
  }
  // save it
	dtkProject->setFilename(filename);
	int ret = dtkProject->save();
  if (ret!=0)
    SystemAlert("Unable to save project file!");
  // keep the menus cool
	UpdateMainMenu();
	return ret;
}


/*-v2------------------------------------------------------------------------*/
int BuildPackage()
{
  if (!dtkProject)
    return -1;
  SaveAllDocuments();
	int err = dtkProject->buildPackage();
	if (!err) {
		err = dtkProject->savePackage();
	}
	UpdateMainMenu();
	return err;
}


/*---------------------------------------------------------------------------*/
void DebugTestScripting()
{
  // THE CODE BELOW FRIGGIN' *WORKS*!!!!1!!11oneone
#ifdef __APPLE__
  ComponentInstance cInst;
  cInst = OpenDefaultComponent(kOSAComponentType, kOSAGenericScriptingComponentSubtype);
  static char *txt = 
    "tell application \"Einstein\"\r"
    " do newton script \"AlarmUser(\\\"A\\\", \\\"b\\\")\"\r"
    "end tell\r";
  AEDesc script, result;
  AECreateDesc(typeChar, txt, strlen(txt), &script);
  AECreateDesc(typeChar, 0, 0, &result);
  /*OSAError err = */ OSADoScript(cInst, &script, kOSANullScript, typeChar, 0, &result);
#endif
}

/*-v2------------------------------------------------------------------------*/
int DownloadPackage()
{
  /// \todo We can control a little bit of Einstein:
  ///       Apple Script: install package /file/
  ///       Apple Script: do neton script /text/
  /*
   OSAError OSADoScript (
    ComponentInstance scriptingComponent,
    const AEDesc *sourceData,
    OSAID contextID,
    DescType desiredType,
    SInt32 modeFlags,
    AEDesc *resultingText
   );
   OSADispose(component, OSAID);
   
   - ComponentInstance a = OpenDefaultComponent('????', 0);
   - typeChar or typeUTF8Text
   - AECreateDesc(typeUTF8Text, "blabla", sizeof("blabla"), AEDesc *newDesc) AEDisposeDesc
   - contextID is some ulong: kOSANullScript
   - typeUTF8Text
   - 0
   - ptr to empty AEDesc
   
   if (gGenericComponent == NULL) {
   gGenericComponent = OpenDefaultComponent(kOSAComponentType, kOSAGenericScriptingComponentSubtype);
   
   if (gGenericComponent == NULL)
   failErr("No such component.");
   else if (gGenericComponent == (ComponentInstance) badComponentInstance)
   failErr("Bad component instance.");
   else if (gGenericComponent == (ComponentInstance) badComponentSelector)
   failErr("Bad component selector.");
   }
   
   */
  
	assert(dtkProject);
	InspectorPrintf("Sending package %s...\n", dtkProject->getPackageName());
  Fl::flush();
	int ret = InspectorSendPackage(
                                 dtkProject->getPackageName(),
                                 dtkProjSettings->app->symbol->get());
	UpdateMainMenu();
	if (ret==-1) {
 		InspectorPrintf("Failed: %s\n", Flmm_Message::system_message());
	} else {
 		InspectorPrintf("Done.\n");
  }
  Fl::flush();
	return ret;
}


/*-v2------------------------------------------------------------------------*/
int ExportPackageToText()
{
	assert(dtkProject);
  Dtk_Script_Writer sw(dtkProject);
  int ret = sw.open("testing_script_writer.txt");
  if (ret) {
    SystemAlert("Can't open file.");
    return ret;
  }
  ret = dtkProject->write(sw);
  if (ret) {
    SystemAlert("Can't write to file.");
    return ret;
  }
	return 0;
}

/*---------------------------------------------------------------------------*/
/**
 * Compile and send a script command to the Newton.
 */
int InspectorSendScript(const char *script)
{
  return wInspectorSerial->sendScript(script);
}


/*-v2------------------------------------------------------------------------*/
int LaunchPackage()
{
	InspectorPrintf("Launching package %s.\n", dtkProject->getPackageName());
  Fl::flush();
	return InspectorLaunchPackage(dtkProjSettings->app->symbol->get());
}


/*---------------------------------------------------------------------------*/
/**
 * Send any package to the Newton.
 */
int InspectorSendPackage(const char *filename, const char *symbol) 
{
	// delete the old package first if that is requested by the user
	if (dtkProjSettings->package->deleteOnDownload->get())
    wInspectorSerial->deletePackage(symbol);
  
  wInspectorSerial->sendPackage(filename);
  
	return 0;
}


/*---------------------------------------------------------------------------*/
/**
 * Launch the package with the given signature.
 */
int InspectorLaunchPackage(const char *symbol) 
{
	char buf[1024];
	sprintf(buf, "GetRoot().|%s|:Open()", symbol);
	return InspectorSendScript(buf);
}


/*---------------------------------------------------------------------------*/
/**
 * Make the Inspector wait for a connection.
 */
void InspectorConnect()
{
	if (wInspectorSerial->is_open()) {
		wInspectorSerial->close();
	} else {
    switch (dtkPrefs->packages->porttype()) {
      case 0: // serial port
        if (!wInspectorSerial->is_serial()) {
          Fl_Group *p = wInspectorSerial->parent();
          p->begin();
          Flio_Inspector *newInspector = new Flio_Inspector(
            wInspectorSerial->x(), wInspectorSerial->y(),
            wInspectorSerial->w(), wInspectorSerial->h(),
            wInspectorSerial->label());
          p->end();
          p->remove(wInspectorSerial);
          delete wInspectorSerial;
          wInspectorSerial = newInspector;
        }
        break;
      case 1: // Einstein via Apple Script
        if (!wInspectorSerial->is_einstein()) {
          Fl_Group *p = wInspectorSerial->parent();
          p->begin();
          Flio_Inspector *newInspector = new Flio_Inspector_Einstein(
            wInspectorSerial->x(), wInspectorSerial->y(),
            wInspectorSerial->w(), wInspectorSerial->h(),
            wInspectorSerial->label());
          p->end();
          p->remove(wInspectorSerial);
          delete wInspectorSerial;
          wInspectorSerial = newInspector;
        }
        break;
    }
    
		if (!wConnect) {
			wConnect = create_connect_dialog();
		}
		wConnect->show();
		wInspectorSerial->open(dtkPrefs->packages->port(), 38400);
		if (!wInspectorSerial->is_open()) {
			wInspectorSerial->close();
			if (wConnect)
				wConnect->hide();
			SystemAlert("Can't open serial port");
			return;
		}
	}
}


/*---------------------------------------------------------------------------*/
/**
 * Connection was canceled.
 */
void InspectorCancelConnect()
{
	wInspectorSerial->cancel();
	wConnect->hide();
}


/*---------------------------------------------------------------------------*/
/**
 * Quit and exit.
 * \todo	this should ask for verification if there are unsaved changes.
 */
void ExitApplication() {
	dtkMain->hide();
	while (Fl::first_window()) {
		Fl::first_window()->hide();
	}
}


/*---------------------------------------------------------------------------*/
/**
 * User wants to see the preferences dialog.
 */
void EditPreferences()
{
	dtkPrefs->show();
}

/*---------------------------------------------------------------------------*/
/**
 * Update activation and deactivation in the main menu bar.
 */
void UpdateMainMenu()
{
  // bits in the mask have the following meanings:
  //	bit 0: a project is loaded
  //	bit 1: a document is active for editing
  //	bit 2: the active document is part of the project
  //  bit 3: Inspector is connected to a Newton device
  //  bit 4: a layout is active for editing
  //  bit 5: the current layout has a visible layout view
  //  bit 6: a template is active for editing
  //  bit 7: a slot is active for editing
	unsigned int mask = 0;
	if (dtkProject)
		mask |= 1;
  Dtk_Document *doc = GetCurrentDocument();
  if (doc) {
		mask |= 2;
    if (doc->project()) {
			mask |= 4;
    }
    if (doc->isLayout()) {
      mask |= 16;
      Dtk_Layout *layout = (Dtk_Layout*)doc;
      if (layout->editViewShown())
        mask |= 32;
      if (GetCurrentTemplate()) {
        mask |= 64;
        if (GetCurrentSlot()) {
          mask |= 128;
        }
      }
    }
  }
	if (wInspectorSerial->is_open()) {
		mask |= 8;
	}
	dtkMain->activate_menus(mask);
	dtkMain->inspector->activate_menus(mask);
}

/*---------------------------------------------------------------------------*/
/**
 * Update the labels and visibility of the Previous Project menu items.
 */
void UpdatePrevProjMenu() 
{
	int i;
	for (i=0; i<8; i++) {
		if (i>=dtkPrefs->nPrevProj) {
			dtkMain->mPrevProj[i]->hide();
		} else {
			Fl_Menu_Item *mi = dtkMain->mPrevProj[i];
			mi->show();
			if (mi->label()) {
				if (mi->label()[0]!='<') // static strings start with a '<' - do not free those!
          free((void*)mi->label());
			}
      const char *path = dtkPrefs->prevProj[i];
      if (path && *path) {
        char buf[2048];
        fl_filename_relative(buf, 2047, path);
        if (buf[0]=='.' && buf[1]=='.')
          mi->label(strdup(path)); // absolute path if we must go up in the hierarchy
        else
          mi->label(strdup(buf)); // relative path if it is a simple relation
      } else {
				mi->label("<null>"); // this merely sets a pointer in case the following function fails
      }
		}
	}
  if (dtkPrefs->nPrevProj==0) {
    dtkMain->mPrevProj[0]->label("<empty>");
    dtkMain->mPrevProj[0]->show();
  }
}

/*---------------------------------------------------------------------------*/
/**
 * Add a new filename to the list of previous projects.
 */
void AddPrevProj(const char *filename)
{
  int i;
  int N = dtkPrefs->nPrevProj;
  char buf[2048];
  fl_filename_absolute(buf, 2047, filename);
  filename = buf;
  
  // don't set empty filenames
  if (!filename || !*filename)
    return;
  
  // add the filename at the top
  if (dtkPrefs->nPrevProj==0) {
    // simplified condition if no entries exist yet
    dtkPrefs->prevProj[0] = strdup(filename);
    dtkPrefs->nPrevProj = 1;
  } else {
    // does this entry exist already?
    for (i=0; i<N; i++) {
      if (strcmp(filename, dtkPrefs->prevProj[i])==0)
        break;
    }
    // if we are already at the top, there is nothing to do
    if (i==0)
      return;
    // if this is not a dup, move *all* entries around
    if (i==N) {
      if (N<8)
        dtkPrefs->nPrevProj++;
      else
        i = 7;
    }
    // now free the last entry
    if (dtkPrefs->prevProj[i])
      free(dtkPrefs->prevProj[i]);
    // move all entries above down by one
    for ( ; i>0; --i) 
      dtkPrefs->prevProj[i] = dtkPrefs->prevProj[i-1];
    // and set the new filename at the top
    dtkPrefs->prevProj[0] = strdup(filename);
  }
	UpdatePrevProjMenu();
}

/*---------------------------------------------------------------------------*/
/**
 * Toggle the 'breakOnThrows' flag on and off.
 * \todo should be a toggle
 */
void InspectorStopOnThrows(bool stop)
{
  if (stop)
    InspectorSendScript("breakOnThrows := 1"); // TRUE or NIL
  else
    InspectorSendScript("breakOnThrows := 0"); // TRUE or NIL
}

/*---------------------------------------------------------------------------*/
/**
 * Set the 'trace' flag to "off".
 */
void InspectorTrace(bool trace)
{
  // Later comment: I don't know what the coment below means ;-)
	// user may have set it to 'functions or true
  if (trace)
	  InspectorSendScript("trace := true");
  else
	  InspectorSendScript("trace := nil");
}

/*---------------------------------------------------------------------------*/
/**
 * Print the contents of the stack.
 */
void InspectorStackTrace()
{
	InspectorSendScript("StackTrace()");
}

/*---------------------------------------------------------------------------*/
/**
 * Leave this level in the break loop.
 * \todo How can we know how deep we are in the break loop?
 */
void InspectorExitBreakLoop()
{
	InspectorSendScript("ExitBreakLoop()");
}

/*---------------------------------------------------------------------------*/
/**
 * Change the depth for printing all kinds of frames.
 * nil shows all levels
 */
void InspectorPrintDepth(int d)
{
	char buf[80];
	sprintf(buf, "printDepth := %d", d);
	InspectorSendScript(buf);
}

/*---------------------------------------------------------------------------*/
/**
 * Take a snapshot from the current screen content and send it to the Inspector.
 */
void InspectorSnapshot()
{
	InspectorSendScript("|Screenshot:ntk|()");
	show_snapshot_window();
}

/*---------------------------------------------------------------------------*/
/**
 * Show a dialog box with the text for the given NewtonOS error code.
 */
void NewtAlert(int err)
{
	newt_alert(err);
}

/*---------------------------------------------------------------------------*/
/**
 * Show a dialog box with the text for the given operrating system error code.
 */
void SystemAlert(const char *msg, int err)
{
	Flmm_Message::alert("%s\n\n%s", msg, Flmm_Message::system_message(err));
}

/*---------------------------------------------------------------------------*/
/**
 * Convert the Newt Frame into an Fl_Image and update the snapshot dialog.
 */
void InspectorSnapshotUpdate(newtRef snapshot) 
{
	if (NewtRefIsFrame(snapshot)) {
		newtRef data = NewtGetFrameSlot(snapshot, NewtFindSlotIndex(snapshot, NSSYM(data)));
		if (NewtRefIsFrame(data)) {
      
      // get the dimensions and data
      newtRef nRowbytes = NewtGetFrameSlot(data, NewtFindSlotIndex(data, NSSYM(rowbytes)));
      newtRef nTop      = NewtGetFrameSlot(data, NewtFindSlotIndex(data, NSSYM(top)));
      newtRef nLeft     = NewtGetFrameSlot(data, NewtFindSlotIndex(data, NSSYM(left)));
      newtRef nBottom   = NewtGetFrameSlot(data, NewtFindSlotIndex(data, NSSYM(bottom)));
      newtRef nRight    = NewtGetFrameSlot(data, NewtFindSlotIndex(data, NSSYM(right)));
      newtRef nDepth    = NewtGetFrameSlot(data, NewtFindSlotIndex(data, NSSYM(depth)));
      newtRef nTheBits  = NewtGetFrameSlot(data, NewtFindSlotIndex(data, NSSYM(theBits)));
      int rowbytes = NewtRefToInteger(nRowbytes);
      int top      = NewtRefToInteger(nTop);
      int left     = NewtRefToInteger(nLeft);
      int bottom   = NewtRefToInteger(nBottom);
      int right    = NewtRefToInteger(nRight);
      int depth    = NewtRefToInteger(nDepth);
      unsigned char *theBits = (unsigned char*)NewtRefToData(nTheBits);
      
      if (depth!=4) {
        printf("Unsupported pixel depth of %d bits\n", depth);
        return;
      }
      // convert this to RGB (ah well)
      int wdt = right - left, hgt = bottom - top, x, y;
      unsigned char *dst = new unsigned char[wdt*hgt*3], *imgData = dst;
      for (y=0; y<hgt; y++) {
        unsigned char *src = theBits + y*rowbytes;
        for (x=0; x<wdt; x+=2) {
          unsigned char pxl, d = *src++;
          pxl = ((d&0xf0)|(d>>4))^0xff; *dst++ = pxl; *dst++ = pxl; *dst++ = pxl;
          pxl = ((d<<4)|(d&0x0f))^0xff; *dst++ = pxl; *dst++ = pxl; *dst++ = pxl;
        }
      }
      Flmp_Image *img = (Flmp_Image*)new Fl_RGB_Image(imgData, wdt, hgt, 3);
      img->alloc_array = 1;
      update_snapshot_window(img);
      //free(imgData);
		}
	}
}

extern void testPkgReader(const char *filename);
void DebugDumpPackage() {
	NcSetGlobalVar(NSSYM(printLength), NSINT(100));
	NcSetGlobalVar(NSSYM(printDepth), NSINT(20));
	NEWT_INDENT = 1;
	NEWT_DUMPBC = 1;
	testPkgReader(0);
}

extern void testNSOFReader(const char *filename);
void DebugDumpNSOF() {
	testNSOFReader(0);
}

void DebugDumpRsrc() {
  const char *filename = fl_file_chooser("Read a resource fork", 0, 0);
  if (!filename)
    return;
  char buf[1024];
  sprintf(buf, "%s/rsrc", filename);
  int fd = open(buf, O_RDONLY /*| O_NO_MFS*/, 0);
  if (fd==-1) {
    SystemAlert("Can't open resource fork");
  }
  for (;;) {
    unsigned char c;
    int n = read(fd, &c, 1);
    if (n!=1) break;
    printf("%02x ", c);
  }
  close(fd);
}

void DebugDumpBuffer(uint8_t *src, int n)
{
  int i, j;
  for (i=0; i<n; i+=16) {
    char buf[78];
    memset(buf, 32, 78); buf[76] = ' '; buf[77] = 0;
    sprintf(buf, "%08x", i); buf[8] = ' ';
    for (j=i; (j<i+16) && (j<n); j++) {
      uint8_t c = src[j];
      sprintf(buf+10+3*(j-i), "%02x", c); buf[12+3*(j-i)] = ' ';
      if (isprint(c))
        buf[59+j-i] = c;
      else
        buf[59+j-i] = '.';
    }
    puts(buf);
  }
}

/*---------------------------------------------------------------------------*/
Dtk_Document *GetCurrentDocument()
{
  Fldtk_Editor *ed = (Fldtk_Editor*)dtkDocumentTabs->value();
  if (!ed) 
    return 0L;
  return ed->document();
}


/*---------------------------------------------------------------------------*/
Dtk_Layout *GetCurrentLayout()
{
  Dtk_Document *doc = GetCurrentDocument();
  if (doc && doc->isLayout())
    return (Dtk_Layout*)doc;
  return 0L;
}


/*---------------------------------------------------------------------------*/
Dtk_Template *GetCurrentTemplate()
{
  Dtk_Layout *lyt = GetCurrentLayout();
  if (!lyt)
    return 0L;
  Fldtk_Tmpl_Browser *te = lyt->templateBrowser();
  int ix = te->value();
  if (!ix) 
    return 0L;
  Dtk_Template *tmpl = (Dtk_Template*)te->data(ix);
  return tmpl;
}


/*---------------------------------------------------------------------------*/
Dtk_Slot *GetCurrentSlot()
{
  Dtk_Layout *lyt = GetCurrentLayout();
  if (!lyt)
    return 0L;
  Fldtk_Slot_Browser *se = lyt->slotBrowser();
  int ix = se->value();
  if (!ix) 
    return 0L;
  Dtk_Slot *slot = (Dtk_Slot*)se->data(ix);
  return slot;
}


/*---------------------------------------------------------------------------*/
void DeleteSlot(Dtk_Slot *slot) 
{
  if (!slot) {
    slot = GetCurrentSlot();
    if (!slot)
      return;
  }
  Dtk_Template *tmpl = slot->getTemplate();
  if (tmpl) {
    tmpl->removeSlot(slot);
  }
  delete slot;
}


/*---------------------------------------------------------------------------*/
void DeleteTemplate(Dtk_Template *tmpl) 
{
  if (!tmpl) {
    tmpl = GetCurrentTemplate();
    if (!tmpl)
      return;
  }
  Dtk_Template_List *list = tmpl->list();
  Dtk_Layout *layout = tmpl->layout();
  if (list) {
    list->remove(tmpl);
    delete tmpl;
  } else if (layout) {
    layout->removeTemplates();
    delete tmpl;
  }
}

/*---------------------------------------------------------------------------*/
int OpenLayoutView(Dtk_Layout *lyt)
{
  if (!lyt) {
    lyt = GetCurrentLayout();
    if (!lyt)
      return -1;
  }
  lyt->editView();
  return 0;
}

/*---------------------------------------------------------------------------*/
int SetMainLayout(Dtk_Document *doc)
{
  if (!doc) {
    doc = GetCurrentDocument();
    if (!doc) 
      return -1;
  }
  if (!doc->project())
    return -2;
  doc->setMain();
  return 0;
}

/*---------------------------------------------------------------------------*/
void SetModeEditTemplate()
{
  Fldtk_Layout_View::mode(0);
  UpdateMainMenu();
}

/*---------------------------------------------------------------------------*/
void SetModeAddTemplate()
{
  Fldtk_Layout_View::mode(1);
  UpdateMainMenu();
}

/*---------------------------------------------------------------------------*/
int ShowTemplateInfo(Dtk_Template *tmpl)
{
  if (!tmpl) {
    tmpl = GetCurrentTemplate();
    if (!tmpl)
      return -1;
  }
  if (!dtkDeclareToDialog) {
    Fl_Group::current(0L);
    dtkDeclareToDialog = new Fldtk_Declare_To_Dialog(300, 122, "Template Info");
  }
  dtkDeclareToDialog->setTemplate(tmpl);
  dtkDeclareToDialog->show();
  return 0;
}

/*---------------------------------------------------------------------------*/
void NewSlot(Dtk_Template *tmpl)
{
  if (!tmpl) {
    tmpl = GetCurrentTemplate();
    if (!tmpl)
      return;
  }
  if (!dtkNewSlotDialog) {
    Fl_Group::current(0L);
    dtkNewSlotDialog = new Fldtk_New_Slot_Dialog(400, 220, "New Slot");
  }
  dtkNewSlotDialog->setTemplate(tmpl);
  dtkNewSlotDialog->show();
}

/*---------------------------------------------------------------------------*/
int RenameSlot(Dtk_Slot *slot)
{
  if (!slot) {
    slot = GetCurrentSlot();
    if (!slot)
      return -1;
  }
  const char *name = fl_input("Slot name:", slot->key());
  if (!name)
    return -2;
  slot->setKey(name);
  return 0;
}

/*---------------------------------------------------------------------------*/
void InspectorPrintf(const char *msg, ...)
{
  char buffer[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buffer, msg, args);
  va_end(args);
  wConsole->insert(buffer);
  wConsole->show_insert_position();
}


//
// End of "$Id$".
//
