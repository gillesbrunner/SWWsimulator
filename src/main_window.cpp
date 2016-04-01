///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 30 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "main_window.h"

///////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	main_menu_bar = new wxMenuBar( 0 );
	menu_file = new wxMenu();
	wxMenuItem* item_exit;
	item_exit = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( item_exit );
	
	main_menu_bar->Append( menu_file, wxT("File") );
	
	this->SetMenuBar( main_menu_bar );
	
	wxFlexGridSizer* mainSizer;
	mainSizer = new wxFlexGridSizer( 4, 1, 0, 0 );
	mainSizer->AddGrowableCol( 0 );
	mainSizer->SetFlexibleDirection( wxBOTH );
	mainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	wxBoxSizer* sizerButtons;
	sizerButtons = new wxBoxSizer( wxHORIZONTAL );
	
	btnInit = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../icons/initialisation.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( btnInit, 0, wxALL, 5 );
	
	btnSim = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../icons/simulation.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( btnSim, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	btnView = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../icons/vizualisation.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( btnView, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	mainSizer->Add( sizerButtons, 1, wxEXPAND, 5 );
	
	pnlInit = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	pnlInit->Hide();
	
	wxFlexGridSizer* mainSizerInit;
	mainSizerInit = new wxFlexGridSizer( 4, 1, 10, 0 );
	mainSizerInit->SetFlexibleDirection( wxBOTH );
	mainSizerInit->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sizerProbInput;
	sizerProbInput = new wxStaticBoxSizer( new wxStaticBox( pnlInit, wxID_ANY, wxT("Problem Inputs") ), wxVERTICAL );
	
	wxFlexGridSizer* sizerInitValues;
	sizerInitValues = new wxFlexGridSizer( 7, 2, 0, 100 );
	sizerInitValues->SetFlexibleDirection( wxBOTH );
	sizerInitValues->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	lblDomain = new wxStaticText( pnlInit, wxID_ANY, wxT("Domain Size [km]:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblDomain->Wrap( -1 );
	sizerInitValues->Add( lblDomain, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtDomain = new wxTextCtrl( pnlInit, wxID_ANY, wxT("100"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	txtDomain->SetMinSize( wxSize( 100,-1 ) );
	
	sizerInitValues->Add( txtDomain, 0, wxALL, 5 );
	
	lblRes = new wxStaticText( pnlInit, wxID_ANY, wxT("Resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblRes->Wrap( -1 );
	sizerInitValues->Add( lblRes, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtTime = new wxTextCtrl( pnlInit, wxID_ANY, wxT("100"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	txtTime->SetMinSize( wxSize( 100,-1 ) );
	
	sizerInitValues->Add( txtTime, 0, wxALL, 5 );
	
	lblTime = new wxStaticText( pnlInit, wxID_ANY, wxT("Simulation Time [min]:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblTime->Wrap( -1 );
	sizerInitValues->Add( lblTime, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtRes = new wxTextCtrl( pnlInit, wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, 0 );
	txtRes->SetMinSize( wxSize( 100,-1 ) );
	
	sizerInitValues->Add( txtRes, 0, wxALL, 5 );
	
	m_txtMaxHeight = new wxStaticText( pnlInit, wxID_ANY, wxT("Max Wave Height [km]:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtMaxHeight->Wrap( -1 );
	sizerInitValues->Add( m_txtMaxHeight, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtMaxHeight = new wxTextCtrl( pnlInit, wxID_ANY, wxT("0.1"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMaxHeight->SetMinSize( wxSize( 100,-1 ) );
	
	sizerInitValues->Add( txtMaxHeight, 0, wxALL, 5 );
	
	lblMinHeight = new wxStaticText( pnlInit, wxID_ANY, wxT("Min Water Height [km]:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblMinHeight->Wrap( -1 );
	sizerInitValues->Add( lblMinHeight, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtMinHeight = new wxTextCtrl( pnlInit, wxID_ANY, wxT("0.00001"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMinHeight->SetMinSize( wxSize( 100,-1 ) );
	
	sizerInitValues->Add( txtMinHeight, 0, wxALL, 5 );
	
	lblInactivHeight = new wxStaticText( pnlInit, wxID_ANY, wxT("Inactive Cell Threshold [km]:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblInactivHeight->Wrap( -1 );
	sizerInitValues->Add( lblInactivHeight, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtInactiveHeight = new wxTextCtrl( pnlInit, wxID_ANY, wxT("0.0002"), wxDefaultPosition, wxDefaultSize, 0 );
	txtInactiveHeight->SetMinSize( wxSize( 100,-1 ) );
	
	sizerInitValues->Add( txtInactiveHeight, 0, wxALL, 5 );
	
	lblInfo = new wxStaticText( pnlInit, wxID_ANY, wxT("Extra Information:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblInfo->Wrap( -1 );
	sizerInitValues->Add( lblInfo, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl7 = new wxTextCtrl( pnlInit, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl7->SetMinSize( wxSize( 200,-1 ) );
	
	sizerInitValues->Add( m_textCtrl7, 0, wxALL, 5 );
	
	sizerProbInput->Add( sizerInitValues, 1, wxEXPAND, 5 );
	
	mainSizerInit->Add( sizerProbInput, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sizerInitSol;
	sizerInitSol = new wxStaticBoxSizer( new wxStaticBox( pnlInit, wxID_ANY, wxT("Initial Solution") ), wxVERTICAL );
	
	wxFlexGridSizer* sizerSol;
	sizerSol = new wxFlexGridSizer( 4, 2, 0, 252 );
	sizerSol->SetFlexibleDirection( wxBOTH );
	sizerSol->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	lblDistribution = new wxStaticText( pnlInit, wxID_ANY, wxT("Distribution:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblDistribution->Wrap( -1 );
	sizerSol->Add( lblDistribution, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString choiseDistributionChoices[] = { wxT("Beta"), wxT("Normal"), wxT("Uniform") };
	int choiseDistributionNChoices = sizeof( choiseDistributionChoices ) / sizeof( wxString );
	choiseDistribution = new wxChoice( pnlInit, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiseDistributionNChoices, choiseDistributionChoices, 0 );
	choiseDistribution->SetSelection( 1 );
	sizerSol->Add( choiseDistribution, 0, wxALL, 5 );
	
	lblMean = new wxStaticText( pnlInit, wxID_ANY, wxT("Center:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblMean->Wrap( -1 );
	sizerSol->Add( lblMean, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* sizerMean1;
	sizerMean1 = new wxBoxSizer( wxHORIZONTAL );
	
	txtMeanX1 = new wxTextCtrl( pnlInit, wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMeanX1->SetMinSize( wxSize( 50,-1 ) );
	
	sizerMean1->Add( txtMeanX1, 0, wxALL, 5 );
	
	txtMeanY1 = new wxTextCtrl( pnlInit, wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMeanY1->SetMinSize( wxSize( 50,-1 ) );
	
	sizerMean1->Add( txtMeanY1, 0, wxALL, 5 );
	
	sizerSol->Add( sizerMean1, 1, wxEXPAND, 5 );
	
	lblVar = new wxStaticText( pnlInit, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblVar->Wrap( -1 );
	sizerSol->Add( lblVar, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* sizerVar;
	sizerVar = new wxBoxSizer( wxHORIZONTAL );
	
	txtVarX = new wxTextCtrl( pnlInit, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	txtVarX->SetMinSize( wxSize( 50,-1 ) );
	
	sizerVar->Add( txtVarX, 0, wxALL, 5 );
	
	txtVarY = new wxTextCtrl( pnlInit, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	txtVarY->SetMinSize( wxSize( 50,-1 ) );
	
	sizerVar->Add( txtVarY, 0, wxALL, 5 );
	
	sizerSol->Add( sizerVar, 1, wxEXPAND, 5 );
	
	lblHeight = new wxStaticText( pnlInit, wxID_ANY, wxT("Height:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblHeight->Wrap( -1 );
	sizerSol->Add( lblHeight, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtDistHeight = new wxTextCtrl( pnlInit, wxID_ANY, wxT("0.4"), wxDefaultPosition, wxDefaultSize, 0 );
	txtDistHeight->SetMinSize( wxSize( 110,-1 ) );
	
	sizerSol->Add( txtDistHeight, 0, wxALL, 5 );
	
	sizerInitSol->Add( sizerSol, 1, wxEXPAND, 5 );
	
	mainSizerInit->Add( sizerInitSol, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sizerTypo;
	sizerTypo = new wxStaticBoxSizer( new wxStaticBox( pnlInit, wxID_ANY, wxT("Typography") ), wxVERTICAL );
	
	wxFlexGridSizer* sizerInitTypo;
	sizerInitTypo = new wxFlexGridSizer( 2, 2, 0, 160 );
	sizerInitTypo->SetFlexibleDirection( wxBOTH );
	sizerInitTypo->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	lblTypo = new wxStaticText( pnlInit, wxID_ANY, wxT("Typography :"), wxDefaultPosition, wxDefaultSize, 0 );
	lblTypo->Wrap( -1 );
	sizerInitTypo->Add( lblTypo, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString choiceTypoChoices[] = { wxT("Flat"), wxT("Sinus"), wxT("Island"), wxT("Create New") };
	int choiceTypoNChoices = sizeof( choiceTypoChoices ) / sizeof( wxString );
	choiceTypo = new wxChoice( pnlInit, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceTypoNChoices, choiceTypoChoices, 0 );
	choiceTypo->SetSelection( 0 );
	choiceTypo->SetMinSize( wxSize( 150,-1 ) );
	
	sizerInitTypo->Add( choiceTypo, 0, wxALL, 5 );
	
	txtBoudary = new wxStaticText( pnlInit, wxID_ANY, wxT("Boundary Conditions:"), wxDefaultPosition, wxDefaultSize, 0 );
	txtBoudary->Wrap( -1 );
	sizerInitTypo->Add( txtBoudary, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString choiseBCChoices[] = { wxT("Absorbing"), wxT("Periodic"), wxT("Reflecting") };
	int choiseBCNChoices = sizeof( choiseBCChoices ) / sizeof( wxString );
	choiseBC = new wxChoice( pnlInit, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiseBCNChoices, choiseBCChoices, 0 );
	choiseBC->SetSelection( 2 );
	choiseBC->SetMinSize( wxSize( 150,-1 ) );
	
	sizerInitTypo->Add( choiseBC, 0, wxALL, 5 );
	
	sizerTypo->Add( sizerInitTypo, 1, wxEXPAND, 5 );
	
	mainSizerInit->Add( sizerTypo, 1, wxEXPAND, 5 );
	
	btnInit1 = new wxButton( pnlInit, wxID_ANY, wxT("Generate File"), wxDefaultPosition, wxDefaultSize, 0 );
	mainSizerInit->Add( btnInit1, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxALL, 5 );
	
	pnlInit->SetSizer( mainSizerInit );
	pnlInit->Layout();
	mainSizerInit->Fit( pnlInit );
	mainSizer->Add( pnlInit, 1, wxALIGN_TOP|wxALL|wxEXPAND, 5 );
	
	pnlSim = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* mainSizerSim;
	mainSizerSim = new wxFlexGridSizer( 2, 1, 10, 200 );
	mainSizerSim->SetFlexibleDirection( wxBOTH );
	mainSizerSim->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* staticsizerSimMethod;
	staticsizerSimMethod = new wxStaticBoxSizer( new wxStaticBox( pnlSim, wxID_ANY, wxT("Method") ), wxVERTICAL );
	
	wxFlexGridSizer* sizerSimMethod;
	sizerSimMethod = new wxFlexGridSizer( 5, 2, 0, 100 );
	sizerSimMethod->SetFlexibleDirection( wxBOTH );
	sizerSimMethod->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	lblNodes = new wxStaticText( pnlSim, wxID_ANY, wxT("MPI Nodes:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblNodes->Wrap( -1 );
	sizerSimMethod->Add( lblNodes, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtNodes = new wxTextCtrl( pnlSim, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	txtNodes->SetMinSize( wxSize( 100,-1 ) );
	
	sizerSimMethod->Add( txtNodes, 0, wxALL, 5 );
	
	lblMethod = new wxStaticText( pnlSim, wxID_ANY, wxT("Method:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblMethod->Wrap( -1 );
	sizerSimMethod->Add( lblMethod, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString choiceMethodChoices[] = { wxT("Roes"), wxT("Weno"), wxT("Parareal"), wxT("Patient Adaptive Parareal") };
	int choiceMethodNChoices = sizeof( choiceMethodChoices ) / sizeof( wxString );
	choiceMethod = new wxChoice( pnlSim, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceMethodNChoices, choiceMethodChoices, 0 );
	choiceMethod->SetSelection( 3 );
	sizerSimMethod->Add( choiceMethod, 0, wxALL, 5 );
	
	lblTimeDomains = new wxStaticText( pnlSim, wxID_ANY, wxT("Time Domains:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblTimeDomains->Wrap( -1 );
	sizerSimMethod->Add( lblTimeDomains, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtTimeDomains = new wxTextCtrl( pnlSim, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	txtTimeDomains->SetMinSize( wxSize( 100,-1 ) );
	
	sizerSimMethod->Add( txtTimeDomains, 0, wxALL, 5 );
	
	lblTol = new wxStaticText( pnlSim, wxID_ANY, wxT("Tolerance:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblTol->Wrap( -1 );
	sizerSimMethod->Add( lblTol, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtTol = new wxTextCtrl( pnlSim, wxID_ANY, wxT("1e-5"), wxDefaultPosition, wxDefaultSize, 0 );
	txtTol->SetMinSize( wxSize( 100,-1 ) );
	
	sizerSimMethod->Add( txtTol, 0, wxALL, 5 );
	
	lblCyc = new wxStaticText( pnlSim, wxID_ANY, wxT("Cycles:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblCyc->Wrap( -1 );
	sizerSimMethod->Add( lblCyc, 0, wxALL, 5 );
	
	txtCyc = new wxTextCtrl( pnlSim, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	txtCyc->SetMinSize( wxSize( 100,-1 ) );
	
	sizerSimMethod->Add( txtCyc, 0, wxALL, 5 );
	
	staticsizerSimMethod->Add( sizerSimMethod, 1, wxEXPAND, 5 );
	
	mainSizerSim->Add( staticsizerSimMethod, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* staticsizerSim;
	staticsizerSim = new wxStaticBoxSizer( new wxStaticBox( pnlSim, wxID_ANY, wxT("Simulation") ), wxVERTICAL );
	
	wxFlexGridSizer* sizerSimSim;
	sizerSimSim = new wxFlexGridSizer( 2, 2, 0, 0 );
	sizerSimSim->SetFlexibleDirection( wxBOTH );
	sizerSimSim->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	barSim = new wxGauge( pnlSim, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	barSim->SetMinSize( wxSize( 800,-1 ) );
	
	sizerSimSim->Add( barSim, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	btnStart = new wxButton( pnlSim, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	btnStart->SetMinSize( wxSize( 120,-1 ) );
	
	sizerSimSim->Add( btnStart, 0, wxALL, 5 );
	
	wxBoxSizer* sizerEstRemTime;
	sizerEstRemTime = new wxBoxSizer( wxHORIZONTAL );
	
	lblEstRemTiime = new wxStaticText( pnlSim, wxID_ANY, wxT("Estimated remaining time:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblEstRemTiime->Wrap( -1 );
	sizerEstRemTime->Add( lblEstRemTiime, 0, wxALL, 5 );
	
	lblEstRemTime2 = new wxStaticText( pnlSim, wxID_ANY, wxT("inf"), wxDefaultPosition, wxDefaultSize, 0 );
	lblEstRemTime2->Wrap( -1 );
	sizerEstRemTime->Add( lblEstRemTime2, 0, wxALL, 5 );
	
	sizerSimSim->Add( sizerEstRemTime, 1, wxEXPAND, 5 );
	
	staticsizerSim->Add( sizerSimSim, 1, wxEXPAND, 5 );
	
	mainSizerSim->Add( staticsizerSim, 1, wxEXPAND, 5 );
	
	pnlSim->SetSizer( mainSizerSim );
	pnlSim->Layout();
	mainSizerSim->Fit( pnlSim );
	mainSizer->Add( pnlSim, 1, wxALIGN_TOP|wxALL|wxEXPAND, 5 );
	
	pnlVisu = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* mainSizerVisu;
	mainSizerVisu = new wxFlexGridSizer( 2, 2, 0, 0 );
	mainSizerVisu->SetFlexibleDirection( wxBOTH );
	mainSizerVisu->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	pnlVisu->SetSizer( mainSizerVisu );
	pnlVisu->Layout();
	mainSizerVisu->Fit( pnlVisu );
	mainSizer->Add( pnlVisu, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	// Connect Events
	this->Connect( item_exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnExit ) );
	btnInit->Connect( wxEVT_MOTION, wxMouseEventHandler( MainWindow::OnInitMotion ), NULL, this );
	btnSim->Connect( wxEVT_MOTION, wxMouseEventHandler( MainWindow::OnSimMotion ), NULL, this );
	btnView->Connect( wxEVT_MOTION, wxMouseEventHandler( MainWindow::OnVisuMotion ), NULL, this );
	choiceTypo->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::OnChooseTypo ), NULL, this );
	choiseBC->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::OnChooseBoundary ), NULL, this );
	btnInit1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnGenerateInitialization ), NULL, this );
	choiceMethod->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::OnMethodSelect ), NULL, this );
}

MainWindow::~MainWindow()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnExit ) );
	btnInit->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainWindow::OnInitMotion ), NULL, this );
	btnSim->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainWindow::OnSimMotion ), NULL, this );
	btnView->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainWindow::OnVisuMotion ), NULL, this );
	choiceTypo->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::OnChooseTypo ), NULL, this );
	choiseBC->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::OnChooseBoundary ), NULL, this );
	btnInit1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnGenerateInitialization ), NULL, this );
	choiceMethod->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::OnMethodSelect ), NULL, this );
}
