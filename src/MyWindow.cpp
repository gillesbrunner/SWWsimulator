/*
 * MyWindow.cpp
 *
 *  Created on: 28 mars 2016
 *      Author: gbrunner
 */

#include "MyWindow.h"

MyWindow::MyWindow()
: MainWindow((wxFrame *)NULL)
{
	selectedPanel = INITIALISATION;
	pnlInit->Show();
	pnlSim->Hide();
	pnlVisu->Hide();
}

MyWindow::~MyWindow() {}

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
	using namespace rapidxml;
	{
		std::ofstream streamOut("init.sww");

		xml_document<> doc;
		//doc.allocate_node(node_type::node_data, "initialisation");

		//xml_node* init_node = doc.first_node("initialisation");

		//xml_attribute<> *attr = doc.allocate_attribute("size", "100");
		//init_node->append_attribbute(attr);

		char buffer[4096];                      // You are responsible for making the buffer large enough!
		char *end = print(buffer, doc, 0);      // end contains pointer to character after last printed character
		*end = 0;                               // Add string terminator after XML
	}
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
