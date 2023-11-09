///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUICLASS_H__
#define __GUICLASS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statusbr.h>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIClass
///////////////////////////////////////////////////////////////////////////////
class GUIClass : public wxFrame 
{
	private:
		wxMenuBar* MenuBar;
	
	protected:
		wxStatusBar* statusBar;
		wxMenu* menu;
		wxButton* TL;
		wxButton* TM;
		wxButton* TR;
		wxButton* ML;
		wxButton* MM;
		wxButton* MR;
		wxButton* BL;
		wxButton* BM;
		wxButton* BR;
		wxButton* Reset;
		wxButton* Exit;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExitSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTTTClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetSelected( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIClass( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTT"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GUIClass();
	
};

#endif //__GUICLASS_H__
