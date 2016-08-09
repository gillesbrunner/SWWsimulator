/*
 * included.h
 *
 *  Created on: 28 mars 2016
 *      Author: gbrunner
 */

#ifndef SRC_INCLUDED_H_
#define SRC_INCLUDED_H_

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

//#ifndef wxHAS_IMAGES_IN_RESOURCES
//    #include "../sample.xpm"
//#endif

#include "wx/aboutdlg.h"
#include "wx/artprov.h"
#include "wx/colordlg.h"
#include "wx/wfstream.h"
#include <wx/app.h>
#include <wx/settings.h>

// Open Scene Graph
#include "wx/defs.h"
#include "wx/cursor.h"
#include "wx/glcanvas.h"
#include <osgViewer/Viewer>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

// For wxCURSOR_BLANK below, but isn't used a.t.m.
#ifdef WIN32
#include "wx/msw/wx.rc"
#endif

#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>
#include <wx/image.h>
#include <wx/menu.h>

// Standards includes
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unistd.h>
#include <sstream>
#include <stdio.h>
#include <assert.h>

#include "XMLFile.h"
#include "panel_ids.h"
#include "exprtk/exprtk.hpp"

#include "../lib/alglib/include/stdafx.h"
#include "../lib/alglib/include/interpolation.h"

#include "Grid.h"
#include "OSGviewer.h"
#include "MyWindow.h"


#define ROES 0x1
#define WENO 0x2
#define PARA 0x4
#define PAPA 0x8

typedef unsigned int uint;

#endif /* SRC_INCLUDED_H_ */
