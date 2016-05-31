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

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sstream>

#include "panel_ids.h"
#include "XMLFile.h"
#include "exprtk/exprtk.hpp"

#define ROES 0x1
#define WENO 0x2
#define PARA 0x4
#define PAPA 0x8

#endif /* SRC_INCLUDED_H_ */
