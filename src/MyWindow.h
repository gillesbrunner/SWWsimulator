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

class MyWindow: public MainWindow {
private :
	Panel selectedPanel;

public:
	MyWindow();

	void OnExit(wxCommandEvent& event);

	void OnInitMotion( wxMouseEvent& event );
	void OnSimMotion( wxMouseEvent& event );
	void OnVisuMotion( wxMouseEvent& event );

	void OnMethodSelect( wxCommandEvent& event );

	virtual ~MyWindow();
};

#endif /* MYWINDOW_H_ */
