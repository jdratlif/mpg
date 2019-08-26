/*
 * Metroid Password Generator
 * Copyright (C) 2005 emuWorks
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
 
// $Id: MPGApp.hh,v 1.2 2005/09/27 08:05:00 technoplaza Exp $

#ifndef _MPGAPP_HH_
#define _MPGAPP_HH_

/// a namespace for all the classes used by mpg
namespace mpg {
    /// The application class and starting point.
    class MPGApp : public wxApp {
        DECLARE_CLASS(MPGApp)
        
    public:
        /**
         * Called to initialize the application.
         */
        virtual bool OnInit();
    };
    
    DECLARE_APP(MPGApp)
}

#endif

