/*
 * OSGviewer.cpp
 *
 *  Created on: 11 juil. 2016
 *      Author: gbrunner
 */

#include "OSGviewer.h"

BEGIN_EVENT_TABLE(VisuPanel, wxPanel)
    EVT_IDLE(VisuPanel::OnIdle)
END_EVENT_TABLE()

/* My frame constructor */
VisuPanel::VisuPanel(wxWindow *frame, MyWindow* main, const wxWindowID& id, const wxPoint& pos,
    const wxSize& size, long style)
    : wxPanel(frame, id, pos, size, style),
	  _mainWindow(main)
{
	Show();
	CreateCanvas();

	root = new osg::Group();
}

void VisuPanel::OnIdle(wxIdleEvent &event)
{
    if (_viewer) _viewer->frame();

    event.RequestMore();
}

void VisuPanel::CreateCanvas()
{
	// create osg canvas
	//    - initialize

	int *attributes = new int[7];
	attributes[0] = int(WX_GL_DOUBLEBUFFER);
	attributes[1] = WX_GL_RGBA;
	attributes[2] = WX_GL_DEPTH_SIZE;
	attributes[3] = 8;
	attributes[4] = WX_GL_STENCIL_SIZE;
	attributes[5] = 8;
	attributes[6] = 0;

	int width  = wxSystemSettings::GetMetric ( wxSYS_SCREEN_X ) ;
	int height = wxSystemSettings::GetMetric ( wxSYS_SCREEN_Y );

	OSGCanvas *canvas = new OSGCanvas(this, wxID_ANY, wxDefaultPosition,
	wxSize(width, height), wxSUNKEN_BORDER, wxT("osgviewerWX"), attributes);

	GraphicsWindowWX* gw = new GraphicsWindowWX(canvas);

	canvas->SetGraphicsWindow(gw);

	osgViewer::Viewer *viewer = new osgViewer::Viewer;
	viewer->getCamera()->setGraphicsContext(gw);
	viewer->getCamera()->setViewport(0,0,width,height);
	viewer->addEventHandler(new osgViewer::StatsHandler);
	viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);

	// load the scene.
	/*wxString fname("cessna.osg");
	osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(std::string(fname.mb_str()));
	if (!loadedModel)
	{
		std::cout <<" No data loaded." << std::endl;
	    return;
	}
	viewer->setSceneData(loadedModel.get());
	*/

	viewer->setCameraManipulator(new osgGA::TrackballManipulator);
	SetViewer(viewer);
}


BEGIN_EVENT_TABLE(OSGCanvas, wxGLCanvas)
    EVT_SIZE                (OSGCanvas::OnSize)
    EVT_PAINT               (OSGCanvas::OnPaint)
    EVT_ERASE_BACKGROUND    (OSGCanvas::OnEraseBackground)

    EVT_CHAR                (OSGCanvas::OnChar)
    EVT_KEY_UP              (OSGCanvas::OnKeyUp)

    EVT_ENTER_WINDOW        (OSGCanvas::OnMouseEnter)
    EVT_LEFT_DOWN           (OSGCanvas::OnMouseDown)
    EVT_MIDDLE_DOWN         (OSGCanvas::OnMouseDown)
    EVT_RIGHT_DOWN          (OSGCanvas::OnMouseDown)
    EVT_LEFT_UP             (OSGCanvas::OnMouseUp)
    EVT_MIDDLE_UP           (OSGCanvas::OnMouseUp)
    EVT_RIGHT_UP            (OSGCanvas::OnMouseUp)
    EVT_MOTION              (OSGCanvas::OnMouseMotion)
    EVT_MOUSEWHEEL          (OSGCanvas::OnMouseWheel)
END_EVENT_TABLE()

// changed constructor to new wxGLCanvas constructor in 2.9.6
OSGCanvas::OSGCanvas(wxWindow *parent, wxWindowID id,
    const wxPoint& pos, const wxSize& size, long style, const wxString& name, int *attributes)
    : wxGLCanvas(parent, id, attributes, pos, size, style|wxFULL_REPAINT_ON_RESIZE, name)
{
    // default cursor to standard
    _oldCursor = *wxSTANDARD_CURSOR;
    context = new wxGLContext(this);
}

OSGCanvas::~OSGCanvas()
{
}

wxGLContext& OSGCanvas::GetContext()
{
    return *context;
}

void OSGCanvas::OnPaint( wxPaintEvent& WXUNUSED(event) )
{
    /* must always be here */
    wxPaintDC dc(this);
}

void OSGCanvas::OnSize(wxSizeEvent& event)
{
    // this is also necessary to update the context on some platforms
    // method not available in wxWidgets 2.9.6
//    wxGLCanvas::OnSize(event);

    // set GL viewport (not called by wxGLCanvas::OnSize on all platforms...)
    int width, height;
    GetClientSize(&width, &height);

    if (_graphics_window.valid())
    {
        // update the window dimensions, in case the window has been resized.
        _graphics_window->getEventQueue()->windowResize(0, 0, width, height);
        _graphics_window->resized(0,0,width,height);
    }
}

