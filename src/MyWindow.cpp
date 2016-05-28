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
	std::ofstream streamOut("init.sww");

	 rapidxml::xml_document<> doc;

	 // xml declaration node
	 rapidxml::xml_node<>* decl = doc.allocate_node(rapidxml::node_declaration); //allocate default xml declaration node

	 //apppend special attributes to it
	 decl->append_attribute(doc.allocate_attribute("version", "1.0"));
	 decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
	 doc.append_node(decl); //finally, append node

	 //allocate root node
	 rapidxml::xml_node<>* root = doc.allocate_node(rapidxml::node_element,"root"); //node element is the type of node
	 doc.append_node(root);


	 //node1
	 rapidxml::xml_node<>* node1 = doc.allocate_node(rapidxml::node_element,"node1");
	 node1->value("Contents of node1");
	 root->append_node(node1);

	 //root2
	 rapidxml::xml_node<>* root2 = doc.allocate_node(rapidxml::node_element,"root2");
	 root2->value("Contetns of root2");
	 doc.append_node(root2);

	 streamOut << doc;
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
