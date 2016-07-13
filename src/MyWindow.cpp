/*
 * MyWindow.cpp
 *
 *  Created on: 28 mars 2016
 *      Author: gbrunner
 */

#include "MyWindow.h"
#include "OSGviewer.h"

MyWindow::MyWindow()
: MainWindow((wxFrame *)NULL)
{
	pnlVisu = new VisuPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	mainSizer->Add( pnlVisu, 1, wxALIGN_TOP|wxALL|wxEXPAND, 5 );

	selectedPanel = INITIALISATION;
	pnlInit->Show();
	pnlSim->Hide();
	pnlVisu->Hide();
}

MyWindow::~MyWindow()
{
	delete pnlVisu;
}

void MyWindow::OnExit(wxCommandEvent& event) { ::wxExit(); }

void MyWindow::OnInitMotion( wxMouseEvent& event )
{
	if (selectedPanel != INITIALISATION) {
		pnlInit->Show();
		selectedPanel = INITIALISATION;

		pnlSim->Hide();
		pnlVisu->Hide();
		Layout();
	}
}

void MyWindow::OnSimMotion( wxMouseEvent& event )
{
	if (selectedPanel != SIMULATION) {
		pnlSim->Show();
		selectedPanel = SIMULATION;

		pnlInit->Hide();
		pnlVisu->Hide();
		Layout();
	}
}

void MyWindow::OnVisuMotion( wxMouseEvent& event )
{
	pnlVisu->CreateCanvas();

	if (selectedPanel != VISUALISATION) {
		pnlVisu->Show();
		selectedPanel = VISUALISATION;

		pnlInit->Hide();
		pnlSim->Hide();
		Layout();
	}
}

void MyWindow::OnMethodSelect( wxCommandEvent& event )
{
	int method = choiceMethod->GetCurrentSelection();

	switch (method)
	{
	case 0: method = ROES; break;
	case 1: method = WENO; break;
	case 2: method = PARA; break;
	case 3: method = PARA + PAPA; break;
	default:
		break;
	}

	if (method & PARA)
	{
		lblTimeDomains->Show();
		txtTimeDomains->Show();
		lblTol->Show();
		txtTol->Show();
		lblCyc->Show();
		if (method & PAPA) txtCyc->Show();
		else 			   txtCyc->Hide();
	}
	else
	{
		lblTimeDomains->Hide();
		txtTimeDomains->Hide();
		lblTol->Hide();
		txtTol->Hide();
		lblCyc->Hide();
		txtCyc->Hide();
	}
	Layout();
}

void MyWindow::OnGenerateInitialization( wxCommandEvent& event )
{
	std::ofstream streamOut("init.xml");

	Node root("initialisation");

	Node input("inputs");
	Node size("size", std::string(txtDomain->GetLineText(0))); input.add(&size);
	Node res("resolution", std::string(txtRes->GetLineText(0))); input.add(&res);
	Node time("sim_time", std::string(txtTime->GetLineText(0))); input.add(&time);
	Node maxH("max_water_height", std::string(txtMaxHeight->GetLineText(0))); input.add(&maxH);
	Node minH("min_water_height", std::string(txtMinHeight->GetLineText(0))); input.add(&minH);
	Node thrshld("cell_threshold", std::string(txtInactiveHeight->GetLineText(0))); input.add(&thrshld);
	Node info("extra_info", std::string(txtinfo->GetLineText(0))); input.add(&info);

	Node init_sol("initial_solution");
	int select = choiceDistribution->GetSelection();
	Node dist("distribution", std::string(choiceDistribution->GetString(select))); init_sol.add(&dist);
	Node centerX("centerX", std::string(txtMeanX1->GetLineText(0))); init_sol.add(&centerX);
	Node centerY("centerY", std::string(txtMeanY1->GetLineText(0))); init_sol.add(&centerY);
	Node widthX("widthX", std::string(txtVarX->GetLineText(0))); init_sol.add(&widthX);
	Node widthY("widthY", std::string(txtVarY->GetLineText(0))); init_sol.add(&widthY);
	Node height("height", std::string(txtDistHeight->GetLineText(0))); init_sol.add(&height);

	Node topo("topography");
	select = choiceTopo->GetSelection();
	Node topo_type("topo_type", std::string(choiceTopo->GetString(select))); topo.add(&topo_type);
	select = choiceBC->GetSelection();
	Node boundaries("boundaries", std::string(choiceBC->GetString(select))); topo.add(&boundaries);

	root.add(&input);
	root.add(&init_sol);
	root.add(&topo);

	root.write(streamOut);
}

// ===================================================================
void MyWindow::InitExpression(std::string expression_string)
{
	symbol_table_t symbol_table;
	symbol_table.add_variable("x", _exprX);
	symbol_table.add_variable("y", _exprY);
	symbol_table.add_constants();

	_expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, _expression);
}
