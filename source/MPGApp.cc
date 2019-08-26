/*
 * Metroid Password Generator
 * Copyright (C) 2005,2007-2008 emuWorks
 * http://games.technoplaza.net/
 *
 * This file is part of Metroid Password Generator.
 *
 * Metroid Password Generator is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Metroid Password Generator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Metroid Password Generator; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
// $Id: MPGApp.cc,v 1.7 2008/12/17 00:23:12 jdratlif Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/xrc/xmlres.h>

#include "AppConstants.hh"
#include "MPGApp.hh"
#include "view/MPGFrame.hh"

using namespace mpg;

const wxString mpg::APP_NAME(wxT("Metroid Password Generator"));
const wxString mpg::APP_VERSION(wxT("1.0a"));
const wxString mpg::APP_COPYRIGHT(wxT("Copyright (C) 2005,2007-2008 emuWorks"));
const wxString mpg::APP_URL(wxT("http://games.technoplaza.net/"));

// prototype for InitXmlResource function
void InitXmlResource();

bool MPGApp::OnInit() {
    // initialize the XRC resources
    wxXmlResource::Get()->InitAllHandlers();
    InitXmlResource();
    
    MPGFrame *frame = new MPGFrame;
    frame->Show();
    
    return true;
}

IMPLEMENT_CLASS(MPGApp, wxApp)
IMPLEMENT_APP(MPGApp)

