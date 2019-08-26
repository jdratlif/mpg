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
 
// $Id: PasswordPanel.cc,v 1.2 2005/09/27 09:06:12 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/dcbuffer.h>

#include "model/Password.hh"
#include "res/alphabet.xpm"
#include "view/PasswordPanel.hh"

using namespace mpg;

BEGIN_EVENT_TABLE(PasswordPanel, wxPanel)
    EVT_ERASE_BACKGROUND(PasswordPanel::onEraseBackground)
    EVT_PAINT(PasswordPanel::onPaint)
END_EVENT_TABLE()

PasswordPanel::PasswordPanel() : alphabet(alphabet_xpm), password(NULL) {}

wxPoint PasswordPanel::getLetterPos(wxChar letter) const {
    int index = Password::ALPHABET.Find(letter);
    
    return wxPoint(((index % CHARS_PER_ROW) * CHAR_WIDTH * 2),
                   ((index / CHARS_PER_ROW) * CHAR_HEIGHT * 2));
}

void PasswordPanel::onPaint(wxPaintEvent &) {
    wxBufferedPaintDC dc(this);
    
    dc.SetBackground(wxBrush(GetBackgroundColour()));
    dc.Clear();
    
    if (password) {
        wxMemoryDC xpm;
        xpm.SelectObject(alphabet);
        const wxString &encoded = password->getEncoded();
        
        // offset display at (8,8)
        wxPoint pos(START_X, START_Y);
        
        // two rows
        for (int row = 0; row < 2; ++row) {
            // of 12 password character
            for (int col = 0; col < 12; ++col) {
                // separated in the middle with a space
                if (col == 6) {
                    pos.x += CHAR_WIDTH;
                }
                
                // (row * 12) + col = [0, 23]
                wxPoint letter = getLetterPos(encoded[(row * 12) + col]);
                dc.Blit(pos.x, pos.y, CHAR_WIDTH, CHAR_HEIGHT,
                        &xpm, letter.x, letter.y);
                
                pos.x += CHAR_WIDTH;
            }
            
            pos.x = START_X;
            pos.y = START_Y + (2 * CHAR_HEIGHT);
        }
    }
}

IMPLEMENT_DYNAMIC_CLASS(PasswordPanel, wxPanel)

