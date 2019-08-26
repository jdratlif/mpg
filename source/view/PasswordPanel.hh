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
 
// $Id: PasswordPanel.hh,v 1.5 2008/12/17 00:23:12 jdratlif Exp $

#ifndef MPG_PASSWORDPANEL_HH_
#define MPG_PASSWORDPANEL_HH_

namespace mpg {
    class Password;
    
    /// class to display a password in Metroid font and style
    class PasswordPanel : public wxPanel {
        DECLARE_DYNAMIC_CLASS(PasswordPanel)
        DECLARE_EVENT_TABLE()
        
    private:
        wxBitmap alphabet;
        const Password *password;
        
        static const int START_X = 4;
        static const int START_Y = 4;
        static const int CHARS_PER_ROW = 13;
        static const int CHAR_WIDTH = 16;
        static const int CHAR_HEIGHT = 16;
        
        /**
         * Gets the upper-left corner position of a letter in the alphabet
         * bitmap.
         *
         * @param letter The letter to find.
         *
         * @return The (x,y) position of the letter.
         */
        wxPoint getLetterPos(wxChar letter) const;
    
        /**
         * Called to erase the background on this PasswordPanel.
         *
         * @param event The triggering wxEraseEvent (unused).
         */
        void onEraseBackground(wxEraseEvent &event);
        
        /**
         * Called to paint this PasswordPanel.
         *
         * @param event The triggering wxPaintEvent (unused).
         */
        void onPaint(wxPaintEvent &event);
        
    public:
        /**
         * Creates a new PasswordPanel.
         */
        PasswordPanel();
    
        /**
         * Sets the password string drawn by this PasswordPanel.
         *
         * @param password The password.
         */
        void setPassword(const Password *password);
    };
    
    inline void PasswordPanel::setPassword(const Password *password)
        { this->password = password; }
    inline void PasswordPanel::onEraseBackground(wxEraseEvent &) {}
}

#endif

