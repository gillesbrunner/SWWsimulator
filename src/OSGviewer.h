/*
 * OSGviewer.h
 *
 *  Created on: 11 juil. 2016
 *      Author: gbrunner
 */

#ifndef OSGVIEWER_H_
#define OSGVIEWER_H_

#include "included.h"

class GraphicsWindowWX;
class MyWindow;

class OSGCanvas : public wxGLCanvas
{
public:
	OSGCanvas(wxWindow *parent, wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize, long style = 0,
		const wxString& name = wxT("TestGLCanvas"),
		int *attributes = 0);

	virtual ~OSGCanvas();

	wxGLContext& GetContext();
	void SetGraphicsWindow(osgViewer::GraphicsWindow *gw) { _graphics_window = gw; }
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnEraseBackground(wxEraseEvent& event);
	void OnChar(wxKeyEvent &event);
	void OnKeyUp(wxKeyEvent &event);
	void OnMouseEnter(wxMouseEvent &event);
	void OnMouseDown(wxMouseEvent &event);
	void OnMouseUp(wxMouseEvent &event);
	void OnMouseMotion(wxMouseEvent &event);
	void OnMouseWheel(wxMouseEvent &event);
	void UseCursor(bool value);

private:
	DECLARE_EVENT_TABLE() osg::ref_ptr<osgViewer::GraphicsWindow> _graphics_window;

	wxCursor _oldCursor;
	wxGLContext* context;
};

class GraphicsWindowWX : public osgViewer::GraphicsWindow
{
	public: GraphicsWindowWX(OSGCanvas *canvas);
	~GraphicsWindowWX();

	void init();

	//
	// GraphicsWindow interface
	//
	void grabFocus();
	void grabFocusIfPointerInWindow();
	void useCursor(bool cursorOn);
	bool makeCurrentImplementation();
	void swapBuffersImplementation();

	// not implemented yet...just use dummy implementation to get working.
	virtual bool valid() const { return true; }
	virtual bool realizeImplementation() { return true; }
	virtual bool isRealizedImplementation() const { return true; }
	virtual void closeImplementation() {}
	virtual bool releaseContextImplementation() { return true; }

private:
	// XXX need to set _canvas to NULL when the canvas is deleted by
	// its parent. for this, need to add event handler in OSGCanvas
	OSGCanvas* _canvas;
};

class VisuPanel : public wxPanel
{
public:
	osg::ref_ptr<osg::Group> root;

	VisuPanel(wxWindow* frame, MyWindow* main, const wxWindowID& id,
			const wxPoint& pos, const wxSize& size,
			long style = wxDEFAULT_FRAME_STYLE);

	void 				SetViewer(osgViewer::Viewer *viewer) { _viewer = viewer; }
	osgViewer::Viewer * GetViewer() 						 { return _viewer  ; }

	void OnIdle(wxIdleEvent& event);
	void CreateCanvas();

private:
	MyWindow* _mainWindow;
	wxFlexGridSizer* mainSizerVisu;

	osg::ref_ptr<osgViewer::Viewer> _viewer;

	DECLARE_EVENT_TABLE()
};


#endif /* OSGVIEWER_H_ */
