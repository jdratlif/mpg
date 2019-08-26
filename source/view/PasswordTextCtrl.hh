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
 
// $Id: PasswordTextCtrl.hh,v 1.3 2005/09/30 10:01:46 technoplaza Exp $

#ifndef _PASSWORDTEXTCTRL_HH_
#define _PASSWORDTEXTCTRL_HH_

namespace mpg {
    /// Custom text control used to enter Metroid passwords
    class PasswordTextCtrl : public wxTextCtrl {
        DECLARE_DYNAMIC_CLASS(PasswordTextCtrl)
        DECLARE_EVENT_TABLE()
        
    private:
        /**
         * Called when a char is typed into this PasswordTextCtrl.
         *
         * @param event The triggering wxKeyEvent.
         */
        void onChar(wxKeyEvent &event);
        
        /**
         * Called when a key is pressed in this PasswordTextCtrl.
         *
         * @param event The triggering wxKeyEvent.
         */
        void onKeyDown(wxKeyEvent &event);
        
    public:
        /**
         * Gets the password text, sans spaces.
         *
         * @return The password text.
         */
        wxString GetValue() const;
        
        /**
         * Sets the password text, inserting the segment separators.
         *
         * @param value The password text.
         */
        virtual void SetValue(const wxString &value);
        
        /**
         * Pastes the contents of the Clipboard onto this PasswordTextCtrl.
         */
        virtual void Paste();
        
        /**
         * Replaces a section of this PasswordTextCtrl with a new value.
         *
         * @param from The position to start replacing at.
         * @param to The position to replace up to (but not including).
         * @param value The string to replace with.
         */
        virtual void Replace(long from, long to, const wxString &value);
    };
}

#endif

