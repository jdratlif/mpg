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
 
// $Id: MPGFrame.hh,v 1.36 2008/12/17 00:23:12 jdratlif Exp $

#ifndef MPG_MPGFRAME_HH_
#define MPG_MPGFRAME_HH_

#include <wx/spinctrl.h>

#include "model/Password.hh"

namespace mpg {
    class PasswordPanel;
    
    /// The main application frame
    class MPGFrame : public wxFrame {
        DECLARE_CLASS(MPGFrame)
        DECLARE_EVENT_TABLE()
        
    private:
        wxButton *fixChecksumButton;
        Password password;
        bool ignoreTextEvent, pal;
        
        enum {
            BRINSTAR, KRAIDSLAIR, NORFAIR, RIDLEYSLAIR, TOURIAN
        };
    
        /**
         * Creates the controls for this MPGFrame.
         */
        void CreateControls();
        
        /**
         * Updates all the controls based on the current password data.
         */
        void updateControls();
        
        /**
         * Updates the text password when the password data has changed.
         *
         * @param updateCtrl true to update the text control value; false
         *                   otherwise.
         */
        void updatePasswordText(bool updateCtrl = true);
        
        /**
         * Updates the raw game time bits.
         *
         * @param value The game time value.
         */
        void updateRawGameTime(wxUint32 value);
        
        /**
         * Updates the raw missile bits.
         *
         * @param value The missile count value.
         */
        void updateRawMissiles(unsigned char value);
        
        /**
         * Updates the approximate real time label.
         */
        void updateRealTime();
        
        /**
         * Updates the start location radio box control.
         */
        void updateStartLocation();
        
        /**
         * Updates the sizes for the text controls so they are wide enough.
         */
        void updateTextCtrlSizes();
        
        /**
         * Warns the user about the debug password.
         *
         * @param password The password string.
         */
        void warnOnDebugPassword(const wxString &password);
        
        /**
         * Called when Samus's armor is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onArmorChanged(wxCommandEvent &event);
        
        /**
         * Called when a boss checkbox is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onBossChanged(wxCommandEvent &event);
        
        /**
         * Called when a shift value from the checksum menu is selected.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onChecksumShift(wxCommandEvent &event);
        
        /**
         * Called when a door checkbox is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onDoorChanged(wxCommandEvent &event);
        
        /**
         * Called when an energy tank checkbox is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onEnergyTankChanged(wxCommandEvent &event);
        
        /**
         * Called when exit is selected from the file menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onFileExit(wxCommandEvent &event);
        
        /**
         * Called when the fix checksum button is pressed.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onFixChecksum(wxCommandEvent &event);
        
        /**
         * Called when NTSC or PAL is selected from the game menu.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onGameSystem(wxCommandEvent &event);
        
        /**
         * Called when the game time is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onGameTimeChanged(wxCommandEvent &event);
        
        /**
         * Called when about from the help menu is selected.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onHelpAbout(wxCommandEvent &event);
        
        /**
         * Called when an item checkbox is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onItemChanged(wxCommandEvent &event);
        
        /**
         * Called when a missile container checkbox is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onMissileContainerChanged(wxCommandEvent &event);
        
        /**
         * Called when the missile count spin button is pressed.
         *
         * @param event The triggering wxSpinEvent.
         */
        void onMissilesSpinner(wxSpinEvent &event);
        
        /**
         * Called when the missile count text is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onMissilesTextChanged(wxCommandEvent &event);
        
        /**
         * Called when the metroid password is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onPasswordChanged(wxCommandEvent &event);
        
        /**
         * Called when debug password from the password menu is selected.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordDebugPassword(wxCommandEvent &event);
        
        /**
         * Called when an ending is selected from the password menu.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onPasswordEnding(wxCommandEvent &event);
        
        /**
         * Called when bosses is selected from the password's give menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveBosses(wxCommandEvent &event);
        
        /**
         * Called when doors is selected from the password's give menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveDoors(wxCommandEvent &event);
        
        /**
         * Called when energy tanks is selected from the password's give menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveEnergyTanks(wxCommandEvent &event);
        
        /**
         * Called when items is selected from the password's give menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveItems(wxCommandEvent &event);
        
        /**
         * Called when missiles is selected from the password's give menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveMissiles(wxCommandEvent &event);
        
        /**
         * Called when missile containers is selected from the password's give
         * menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveMissileContainers(wxCommandEvent &event);
        
        /**
         * Called when statues is selected from the password's give menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveStatues(wxCommandEvent &event);
        
        /**
         * Called when zebetites is selected from the password's give menu.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordGiveZebetites(wxCommandEvent &event);
        
        /**
         * Called when perfect game from the password menu is selected.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onPasswordPerfectGame(wxCommandEvent &event);
        
        /**
         * Called when reset from the password menu is selected.
         *
         * @param event The triggerin wxCommandEvent (unused).
         */
        void onPasswordReset(wxCommandEvent &event);
        
        /**
         * Called when on of the bits in the raw bitlist is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onRawBitChanged(wxCommandEvent &event);
        
        /**
         * Called when the shift spin button is pressed.
         *
         * @param event The triggering wxSpinEvent.
         */
        void onShiftSpinner(wxSpinEvent &event);
        
        /**
         * Called when the shift text value is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onShiftTextChanged(wxCommandEvent &event);
        
        /**
         * Called when the start location is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onStartLocationChanged(wxCommandEvent &event);
        
        /**
         * Called when a statue checkbox is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onStatueChanged(wxCommandEvent &event);
        
        /**
         * Called when a zebetite checkbox is changed.
         *
         * @param event The triggering wxCommandEvent.
         */
        void onZebetiteChanged(wxCommandEvent &event);
        
    public:
        /**
         * Creates a new MPGFrame.
         */
        MPGFrame();
    };
    
    inline void MPGFrame::onFileExit(wxCommandEvent &) { Close(); }
}

#endif