void OSGCanvas::OnEraseBackground(wxEraseEvent& WXUNUSED(event))
{
    /* Do nothing, to avoid flashing on MSW */
}

void OSGCanvas::OnChar(wxKeyEvent &event)
{
#if wxUSE_UNICODE
    int key = event.GetUnicodeKey();
#else
    int key = event.GetKeyCode();
#endif

    if (_graphics_window.valid())
        _graphics_window->getEventQueue()->keyPress(key);

    // If this key event is not processed here, we should call
    // event.Skip() to allow processing to continue.
}

void OSGCanvas::OnKeyUp(wxKeyEvent &event)
{
#if wxUSE_UNICODE
    int key = event.GetUnicodeKey();
#else
    int key = event.GetKeyCode();
#endif

    if (_graphics_window.valid())
        _graphics_window->getEventQueue()->keyRelease(key);

    // If this key event is not processed here, we should call
    // event.Skip() to allow processing to continue.
}

void OSGCanvas::OnMouseEnter(wxMouseEvent &event)
{
    // Set focus to ourselves, so keyboard events get directed to us
    SetFocus();
}

void OSGCanvas::OnMouseDown(wxMouseEvent &event)
{
    if (_graphics_window.valid())
    {
        _graphics_window->getEventQueue()->mouseButtonPress(event.GetX(), event.GetY(),
            event.GetButton());
    }
}

void OSGCanvas::OnMouseUp(wxMouseEvent &event)
{
    if (_graphics_window.valid())
    {
        _graphics_window->getEventQueue()->mouseButtonRelease(event.GetX(), event.GetY(),
            event.GetButton());
    }
}

void OSGCanvas::OnMouseMotion(wxMouseEvent &event)
{
    if (_graphics_window.valid())
        _graphics_window->getEventQueue()->mouseMotion(event.GetX(), event.GetY());
}

void OSGCanvas::OnMouseWheel(wxMouseEvent &event)
{
    int delta = event.GetWheelRotation() / event.GetWheelDelta() * event.GetLinesPerAction();

    if (_graphics_window.valid()) {
        _graphics_window->getEventQueue()->mouseScroll(
            delta>0 ?
            osgGA::GUIEventAdapter::SCROLL_UP :
            osgGA::GUIEventAdapter::SCROLL_DOWN);
    }
}

void OSGCanvas::UseCursor(bool value)
{
    if (value)
    {
        // show the old cursor
        SetCursor(_oldCursor);
    }
    else
    {
        // remember the old cursor
        _oldCursor = GetCursor();

        // hide the cursor
        //    - can't find a way to do this neatly, so create a 1x1, transparent image
        wxImage image(1,1);
        image.SetMask(true);
        image.SetMaskColour(0, 0, 0);
        wxCursor cursor(image);
        SetCursor(cursor);

        // On wxGTK, only works as of version 2.7.0
        // (http://trac.wxwidgets.org/ticket/2946)
        // SetCursor( wxStockCursor( wxCURSOR_BLANK ) );
    }
}

GraphicsWindowWX::GraphicsWindowWX(OSGCanvas *canvas)
{
    _canvas = canvas;

    _traits = new GraphicsContext::Traits;

    wxPoint pos = _canvas->GetPosition();
    wxSize  size = _canvas->GetSize();

    _traits->x = pos.x;
    _traits->y = pos.y;
    _traits->width = size.x;
    _traits->height = size.y;

    init();
}

GraphicsWindowWX::~GraphicsWindowWX()
{
}

void GraphicsWindowWX::init()
{
    if (valid())
    {
        setState( new osg::State );
        getState()->setGraphicsContext(this);

        if (_traits.valid() && _traits->sharedContext != nullptr)
        {
            getState()->setContextID( _traits->sharedContext->getState()->getContextID() );
            incrementContextIDUsageCount( getState()->getContextID() );
        }
        else
        {
            getState()->setContextID( osg::GraphicsContext::createNewContextID() );
        }
    }
}

void GraphicsWindowWX::grabFocus()
{
    // focus the canvas
    _canvas->SetFocus();
}

void GraphicsWindowWX::grabFocusIfPointerInWindow()
{
    // focus this window, if the pointer is in the window
    wxPoint pos = wxGetMousePosition();
    if (wxFindWindowAtPoint(pos) == _canvas)
        _canvas->SetFocus();
}

void GraphicsWindowWX::useCursor(bool cursorOn)
{
    _canvas->UseCursor(cursorOn);
}

bool GraphicsWindowWX::makeCurrentImplementation()
{
    _canvas->SetCurrent(_canvas->GetContext());
    return true;
}

void GraphicsWindowWX::swapBuffersImplementation()
{
    _canvas->SwapBuffers();
}
