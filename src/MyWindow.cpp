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

