///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 30 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __main_window__
#define __main_window__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/gauge.h>
#include <wx/combobox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainWindow
///////////////////////////////////////////////////////////////////////////////
class MainWindow : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* main_menu_bar;
		wxMenu* menu_file;
		wxFlexGridSizer* mainSizer;
		wxStaticBitmap* btnInit;
		wxStaticBitmap* btnSim;
		wxStaticBitmap* btnView;
		wxPanel* pnlInit;
		wxStaticText* lblDomain;
		wxTextCtrl* txtDomain;
		wxStaticText* lblRes;
		wxTextCtrl* txtRes;
		wxStaticText* lblTime;
		wxTextCtrl* txtTime;
		wxStaticText* lblMaxHeight;
		wxTextCtrl* txtMaxHeight;
		wxStaticText* lblMinHeight;
		wxTextCtrl* txtMinHeight;
		wxStaticText* lblInactivHeight;
		wxTextCtrl* txtInactiveHeight;
		wxStaticText* lblInfo;
		wxTextCtrl* txtinfo;
		wxStaticText* lblDistribution;
		wxChoice* choiceDistribution;
		wxStaticText* lblMean;
		wxTextCtrl* txtMeanX1;
		wxTextCtrl* txtMeanY1;
		wxStaticText* lblVar;
		wxTextCtrl* txtVarX;
		wxTextCtrl* txtVarY;
		wxStaticText* lblHeight;
		wxTextCtrl* txtDistHeight;
		wxStaticText* lblTopo;
		wxChoice* choiceTopo;
		wxStaticText* txtBoudary;
		wxChoice* choiceBC;
		wxButton* btnInit1;
		wxPanel* pnlSim;
		wxStaticText* lblNodes;
		wxTextCtrl* txtNodes;
		wxStaticText* lblMethod;
		wxChoice* choiceMethod;
		wxStaticText* lblTimeDomains;
		wxTextCtrl* txtTimeDomains;
		wxStaticText* lblTol;
		wxTextCtrl* txtTol;
		wxStaticText* lblCyc;
		wxTextCtrl* txtCyc;
		wxGauge* barSim;
		wxButton* btnStart;
		wxStaticText* lblEstRemTime;
		wxStaticText* lblEstRemTime2;
		wxPanel* pnlVisu;
		wxStaticBoxSizer* staticsizerManagment;
		wxButton* btnload;
		wxStaticText* lblCities;
		wxComboBox* cbTowns;
		wxStaticText* lblLatitude;
		wxTextCtrl* txtLatitude;
		wxStaticText* lblLongitude;
		wxTextCtrl* txtLongitude;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInitMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSimMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnVisuMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnChooseTypo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChooseBoundary( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGenerateInitialization( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMethodSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadDataClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectComboBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWritingText( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Shallow Water Wave Simulator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1210,901 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
		~MainWindow();
	
};

#endif //__main_window__
