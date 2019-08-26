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
 
// $Id: PasswordTextCtrl.cc,v 1.8 2007/02/20 19:27:17 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/clipbrd.h>

#include "view/MPGFrame.hh"
#include "view/PasswordTextCtrl.hh"

using namespace mpg;

wxString PasswordTextCtrl::GetValue() const {
    wxString temp = wxTextCtrl::GetValue();
    
    return wxString(temp.Mid(0, 6) + temp.Mid(7, 6) +
                     temp.Mid(14, 6) + temp.Mid(21));
}

void PasswordTextCtrl::SetValue(const wxString &value) {
    wxString text;
    
    // separate the password segments with spaces
    for (unsigned int i = 0; i < PASSWORD_LENGTH; ++i) {
        if ((i > 0) && ((i % 6) == 0)) {
            text += wxT(' ');
        }
        
        text += value[i];
    }
    
    wxTextCtrl::SetValue(text);
}

void PasswordTextCtrl::Paste() {
    if (wxTheClipboard->Open()) {
        if (wxTheClipboard->IsSupported(wxDF_TEXT)) {
            wxTextDataObject data;
            wxTheClipboard->GetData(data);
            
            wxString text = data.GetText();
            text.Replace(wxT(" "), wxT(""));
            
            int pos = GetInsertionPoint();
            int retPos = pos;
            text = text.Truncate(27 - pos);
            
            if (pos >= 21) {
                pos -= 3;
            } else if (pos >= 14) {
                pos -= 2;
            } else if (pos >= 7) {
                --pos;
            }
            
            int len = text.Length();            
            wxString value = GetValue();
            wxString temp;
            
            if (pos == 0) {
                temp += text;
                temp += value.Mid(len);
            } else {
                temp += value.Mid(0, pos);
                temp += text;
                temp += value.Mid(pos + len);
            }
            
            SetValue(temp);
            SetInsertionPoint(retPos);
        }
        
        wxTheClipboard->Close();
    }
}

void PasswordTextCtrl::Replace(long from, long to, const wxString &value) {
    #ifdef __WXMAC__
        wxString text = wxTextCtrl::GetValue();
        
        for (int i = from, count = 0; i < to; i++, count++) {
            text[i] = value[count];
        }
        
        wxTextCtrl::SetValue(text);
    #else
        wxTextCtrl::Replace(from, to, value);
    #endif
}

void PasswordTextCtrl::onChar(wxKeyEvent &event) {
    long key = event.m_keyCode;
    int pos = GetInsertionPoint();
    
    if (key == WXK_LEFT) {
        if ((pos == 7) || (pos == 14) || (pos == 21)) {
            pos -= 2;
        } else if (pos != 0) {
            --pos;
        }
        
        SetInsertionPoint(pos);
    } else if (key == WXK_RIGHT) {
        if ((pos == 5) || (pos == 12) || (pos == 19)) {
            pos += 2;
        } else if (pos != 27) {
            ++pos;
        }
        
        SetInsertionPoint(pos);
    } else if (key == WXK_BACK) {
        if ((pos == 7) || (pos == 14) || (pos == 21)) {
            --pos;
        }
        
        if (pos > 0) {
            Replace(pos - 1, pos, wxT(' '));
            SetInsertionPoint(pos - 1);
        }
    } else if (key == WXK_DELETE) {
        if (pos < 27) {
            Replace(pos, pos + 1, wxT(' '));
            SetInsertionPoint(pos);
        }
    } else if ( ((key >= '0') && (key <= '9')) ||
                ((key >= 'A') && (key <= 'Z')) ||
                ((key >= 'a') && (key <= 'z')) ||
                (key == '?') || (key == '-') || (key == WXK_SPACE)
              ) {
        // The legitimite Metroid alphabet
        if (event.AltDown()) {
            // skip menu accelerators
            event.Skip();
        } else if (pos < 27) {
            wxString text = wxTextCtrl::GetValue();
            wxChar ch = static_cast<wxChar>(key);
            
            if ((pos == 6) || (pos == 13) || (pos == 20)) {
                ++pos;
            }
            
            if (text[pos] != ch) {
                Replace(pos, pos + 1, ch);
            }
            
            if ((pos == 5) || (pos == 12) || (pos == 19)) {
                ++pos;
            }
            
            SetInsertionPoint(pos + 1);
        }
    } else if ((key < WXK_SPACE) || (key > WXK_START)) {
        // don't filter special keys
        event.Skip();
    }
}

void PasswordTextCtrl::onKeyDown(wxKeyEvent &event) {
    if (event.m_keyCode == WXK_DELETE) {
        long from, to;
        GetSelection(&from, &to);
        
        if (from != to) {
            Replace(from, to, wxString(wxT(' '), (to - from)));
            SetInsertionPoint(from);
        } else {
            event.Skip();
        }
    } else if ((event.m_keyCode == 'V') && (event.CmdDown())) {
        Paste();
    } else {
        event.Skip();
    }
}

IMPLEMENT_DYNAMIC_CLASS(PasswordTextCtrl, wxTextCtrl)

BEGIN_EVENT_TABLE(PasswordTextCtrl, wxTextCtrl)
    EVT_CHAR(PasswordTextCtrl::onChar)
    EVT_KEY_DOWN(PasswordTextCtrl::onKeyDown)
END_EVENT_TABLE()

