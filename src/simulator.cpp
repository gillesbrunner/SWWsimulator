#include "simulator.h"

// ---------------------------------------------------------------------------
// MyApp
// ---------------------------------------------------------------------------

// Initialise this in OnInit, not statically
bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    // Create the main frame window

    MyWindow* frame = new MyWindow();
    frame->Show(true);

    return true;
}

IMPLEMENT_APP(MyApp)
