#include "simulator.h"

IMPLEMENT_APP(MyApp)

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
