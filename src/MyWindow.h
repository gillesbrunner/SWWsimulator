/*
 * MyWindow.h
 *
 *  Created on: 28 mars 2016
 *      Author: gbrunner
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "included.h"
#include "main_window.h"

typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>   expression_t;
typedef exprtk::parser<double>     	 parser_t;


class MyWindow: public MainWindow
{
private :
	Panel _selectedPanel;

	VisuPanel* 	_OSGview;
	wxStatusBar* _statusBar;
	wxGauge* _progressGauge;

	expression_t _expression;
	double _exprX;
	double _exprY;

public:
	Grid* simGrid;

	MyWindow();

	void OnSize( wxSizeEvent& event );
	void OnExit(wxCommandEvent& event);

	void OnInitMotion( wxMouseEvent& event );
	void OnSimMotion( wxMouseEvent& event );
	void OnVisuMotion( wxMouseEvent& event );

	void OnMethodSelect( wxCommandEvent& event );
	void OnGenerateInitialization( wxCommandEvent& event );
	void OnLoadDataClick( wxCommandEvent& event );
	void OnSelectComboBox( wxCommandEvent& event );
	void OnWritingText( wxCommandEvent& event );

	virtual ~MyWindow();

	inline double EvaluateExpression(double const& x, double const& y)
	{ _exprX = x; _exprY = y; return _expression.value(); }

	void SetProgressBarValue(int v);

private:
	void InitExpression(std::string expression_string);
};

#endif /* MYWINDOW_H_ */
