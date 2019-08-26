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
 
// $Id: MPGFrame.cc,v 1.30 2005/09/28 01:46:23 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/xrc/xmlres.h>

#include "AppConstants.hh"
#include "exceptions/InvalidPasswordException.hh"
#include "res/icon32x32.xpm"
#include "view/MPGFrame.hh"
#include "view/PasswordPanel.hh"

using namespace mpg;

BEGIN_EVENT_TABLE(MPGFrame, wxFrame)
    EVT_BUTTON(XRCID("IDB_CHECKSUM"), MPGFrame::onFixChecksum)

    EVT_CHECKBOX(XRCID("IDC_ITEMS_MARUMARI"), MPGFrame::onItemChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_LONGBEAM"), MPGFrame::onItemChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_WAVEBEAM"), MPGFrame::onItemChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ICEBEAM"), MPGFrame::onItemChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_BOMBS"), MPGFrame::onItemChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_HIGHJUMPBOOTS"), MPGFrame::onItemChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_SCREWATTACK"), MPGFrame::onItemChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_VARIA"), MPGFrame::onItemChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_BS1"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_BS2"), MPGFrame::onMissileContainerChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_KL1"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_KL2"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_KL3"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_KL4"), MPGFrame::onMissileContainerChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF1"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF2"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF3"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF4"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF5"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF6"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF7"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF8"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF9"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF10"), 
                 MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF11"),
                 MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_NF12"),
                 MPGFrame::onMissileContainerChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_RL1"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_RL2"), MPGFrame::onMissileContainerChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_MC_RL3"), MPGFrame::onMissileContainerChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_BS1"), MPGFrame::onEnergyTankChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_BS2"), MPGFrame::onEnergyTankChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_BS3"), MPGFrame::onEnergyTankChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_NF"), MPGFrame::onEnergyTankChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_KL"), MPGFrame::onEnergyTankChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_KL_KRAID"), MPGFrame::onEnergyTankChanged)
    
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_RL"), MPGFrame::onEnergyTankChanged)
    EVT_CHECKBOX(XRCID("IDC_ITEMS_ET_RL_RIDLEY"), MPGFrame::onEnergyTankChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_BS_LONGBEAM"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_BS_TOURIANBRIDGE"),
                 MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_BS_BOMBS"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_BS_ICEBEAM"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_BS_VARIA"), MPGFrame::onDoorChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_KL1"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_KL2"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_KL3"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_KL4"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_KL_KRAID"), MPGFrame::onDoorChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_NF_HIGHJUMPBOOTS"),
                 MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_NF_SCREWATTACK"),
                 MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_NF_WAVEBEAM"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_NF_ICEBEAM"), MPGFrame::onDoorChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_RL"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_RL_RIDLEY"), MPGFrame::onDoorChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_T1"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_T2"), MPGFrame::onDoorChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_DOORS_T3"), MPGFrame::onDoorChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_STATUE_KRAID"), MPGFrame::onStatueChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_STATUE_RIDLEY"), MPGFrame::onStatueChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_ZEBETITE1"), MPGFrame::onZebetiteChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_ZEBETITE2"), MPGFrame::onZebetiteChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_ZEBETITE3"), MPGFrame::onZebetiteChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_ZEBETITE4"), MPGFrame::onZebetiteChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_ZEBETITE5"), MPGFrame::onZebetiteChanged)
    
    EVT_CHECKBOX(XRCID("IDC_MISC_BOSS_KRAID"), MPGFrame::onBossChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_BOSS_RIDLEY"), MPGFrame::onBossChanged)
    EVT_CHECKBOX(XRCID("IDC_MISC_BOSS_MOTHERBRAIN"), MPGFrame::onBossChanged)
    
    EVT_CHECKLISTBOX(XRCID("IDCLB_RAW_BITS"), MPGFrame::onRawBitChanged)
    
    EVT_MENU(wxID_EXIT, MPGFrame::onFileExit)
    
    EVT_MENU(XRCID("IDM_PASSWORD_PERFECTGAME"),
        MPGFrame::onPasswordPerfectGame)
    EVT_MENU(XRCID("IDM_PASSWORD_DEBUGPASSWORD"),
        MPGFrame::onPasswordDebugPassword)
    EVT_MENU(XRCID("IDM_PASSWORD_RESET"), MPGFrame::onPasswordReset)
    
    EVT_MENU(XRCID("IDM_PASSWORD_ENDING1"), MPGFrame::onPasswordEnding)
    EVT_MENU(XRCID("IDM_PASSWORD_ENDING2"), MPGFrame::onPasswordEnding)
    EVT_MENU(XRCID("IDM_PASSWORD_ENDING3"), MPGFrame::onPasswordEnding)
    EVT_MENU(XRCID("IDM_PASSWORD_ENDING4"), MPGFrame::onPasswordEnding)
    EVT_MENU(XRCID("IDM_PASSWORD_ENDING5"), MPGFrame::onPasswordEnding)
    
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_MISSILES"),
        MPGFrame::onPasswordGiveMissiles)
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_ITEMS"), MPGFrame::onPasswordGiveItems)
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_MC"),
        MPGFrame::onPasswordGiveMissileContainers)
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_ET"),
        MPGFrame::onPasswordGiveEnergyTanks)
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_DOORS"), MPGFrame::onPasswordGiveDoors)
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_STATUES"),
        MPGFrame::onPasswordGiveStatues)
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_ZEBETITES"),
        MPGFrame::onPasswordGiveZebetites)
    EVT_MENU(XRCID("IDM_PASSWORD_GIVE_BOSSES"), MPGFrame::onPasswordGiveBosses)
    
    EVT_MENU(wxID_ABOUT, MPGFrame::onHelpAbout)
    
    EVT_RADIOBOX(XRCID("IDRB_MISC_START"), MPGFrame::onStartLocationChanged)
    EVT_RADIOBOX(XRCID("IDRB_MISC_ARMOR"), MPGFrame::onArmorChanged)
    
    EVT_TEXT(XRCID("IDSC_ITEMS_MISSILES"), MPGFrame::onMissilesTextChanged)
    EVT_TEXT(XRCID("IDT_MISC_GAMETIME"), MPGFrame::onGameTimeChanged)
    EVT_TEXT(XRCID("IDSC_RAW_SHIFT"), MPGFrame::onShiftTextChanged)
    EVT_TEXT(XRCID("IDT_PASSWORD"), MPGFrame::onPasswordChanged)
END_EVENT_TABLE()

MPGFrame::MPGFrame() : fixChecksumButton(NULL), ignoreTextEvent(true) {
    SetParent(NULL);
    
    CreateControls();
    GetSizer()->SetSizeHints(this);
    Centre();
}

void MPGFrame::CreateControls() {
    wxXmlResource::Get()->LoadFrame(this, GetParent(), wxT("IDF_MPG"));
    SetIcon(wxIcon(icon32x32_xpm));
    
    XRCCTRL(*this, "IDP_PASSWORD", PasswordPanel)->setPassword(&password);
    XRCCTRL(*this, "IDT_PASSWORD", wxTextCtrl)->SetMaxLength(27);
    
    wxTextCtrl *gameTime = XRCCTRL(*this, "IDT_MISC_GAMETIME", wxTextCtrl);
    gameTime->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
    gameTime->SetMaxLength(10);
    
    fixChecksumButton = XRCCTRL(*this, "IDB_CHECKSUM", wxButton);
    
    updateTextCtrlSizes();
    
    ignoreTextEvent = false;
}

wxString MPGFrame::getUnifiedPassword() const {
    wxString temp = XRCCTRL(*this, "IDT_PASSWORD", wxTextCtrl)->GetValue();
    
    if (temp.Length() != 27) {
        return wxEmptyString;
    }
    
    return wxString(temp.Mid(0, 6) + temp.Mid(7, 6) +
                     temp.Mid(14, 6) + temp.Mid(21));
}

void MPGFrame::updateControls() {
    // update the item controls
    XRCCTRL(*this, "IDC_ITEMS_MARUMARI",
            wxCheckBox)->SetValue(password.getBit(MARUMARI) &&
                                  password.getBit(MARUMARI_TAKEN));
    XRCCTRL(*this, "IDC_ITEMS_LONGBEAM",
            wxCheckBox)->SetValue(password.getBit(LONGBEAM));
    XRCCTRL(*this, "IDC_ITEMS_WAVEBEAM",
            wxCheckBox)->SetValue(password.getBit(WAVEBEAM));
    XRCCTRL(*this, "IDC_ITEMS_ICEBEAM",
            wxCheckBox)->SetValue(password.getBit(ICEBEAM));
    XRCCTRL(*this, "IDC_ITEMS_BOMBS",
            wxCheckBox)->SetValue(password.getBit(BOMBS) &&
                                  password.getBit(BOMBS_TAKEN));
    XRCCTRL(*this, "IDC_ITEMS_HIGHJUMPBOOTS",
            wxCheckBox)->SetValue(password.getBit(HIGHJUMPBOOTS) &&
                                  password.getBit(HIGHJUMPBOOTS_TAKEN));
    XRCCTRL(*this, "IDC_ITEMS_SCREWATTACK",
            wxCheckBox)->SetValue(password.getBit(SCREWATTACK) &&
                                  password.getBit(SCREWATTACK_TAKEN));
    XRCCTRL(*this, "IDC_ITEMS_VARIA",
            wxCheckBox)->SetValue(password.getBit(VARIA) &&
                                  password.getBit(VARIA_TAKEN));
    
    // update the missile container controls
    XRCCTRL(*this, "IDC_ITEMS_MC_BS1",
            wxCheckBox)->SetValue(password.getBit(MISSILE_BS1));
    XRCCTRL(*this, "IDC_ITEMS_MC_BS2",
            wxCheckBox)->SetValue(password.getBit(MISSILE_BS2));
    
    XRCCTRL(*this, "IDC_ITEMS_MC_KL1",
            wxCheckBox)->SetValue(password.getBit(MISSILE_KL1));
    XRCCTRL(*this, "IDC_ITEMS_MC_KL2",
            wxCheckBox)->SetValue(password.getBit(MISSILE_KL2));
    XRCCTRL(*this, "IDC_ITEMS_MC_KL3",
            wxCheckBox)->SetValue(password.getBit(MISSILE_KL3));
    XRCCTRL(*this, "IDC_ITEMS_MC_KL4",
            wxCheckBox)->SetValue(password.getBit(MISSILE_KL4));
    
    XRCCTRL(*this, "IDC_ITEMS_MC_NF1",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF1));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF2",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF2));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF3",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF3));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF4",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF4));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF5",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF5));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF6",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF6));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF7",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF7));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF8",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF8));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF9",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF9));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF10",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF10));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF11",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF11));
    XRCCTRL(*this, "IDC_ITEMS_MC_NF12",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_NF12));
    
    XRCCTRL(*this, "IDC_ITEMS_MC_RL1",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_RL1));
    XRCCTRL(*this, "IDC_ITEMS_MC_RL2",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_RL2));
    XRCCTRL(*this, "IDC_ITEMS_MC_RL3",
		    wxCheckBox)->SetValue(password.getBit(MISSILE_RL3));
    
    // update the energy tank controls
    XRCCTRL(*this, "IDC_ITEMS_ET_BS1",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_BS1));
    XRCCTRL(*this, "IDC_ITEMS_ET_BS2",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_BS2));
    XRCCTRL(*this, "IDC_ITEMS_ET_BS3",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_BS3));
    
    XRCCTRL(*this, "IDC_ITEMS_ET_NF",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_NF));
    
    XRCCTRL(*this, "IDC_ITEMS_ET_KL",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_KL));
    XRCCTRL(*this, "IDC_ITEMS_ET_KL_KRAID",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_KL_KRAID));
    
    XRCCTRL(*this, "IDC_ITEMS_ET_RL",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_RL));
    XRCCTRL(*this, "IDC_ITEMS_ET_RL_RIDLEY",
		    wxCheckBox)->SetValue(password.getBit(ENERGYTANK_RL_RIDLEY));
    
    // update the red & yellow door controls
    XRCCTRL(*this, "IDC_MISC_DOORS_BS_LONGBEAM",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_BS_LONGBEAM));
    XRCCTRL(*this, "IDC_MISC_DOORS_BS_TOURIANBRIDGE",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_BS_TOURIANBRIDGE));
    XRCCTRL(*this, "IDC_MISC_DOORS_BS_BOMBS",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_BS_BOMBS));
    XRCCTRL(*this, "IDC_MISC_DOORS_BS_ICEBEAM",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_BS_ICEBEAM));
    XRCCTRL(*this, "IDC_MISC_DOORS_BS_VARIA",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_BS_VARIA));
    
    XRCCTRL(*this, "IDC_MISC_DOORS_KL1",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_KL1));
    XRCCTRL(*this, "IDC_MISC_DOORS_KL2",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_KL2));
    XRCCTRL(*this, "IDC_MISC_DOORS_KL3",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_KL3));
    XRCCTRL(*this, "IDC_MISC_DOORS_KL4",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_KL4));
    XRCCTRL(*this, "IDC_MISC_DOORS_KL_KRAID",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_KL_KRAID));
    
    XRCCTRL(*this, "IDC_MISC_DOORS_NF_HIGHJUMPBOOTS",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_NF_HIGHJUMPBOOTS));
    XRCCTRL(*this, "IDC_MISC_DOORS_NF_SCREWATTACK",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_NF_SCREWATTACK));
    XRCCTRL(*this, "IDC_MISC_DOORS_NF_WAVEBEAM",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_NF_WAVEBEAM));
    XRCCTRL(*this, "IDC_MISC_DOORS_NF_ICEBEAM",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_NF_ICEBEAM));
    
    XRCCTRL(*this, "IDC_MISC_DOORS_RL",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_RL));
    XRCCTRL(*this, "IDC_MISC_DOORS_RL_RIDLEY",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_RL_RIDLEY));
    
    XRCCTRL(*this, "IDC_MISC_DOORS_T1",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_T1));
    XRCCTRL(*this, "IDC_MISC_DOORS_T2",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_T2));
    XRCCTRL(*this, "IDC_MISC_DOORS_T3",
		    wxCheckBox)->SetValue(password.getBit(REDDOOR_T3));
    
    // update the statue controls
    XRCCTRL(*this, "IDC_MISC_STATUE_KRAID",
		    wxCheckBox)->SetValue(password.getBit(KRAID_STATUE));
    XRCCTRL(*this, "IDC_MISC_STATUE_RIDLEY",
		    wxCheckBox)->SetValue(password.getBit(RIDLEY_STATUE));
    
    // update the zebetite controls
    XRCCTRL(*this, "IDC_MISC_ZEBETITE1",
		    wxCheckBox)->SetValue(password.getBit(ZEBETITE1));
    XRCCTRL(*this, "IDC_MISC_ZEBETITE2",
		    wxCheckBox)->SetValue(password.getBit(ZEBETITE2));
    XRCCTRL(*this, "IDC_MISC_ZEBETITE3",
		    wxCheckBox)->SetValue(password.getBit(ZEBETITE3));
    XRCCTRL(*this, "IDC_MISC_ZEBETITE4",
		    wxCheckBox)->SetValue(password.getBit(ZEBETITE4));
    XRCCTRL(*this, "IDC_MISC_ZEBETITE5",
		    wxCheckBox)->SetValue(password.getBit(ZEBETITE5));
    
    // update the boss controls
    XRCCTRL(*this, "IDC_MISC_BOSS_KRAID",
		    wxCheckBox)->SetValue(password.getBit(KRAID));
    XRCCTRL(*this, "IDC_MISC_BOSS_RIDLEY",
		    wxCheckBox)->SetValue(password.getBit(RIDLEY));
    XRCCTRL(*this, "IDC_MISC_BOSS_MOTHERBRAIN",
		    wxCheckBox)->SetValue(password.getBit(MOTHERBRAIN));
    
    // update the armor control
    XRCCTRL(*this, "IDRB_MISC_ARMOR",
            wxRadioBox)->SetSelection(password.getBit(SWIMSUIT) ? 1 : 0);
    
    // update the missile count, gametime, and shift byte controls
    unsigned long value = static_cast<unsigned long>(password.getGameTime());
    
    ignoreTextEvent = true;
    XRCCTRL(*this, "IDSC_ITEMS_MISSILES",
            wxSpinCtrl)->SetValue(password.getMissiles());
    XRCCTRL(*this, "IDT_MISC_GAMETIME",
            wxTextCtrl)->SetValue(wxString::Format(wxT("%lu"), value));
    XRCCTRL(*this, "IDSC_RAW_SHIFT",
            wxSpinCtrl)->SetValue(password.getShift());
    ignoreTextEvent = false;
    
    // update the start location
    updateStartLocation();
    
    // update the raw password data control
    for (int i = 0; i < PASSWORD_BITS; ++i) {
        XRCCTRL(*this, "IDCLB_RAW_BITS",
                wxCheckListBox)->Check(i, password.getBit(i));
    }
    
    // warn about invalid passwords due to reset bit
    if (password.getBit(RESET)) {
        wxMessageBox(wxT("This password is invalid: reset bit is set"),
                     wxT("Warning: Invalid Password"),
                     wxICON_EXCLAMATION | wxOK);
    }
}

void MPGFrame::updatePasswordText() {
    wxTextCtrl *ctrl = XRCCTRL(*this, "IDT_PASSWORD", wxTextCtrl);
    wxString text;
    
    // separate the password segments with spaces
    for (unsigned int i = 0; i < PASSWORD_LENGTH; ++i) {
        if ((i > 0) && ((i % 6) == 0)) {
            text += wxT(' ');
        }
        
        text += password.getEncoded()[i];
    }
    
    ignoreTextEvent = true;
    ctrl->SetValue(text);
    ignoreTextEvent = false;
    
    XRCCTRL(*this, "IDP_PASSWORD", PasswordPanel)->Refresh(false);
    
    // warn if they have entered the debug password
    if (password.getEncoded().StartsWith(wxT("NARPASSWORD00000"))) {
        wxMessageBox(wxT("This password triggers debug mode.\n"
                         "Because it is Hard Coded, any change will disable "
                         "debug mode effects."),
                     wxT("Debug Password"), wxICON_EXCLAMATION | wxOK);
    }
}

void MPGFrame::updateRawGameTime(wxUint32 value) {
    wxCheckListBox *ctrl = XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox);
    
    for (int i = 0; i < 32; ++i) {
        ctrl->Check(GAMETIME + i, (value & (1 << i)));
    }
}

void MPGFrame::updateRawMissiles(unsigned char value) {
    wxCheckListBox *ctrl = XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox);
    
    for (int i = 0; i < 8; ++i) {
        ctrl->Check(MISSILES + i, (value & (1 << i)));
    }
}

void MPGFrame::updateStartLocation() {
    bool nf = password.getBit(START_NF);
    bool kl = password.getBit(START_KL);
    bool rl = password.getBit(START_RL);
    
    wxRadioBox *ctrl = XRCCTRL(*this, "IDRB_MISC_START", wxRadioBox);
    
    if (!nf && !kl && !rl) {
        // Brinstar
        ctrl->SetSelection(BRINSTAR);
    } else if (!nf && kl && !rl) {
        // Kraid's Lair
        ctrl->SetSelection(KRAIDSLAIR);
    } else if (nf && !kl && !rl) {
        // Norfair
        ctrl->SetSelection(NORFAIR);
    } else if (!nf && !kl && rl) {
        // Ridley's Lair
        ctrl->SetSelection(RIDLEYSLAIR);
    } else if (nf && kl && !rl) {
        // Tourian
        ctrl->SetSelection(TOURIAN);
    } else {
        // invalid start location
        wxMessageBox(wxT("This password has an invalid start location."),
                     wxT("Warning: Invalid Password"),
                     wxICON_EXCLAMATION | wxOK);
    }
}

void MPGFrame::updateTextCtrlSizes() {
    wxClientDC dc(this);
    wxTextCtrl *ctrl;
    wxCoord width, height;
    
    ctrl = XRCCTRL(*this, "IDT_MISC_GAMETIME", wxTextCtrl);
    dc.SetFont(ctrl->GetFont());
    dc.GetTextExtent(wxT("04294967296"), &width, &height);
    
    wxSize size(width + 15, height + 5);
    ctrl->SetSize(size);
    ctrl->SetMinSize(size);
    ctrl->SetMaxSize(size);
    
    ctrl = XRCCTRL(*this, "IDT_PASSWORD", wxTextCtrl);
    dc.SetFont(ctrl->GetFont());
    dc.GetTextExtent(ctrl->GetValue(), &width, &height);
    
    size = wxSize(width + 15, height + 5);
    ctrl->SetSize(size);
    ctrl->SetMinSize(size);
    ctrl->SetMaxSize(size);
}

void MPGFrame::onArmorChanged(wxCommandEvent &event) {
    wxRadioBox *ptr = dynamic_cast<wxRadioBox *>(event.GetEventObject());
    bool state = (ptr->GetSelection() == 1);
    
    XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox)->Check(SWIMSUIT, state);
    password.setBit(SWIMSUIT, state);
    
    updatePasswordText();
}

void MPGFrame::onBossChanged(wxCommandEvent &event) {
    int id = event.GetId();
    bool state = event.IsChecked();
    int bit;
    
    if (id == XRCID("IDC_MISC_BOSS_KRAID")) {
        bit = KRAID;
    } else if (id == XRCID("IDC_MISC_BOSS_RIDLEY")) {
        bit = RIDLEY;
    } else {
        bit = MOTHERBRAIN;
    }
    
    XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox)->Check(bit, state);
    password.setBit(bit, state);
    
    updatePasswordText();
}

void MPGFrame::onDoorChanged(wxCommandEvent &event) {
    int id = event.GetId();
    bool state = event.IsChecked();
    int bit;
    
    if (id == XRCID("IDC_MISC_DOORS_BS_LONGBEAM")) {
        bit = REDDOOR_BS_LONGBEAM;
    } else if (id == XRCID("IDC_MISC_DOORS_BS_TOURIANBRIDGE")) {
        bit = REDDOOR_BS_TOURIANBRIDGE;
    } else if (id == XRCID("IDC_MISC_DOORS_BS_BOMBS")) {
        bit = REDDOOR_BS_BOMBS;
    } else if (id == XRCID("IDC_MISC_DOORS_BS_ICEBEAM")) {
        bit = REDDOOR_BS_ICEBEAM;
    } else if (id == XRCID("IDC_MISC_DOORS_BS_VARIA")) {
        bit = REDDOOR_BS_VARIA;
    } else if (id == XRCID("IDC_MISC_DOORS_KL1")) {
        bit = REDDOOR_KL1;
    } else if (id == XRCID("IDC_MISC_DOORS_KL2")) {
        bit = REDDOOR_KL2;
    } else if (id == XRCID("IDC_MISC_DOORS_KL3")) {
        bit = REDDOOR_KL3;
    } else if (id == XRCID("IDC_MISC_DOORS_KL4")) {
        bit = REDDOOR_KL4;
    } else if (id == XRCID("IDC_MISC_DOORS_KL_KRAID")) {
        bit = REDDOOR_KL_KRAID;
    } else if (id == XRCID("IDC_MISC_DOORS_NF_HIGHJUMPBOOTS")) {
        bit = REDDOOR_NF_HIGHJUMPBOOTS;
    } else if (id == XRCID("IDC_MISC_DOORS_NF_SCREWATTACK")) {
        bit = REDDOOR_NF_SCREWATTACK;
    } else if (id == XRCID("IDC_MISC_DOORS_NF_WAVEBEAM")) {
        bit = REDDOOR_NF_WAVEBEAM;
    } else if (id == XRCID("IDC_MISC_DOORS_NF_ICEBEAM")) {
        bit = REDDOOR_NF_ICEBEAM;
    } else if (id == XRCID("IDC_MISC_DOORS_RL")) {
        bit = REDDOOR_RL;
    } else if (id == XRCID("IDC_MISC_DOORS_RL_RIDLEY")) {
        bit = REDDOOR_RL_RIDLEY;
    } else if (id == XRCID("IDC_MISC_DOORS_T1")) {
        bit = REDDOOR_T1;
    } else if (id == XRCID("IDC_MISC_DOORS_T2")) {
        bit = REDDOOR_T2;
    } else {
        bit = REDDOOR_T3;
    }
    
    XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox)->Check(bit, state);
    password.setBit(bit, state);
    
    updatePasswordText();
}

void MPGFrame::onEnergyTankChanged(wxCommandEvent &event) {
    int id = event.GetId();
    bool state = event.IsChecked();
    int bit;
    
    if (id == XRCID("IDC_ITEMS_ET_BS1")) {
        bit = ENERGYTANK_BS1;
    } else if (id == XRCID("IDC_ITEMS_ET_BS2")) {
        bit = ENERGYTANK_BS2;
    } else if (id == XRCID("IDC_ITEMS_ET_BS3")) {
        bit = ENERGYTANK_BS3;
    } else if (id == XRCID("IDC_ITEMS_ET_NF")) {
        bit = ENERGYTANK_NF;
    } else if (id == XRCID("IDC_ITEMS_ET_KL")) {
        bit = ENERGYTANK_KL;
    } else if (id == XRCID("IDC_ITEMS_ET_KL_KRAID")) {
        bit = ENERGYTANK_KL_KRAID;
    } else if (id == XRCID("IDC_ITEMS_ET_RL")) {
        bit = ENERGYTANK_RL;
    } else {
        bit = ENERGYTANK_RL_RIDLEY;
    }
    
    XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox)->Check(bit, state);
    password.setBit(bit, state);
    
    updatePasswordText();
}

void MPGFrame::onFixChecksum(wxCommandEvent &) {
    password = Password(getUnifiedPassword(), true);
    updatePasswordText();
    updateControls();
}

void MPGFrame::onGameTimeChanged(wxCommandEvent &event) {
    if (ignoreTextEvent) {
        return;
    }
    
    unsigned long value;
    
    if (event.GetString().ToULong(&value)) {
        wxUint32 ticks = static_cast<wxUint32>(value);
        
        updateRawGameTime(ticks);
        password.setGameTime(ticks);
        
        updatePasswordText();
    }
}

void MPGFrame::onHelpAbout(wxCommandEvent &) {
    wxString message = APP_NAME + wxT(' ') + APP_VERSION + wxT('\n') +
                       APP_COPYRIGHT + wxT('\n') + APP_URL;
    wxString title = wxT("About ") + APP_NAME + wxT("...");
    
    wxMessageBox(message, title, wxICON_INFORMATION | wxOK);
}

void MPGFrame::onItemChanged(wxCommandEvent &event) {
    int id = event.GetId();
    bool state = event.IsChecked();
    int b1, b2 = -1;
    wxCheckListBox *ctrl = XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox);
    
    if (id == XRCID("IDC_ITEMS_MARUMARI")) {
        b1 = MARUMARI;
        b2 = MARUMARI_TAKEN;
    } else if (id == XRCID("IDC_ITEMS_LONGBEAM")) {
        b1 = LONGBEAM;
    } else if (id == XRCID("IDC_ITEMS_WAVEBEAM")) {
        b1 = WAVEBEAM;
        
        // can't use wave beam and ice beam simultaneously
        XRCCTRL(*this, "IDC_ITEMS_ICEBEAM", wxCheckBox)->SetValue(false);
        ctrl->Check(ICEBEAM, false);
        password.setBit(ICEBEAM, false);
    } else if (id == XRCID("IDC_ITEMS_ICEBEAM")) {
        b1 = ICEBEAM;
        
        // can't use wave beam and ice beam simultaneously
        XRCCTRL(*this, "IDC_ITEMS_WAVEBEAM", wxCheckBox)->SetValue(false);
        ctrl->Check(WAVEBEAM, false);
        password.setBit(WAVEBEAM, false);
    } else if (id == XRCID("IDC_ITEMS_BOMBS")) {
        b1 = BOMBS;
        b2 = BOMBS_TAKEN;
    } else if (id == XRCID("IDC_ITEMS_HIGHJUMPBOOTS")) {
        b1 = HIGHJUMPBOOTS;
        b2 = HIGHJUMPBOOTS_TAKEN;
    } else if (id == XRCID("IDC_ITEMS_SCREWATTACK")) {
        b1 = SCREWATTACK;
        b2 = SCREWATTACK_TAKEN;
    } else {
        b1 = VARIA;
        b2 = VARIA_TAKEN;
    }
    
    ctrl->Check(b1, state);
    password.setBit(b1, state);
    
    if (b2 != -1) {
        ctrl->Check(b2, state);
        password.setBit(b2, state);
    }
    
    updatePasswordText();
}

void MPGFrame::onMissileContainerChanged(wxCommandEvent &event) {
    int id = event.GetId();
    bool state = event.IsChecked();
    int bit;
    
    if (id == XRCID("IDC_ITEMS_MC_BS1")) {
        bit = MISSILE_BS1;
    } else if (id == XRCID("IDC_ITEMS_MC_BS2")) {
        bit = MISSILE_BS2;
    } else if (id == XRCID("IDC_ITEMS_MC_KL1")) {
        bit = MISSILE_KL1;
    } else if (id == XRCID("IDC_ITEMS_MC_KL2")) {
        bit = MISSILE_KL2;
    } else if (id == XRCID("IDC_ITEMS_MC_KL3")) {
        bit = MISSILE_KL3;
    } else if (id == XRCID("IDC_ITEMS_MC_KL4")) {
        bit = MISSILE_KL4;
    } else if (id == XRCID("IDC_ITEMS_MC_NF1")) {
        bit = MISSILE_NF1;
    } else if (id == XRCID("IDC_ITEMS_MC_NF2")) {
        bit = MISSILE_NF2;
    } else if (id == XRCID("IDC_ITEMS_MC_NF3")) {
        bit = MISSILE_NF3;
    } else if (id == XRCID("IDC_ITEMS_MC_NF4")) {
        bit = MISSILE_NF4;
    } else if (id == XRCID("IDC_ITEMS_MC_NF5")) {
        bit = MISSILE_NF5;
    } else if (id == XRCID("IDC_ITEMS_MC_NF6")) {
        bit = MISSILE_NF6;
    } else if (id == XRCID("IDC_ITEMS_MC_NF7")) {
        bit = MISSILE_NF7;
    } else if (id == XRCID("IDC_ITEMS_MC_NF8")) {
        bit = MISSILE_NF8;
    } else if (id == XRCID("IDC_ITEMS_MC_NF9")) {
        bit = MISSILE_NF9;
    } else if (id == XRCID("IDC_ITEMS_MC_NF10")) {
        bit = MISSILE_NF10;
    } else if (id == XRCID("IDC_ITEMS_MC_NF11")) {
        bit = MISSILE_NF11;
    } else if (id == XRCID("IDC_ITEMS_MC_NF12")) {
        bit = MISSILE_NF12;
    } else if (id == XRCID("IDC_ITEMS_MC_RL1")) {
        bit = MISSILE_RL1;
    } else if (id == XRCID("IDC_ITEMS_MC_RL2")) {
        bit = MISSILE_RL2;
    } else {
        bit = MISSILE_RL3;
    }
    
    XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox)->Check(bit, state);
    password.setBit(bit, state);
    
    updatePasswordText();
}

void MPGFrame::onMissilesTextChanged(wxCommandEvent &) {
    if (ignoreTextEvent) {
        return;
    }
    
    wxSpinCtrl *ctrl = XRCCTRL(*this, "IDSC_ITEMS_MISSILES", wxSpinCtrl);
    unsigned char value = static_cast<unsigned char>(ctrl->GetValue());
    
    password.setMissiles(value);
    
    updateRawMissiles(value);
    updatePasswordText();
}

void MPGFrame::onPasswordChanged(wxCommandEvent &) {
    if (fixChecksumButton) {
        fixChecksumButton->Enable(false);
    }
    
    if (ignoreTextEvent) {
        return;
    }
    
    wxString value = getUnifiedPassword();
                     
    try {
        password = Password(value);
        
        updatePasswordText();
        updateControls();
    } catch (InvalidPasswordException &e) {
        if (e.getError() == INVALID_CHECKSUM) {
            fixChecksumButton->Enable(true);
        }
    }
}

void MPGFrame::onPasswordDebugPassword(wxCommandEvent &) {  
    wxMessageBox(wxT("The debug password is NARPAS SWORD0 000000 000000\n"
                     "It is Hard Coded and cannot be edited."),
                 wxT("Debug Password"), wxICON_INFORMATION | wxOK);
}

void MPGFrame::onPasswordEnding(wxCommandEvent &event) {
    wxTextCtrl *ctrl = XRCCTRL(*this, "IDT_MISC_GAMETIME", wxTextCtrl);
    int id = event.GetId();
    
    if (id == XRCID("IDM_PASSWORD_ENDING1")) {
        ctrl->SetValue(wxT("0"));
    } else if (id == XRCID("IDM_PASSWORD_ENDING2")) {
        ctrl->SetValue(wxT("1024"));
    } else if (id == XRCID("IDM_PASSWORD_ENDING3")) {
        ctrl->SetValue(wxT("2560"));
    } else if (id == XRCID("IDM_PASSWORD_ENDING4")) {
        ctrl->SetValue(wxT("5632"));
    } else {
        ctrl->SetValue(wxT("31232"));
    }
}

void MPGFrame::onPasswordGiveBosses(wxCommandEvent &) {
    password.setBit(KRAID);
    password.setBit(RIDLEY);
    password.setBit(MOTHERBRAIN);
    
    updatePasswordText();
    updateControls();
}

void MPGFrame::onPasswordGiveDoors(wxCommandEvent &) {
    password.setBit(REDDOOR_BS_LONGBEAM);
    password.setBit(REDDOOR_BS_TOURIANBRIDGE);
    password.setBit(REDDOOR_BS_BOMBS);
    password.setBit(REDDOOR_BS_ICEBEAM);
    password.setBit(REDDOOR_BS_VARIA);
    
    password.setBit(REDDOOR_KL1);
    password.setBit(REDDOOR_KL2);
    password.setBit(REDDOOR_KL3);
    password.setBit(REDDOOR_KL4);
    password.setBit(REDDOOR_KL_KRAID);
    
    password.setBit(REDDOOR_NF_HIGHJUMPBOOTS);
    password.setBit(REDDOOR_NF_SCREWATTACK);
    password.setBit(REDDOOR_NF_WAVEBEAM);
    password.setBit(REDDOOR_NF_ICEBEAM);
    
    password.setBit(REDDOOR_RL);
    password.setBit(REDDOOR_RL_RIDLEY);
    
    password.setBit(REDDOOR_T1);
    password.setBit(REDDOOR_T2);
    password.setBit(REDDOOR_T3);
    
    updatePasswordText();
    updateControls();
}

void MPGFrame::onPasswordGiveEnergyTanks(wxCommandEvent &) {
    password.setBit(ENERGYTANK_BS1);
    password.setBit(ENERGYTANK_BS2);
    password.setBit(ENERGYTANK_BS3);
    
    password.setBit(ENERGYTANK_NF);
    
    password.setBit(ENERGYTANK_KL);
    password.setBit(ENERGYTANK_KL_KRAID);
    
    password.setBit(ENERGYTANK_RL);
    password.setBit(ENERGYTANK_RL_RIDLEY);
    
    updatePasswordText();
    updateControls();
}

void MPGFrame::onPasswordGiveItems(wxCommandEvent &) {
    password.setBit(MARUMARI);
    password.setBit(MARUMARI_TAKEN);
    
    password.setBit(LONGBEAM);
    password.setBit(WAVEBEAM, false);
    password.setBit(ICEBEAM);
    
    password.setBit(BOMBS);
    password.setBit(BOMBS_TAKEN);
    
    password.setBit(HIGHJUMPBOOTS);
    password.setBit(HIGHJUMPBOOTS_TAKEN);
    
    password.setBit(SCREWATTACK);
    password.setBit(SCREWATTACK_TAKEN);
    
    password.setBit(VARIA);
    password.setBit(VARIA_TAKEN);
    
    updatePasswordText();
    updateControls();
}

void MPGFrame::onPasswordGiveMissiles(wxCommandEvent &) {
    int count = 0;
    
    if (password.getBit(MISSILE_BS1)) ++count;
    if (password.getBit(MISSILE_BS2)) ++count;
    if (password.getBit(MISSILE_KL1)) ++count;
    if (password.getBit(MISSILE_KL2)) ++count;
    if (password.getBit(MISSILE_KL3)) ++count;
    if (password.getBit(MISSILE_KL4)) ++count;
    if (password.getBit(MISSILE_NF1)) ++count;
    if (password.getBit(MISSILE_NF2)) ++count;
    if (password.getBit(MISSILE_NF3)) ++count;
    if (password.getBit(MISSILE_NF4)) ++count;
    if (password.getBit(MISSILE_NF5)) ++count;
    if (password.getBit(MISSILE_NF6)) ++count;
    if (password.getBit(MISSILE_NF7)) ++count;
    if (password.getBit(MISSILE_NF8)) ++count;
    if (password.getBit(MISSILE_NF9)) ++count;
    if (password.getBit(MISSILE_NF10)) ++count;
    if (password.getBit(MISSILE_NF11)) ++count;
    if (password.getBit(MISSILE_NF12)) ++count;
    if (password.getBit(MISSILE_RL1)) ++count;
    if (password.getBit(MISSILE_RL2)) ++count;
    if (password.getBit(MISSILE_RL3)) ++count;
    if (password.getBit(KRAID) || password.getBit(KRAID_STATUE)) count += 15;
    if (password.getBit(RIDLEY) || password.getBit(RIDLEY_STATUE)) count += 15;
    
    XRCCTRL(*this, "IDSC_ITEMS_MISSILES", wxSpinCtrl)->SetValue(count *= 5);
    
    #ifndef __WXMSW__
        // SetValue of a wxSpinCtrl on Windows also generates a EVT_TEXT event,
        // but on wxGTK it doesn't, so we need to update manually
        password.setMissiles(count);
        
        updateRawMissiles(count);
        updatePasswordText();
    #endif
}

void MPGFrame::onPasswordGiveMissileContainers(wxCommandEvent &) {
    password.setBit(MISSILE_BS1);
    password.setBit(MISSILE_BS2);
    
    password.setBit(MISSILE_KL1);
    password.setBit(MISSILE_KL2);
    password.setBit(MISSILE_KL3);
    password.setBit(MISSILE_KL4);
    
    password.setBit(MISSILE_NF1);
    password.setBit(MISSILE_NF2);
    password.setBit(MISSILE_NF3);
    password.setBit(MISSILE_NF4);
    password.setBit(MISSILE_NF5);
    password.setBit(MISSILE_NF6);
    password.setBit(MISSILE_NF7);
    password.setBit(MISSILE_NF8);
    password.setBit(MISSILE_NF9);
    password.setBit(MISSILE_NF10);
    password.setBit(MISSILE_NF11);
    password.setBit(MISSILE_NF12);
    
    password.setBit(MISSILE_RL1);
    password.setBit(MISSILE_RL2);
    password.setBit(MISSILE_RL3);
    
    updatePasswordText();
    updateControls();
}

void MPGFrame::onPasswordGiveStatues(wxCommandEvent &) {
    password.setBit(KRAID_STATUE);
    password.setBit(RIDLEY_STATUE);
    
    updatePasswordText();
    updateControls();
}

void MPGFrame::onPasswordGiveZebetites(wxCommandEvent &) {
    password.setBit(ZEBETITE1);
    password.setBit(ZEBETITE2);
    password.setBit(ZEBETITE3);
    password.setBit(ZEBETITE4);
    password.setBit(ZEBETITE5);
    
    updatePasswordText();
    updateControls();
}

void MPGFrame::onPasswordPerfectGame(wxCommandEvent &) {
    password = Password();

    // Missile Inventory
    password.setMissiles(MAX_MISSILES);
    
    // Start Location
    password.setBit(START_NF);
    password.setBit(START_KL);
    
    // Statues
    password.setBit(KRAID_STATUE);
    password.setBit(RIDLEY_STATUE);
    
    // Swimsuit Samus
    password.setBit(SWIMSUIT);
    
    // Bosses
    password.setBit(KRAID);
    password.setBit(RIDLEY);
    
    // Items
    wxCommandEvent event1(wxEVT_COMMAND_MENU_SELECTED,
                          XRCID("IDM_PASSWORD_GIVE_ITEMS"));
    GetEventHandler()->AddPendingEvent(event1);
    
    // Missile Containers
    wxCommandEvent event2(wxEVT_COMMAND_MENU_SELECTED,
                          XRCID("IDM_PASSWORD_GIVE_MC"));
    GetEventHandler()->AddPendingEvent(event2);
    
    // Energy Tanks
    wxCommandEvent event3(wxEVT_COMMAND_MENU_SELECTED,
                          XRCID("IDM_PASSWORD_GIVE_ET"));
    GetEventHandler()->AddPendingEvent(event3);
    
    // Red & Yellow Doors
    wxCommandEvent event4(wxEVT_COMMAND_MENU_SELECTED,
                          XRCID("IDM_PASSWORD_GIVE_DOORS"));
    GetEventHandler()->AddPendingEvent(event4);
    
    // Zebetites
    wxCommandEvent event5(wxEVT_COMMAND_MENU_SELECTED,
                          XRCID("IDM_PASSWORD_GIVE_ZEBETITES"));
    GetEventHandler()->AddPendingEvent(event5);
}

void MPGFrame::onPasswordReset(wxCommandEvent &) {
    int answer = wxMessageBox(wxT("Really Reset Password?"),
                              wxT("Confirm: Reset Password"),
                              wxYES_NO | wxICON_QUESTION);
                              
    if (answer == wxYES) {
        password = Password();
        
        updatePasswordText();
        updateControls();
    }
}

void MPGFrame::onRawBitChanged(wxCommandEvent &event) {
    wxCheckListBox *ptr = 
        dynamic_cast<wxCheckListBox *>(event.GetEventObject());
    int bit = event.GetSelection();
    bool state = ptr->IsChecked(bit);
    
    password.setBit(bit, state);
    
    switch (bit) {
        case MARUMARI:
        case MARUMARI_TAKEN:
            // Maru Mari not valid unless it's both taken and equipped
            state = password.getBit(MARUMARI) &&
                    password.getBit(MARUMARI_TAKEN);
            XRCCTRL(*this, "IDC_ITEMS_MARUMARI", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_BS1:
            XRCCTRL(*this, "IDC_ITEMS_MC_BS1", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_BS_LONGBEAM:
            XRCCTRL(*this, "IDC_MISC_DOORS_BS_LONGBEAM",
                    wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_BS_TOURIANBRIDGE:
            XRCCTRL(*this, "IDC_MISC_DOORS_BS_TOURIANBRIDGE",
				    wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_BS1:
            XRCCTRL(*this, "IDC_ITEMS_ET_BS1", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_BS_BOMBS:
            XRCCTRL(*this, "IDC_MISC_DOORS_BS_BOMBS",
				    wxCheckBox)->SetValue(state);
            break;
            
        case BOMBS:
        case BOMBS_TAKEN:
            // Bombs not valid unless it's both taken and equipped
            state = password.getBit(BOMBS) && password.getBit(BOMBS_TAKEN);
            XRCCTRL(*this, "IDC_ITEMS_BOMBS", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_BS_ICEBEAM:
            XRCCTRL(*this, "IDC_MISC_DOORS_BS_ICEBEAM",
				    wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_BS2:
            XRCCTRL(*this, "IDC_ITEMS_MC_BS2", wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_BS2:
            XRCCTRL(*this, "IDC_ITEMS_ET_BS2", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_BS_VARIA:
            XRCCTRL(*this, "IDC_MISC_DOORS_BS_VARIA",
				    wxCheckBox)->SetValue(state);
            break;
            
        case VARIA:
        case VARIA_TAKEN:
            // Varia not valid unless it's both taken and equipped
            state = password.getBit(VARIA) && password.getBit(VARIA_TAKEN);
            XRCCTRL(*this, "IDC_ITEMS_VARIA", wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_BS3:
            XRCCTRL(*this, "IDC_ITEMS_ET_BS3", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF1:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF1", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF2:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF2", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_NF_ICEBEAM:
            XRCCTRL(*this, "IDC_MISC_DOORS_NF_ICEBEAM",
				    wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF3:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF3", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF4:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF4", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF5:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF5", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF6:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF6", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF7:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF7", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF8:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF8", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF9:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF9", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_NF_HIGHJUMPBOOTS:
            XRCCTRL(*this, "IDC_MISC_DOORS_NF_HIGHJUMPBOOTS",
				    wxCheckBox)->SetValue(state);
            break;
            
        case HIGHJUMPBOOTS:
        case HIGHJUMPBOOTS_TAKEN:
            // High Jump Boots not valid unless both taken and equipped
            state = password.getBit(HIGHJUMPBOOTS) &&
                    password.getBit(HIGHJUMPBOOTS_TAKEN);
            XRCCTRL(*this, "IDC_ITEMS_HIGHJUMPBOOTS",
				    wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_NF_SCREWATTACK:
            XRCCTRL(*this, "IDC_MISC_DOORS_NF_SCREWATTACK",
				    wxCheckBox)->SetValue(state);
            break;
            
        case SCREWATTACK:
        case SCREWATTACK_TAKEN:
            // Screw Attack not valid unless both taken and equipped
            state = password.getBit(SCREWATTACK) &&
                    password.getBit(SCREWATTACK_TAKEN);
            XRCCTRL(*this, "IDC_ITEMS_SCREWATTACK",
				    wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF10:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF10", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF11:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF11", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_NF_WAVEBEAM:
            XRCCTRL(*this, "IDC_MISC_DOORS_NF_WAVEBEAM",
				    wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_NF:
            XRCCTRL(*this, "IDC_ITEMS_ET_NF", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_NF12:
            XRCCTRL(*this, "IDC_ITEMS_MC_NF12", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_KL1:
            XRCCTRL(*this, "IDC_MISC_DOORS_KL1", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_KL1:
            XRCCTRL(*this, "IDC_ITEMS_MC_KL1", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_KL2:
            XRCCTRL(*this, "IDC_ITEMS_MC_KL2", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_KL2:
            XRCCTRL(*this, "IDC_MISC_DOORS_KL2", wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_KL:
            XRCCTRL(*this, "IDC_ITEMS_ET_KL", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_KL3:
            XRCCTRL(*this, "IDC_MISC_DOORS_KL3", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_KL4:
            XRCCTRL(*this, "IDC_MISC_DOORS_KL4", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_KL3:
            XRCCTRL(*this, "IDC_ITEMS_MC_KL3", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_KL4:
            XRCCTRL(*this, "IDC_ITEMS_MC_KL4", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_KL_KRAID:
            XRCCTRL(*this, "IDC_MISC_DOORS_KL_KRAID",
				    wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_KL_KRAID:
            XRCCTRL(*this, "IDC_ITEMS_ET_KL_KRAID",
				    wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_RL1:
            XRCCTRL(*this, "IDC_ITEMS_MC_RL1", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_RL:
            XRCCTRL(*this, "IDC_MISC_DOORS_RL", wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_RL:
            XRCCTRL(*this, "IDC_ITEMS_ET_RL", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_RL2:
            XRCCTRL(*this, "IDC_ITEMS_MC_RL2", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_RL_RIDLEY:
            XRCCTRL(*this, "IDC_MISC_DOORS_RL_RIDLEY",
				    wxCheckBox)->SetValue(state);
            break;
            
        case ENERGYTANK_RL_RIDLEY:
            XRCCTRL(*this, "IDC_ITEMS_ET_RL_RIDLEY",
				    wxCheckBox)->SetValue(state);
            break;
            
        case MISSILE_RL3:
            XRCCTRL(*this, "IDC_ITEMS_MC_RL3", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_T1:
            XRCCTRL(*this, "IDC_MISC_DOORS_T1", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_T2:
            XRCCTRL(*this, "IDC_MISC_DOORS_T2", wxCheckBox)->SetValue(state);
            break;
            
        case REDDOOR_T3:
            XRCCTRL(*this, "IDC_MISC_DOORS_T3", wxCheckBox)->SetValue(state);
            break;
            
        case ZEBETITE1:
            XRCCTRL(*this, "IDC_MISC_ZEBETITE1", wxCheckBox)->SetValue(state);
            break;
            
        case ZEBETITE2:
            XRCCTRL(*this, "IDC_MISC_ZEBETITE2", wxCheckBox)->SetValue(state);
            break;
            
        case ZEBETITE3:
            XRCCTRL(*this, "IDC_MISC_ZEBETITE3", wxCheckBox)->SetValue(state);
            break;
            
        case ZEBETITE4:
            XRCCTRL(*this, "IDC_MISC_ZEBETITE4", wxCheckBox)->SetValue(state);
            break;
            
        case ZEBETITE5:
            XRCCTRL(*this, "IDC_MISC_ZEBETITE5", wxCheckBox)->SetValue(state);
            break;
            
        case MOTHERBRAIN:
            XRCCTRL(*this, "IDC_MISC_BOSS_MOTHERBRAIN",
				    wxCheckBox)->SetValue(state);
            break;
            
        case START_NF:
        case START_KL:
        case START_RL:
            updateStartLocation();
            break;
            
        case RESET:
            if (state) {
                wxMessageBox(wxT("This bit will produce an invalid password."),
                             wxT("Warning: Invalid Password"),
                             wxICON_EXCLAMATION | wxOK);
            }
            
            break;
        
        case SWIMSUIT:
            XRCCTRL(*this, "IDRB_MISC_ARMOR",
                    wxRadioBox)->SetSelection(state ? 1 : 0);
            break;

        case LONGBEAM:
            XRCCTRL(*this, "IDC_ITEMS_LONGBEAM", wxCheckBox)->SetValue(state);
            break;
            
        case WAVEBEAM:
            XRCCTRL(*this, "IDC_ITEMS_WAVEBEAM", wxCheckBox)->SetValue(state);
            break;
            
        case ICEBEAM:
            XRCCTRL(*this, "IDC_ITEMS_ICEBEAM", wxCheckBox)->SetValue(state);
            break;
            
        case MISSILES:
        case MISSILES + 1:
        case MISSILES + 2:
        case MISSILES + 3:
        case MISSILES + 4:
        case MISSILES + 5:
        case MISSILES + 6:
        case MISSILES + 7:
            ignoreTextEvent = true;
            XRCCTRL(*this, "IDSC_ITEMS_MISSILES",
                    wxSpinCtrl)->SetValue(password.getMissiles());
            ignoreTextEvent = false;
            
            break;
        
        case GAMETIME: 
        case GAMETIME + 1:
        case GAMETIME + 2:
        case GAMETIME + 3:
        case GAMETIME + 4:
        case GAMETIME + 5:
        case GAMETIME + 6:
        case GAMETIME + 7:
        case GAMETIME + 8:
        case GAMETIME + 9:
        case GAMETIME + 10:
        case GAMETIME + 11:
        case GAMETIME + 12:
        case GAMETIME + 13:
        case GAMETIME + 14:
        case GAMETIME + 15:
        case GAMETIME + 16:
        case GAMETIME + 17:
        case GAMETIME + 18:
        case GAMETIME + 19:
        case GAMETIME + 20:
        case GAMETIME + 21:
        case GAMETIME + 22:
        case GAMETIME + 23:
        case GAMETIME + 24:
        case GAMETIME + 25:
        case GAMETIME + 26:
        case GAMETIME + 27:
        case GAMETIME + 28:
        case GAMETIME + 29:
        case GAMETIME + 30:
        case GAMETIME + 31:
            {
                unsigned long value =
                    static_cast<unsigned long>(password.getGameTime());
                
                ignoreTextEvent = true;
                XRCCTRL(*this, "IDT_MISC_GAMETIME",
                        wxTextCtrl)->SetValue(wxString::Format(wxT("%lu"),
                                              value));
                ignoreTextEvent = false;
            }
            
            break;
            
        case RIDLEY:
            XRCCTRL(*this, "IDC_MISC_BOSS_RIDLEY", wxCheckBox)->SetValue(state);
            break;
            
        case RIDLEY_STATUE:
            XRCCTRL(*this, "IDC_MISC_STATUE_RIDLEY",
                    wxCheckBox)->SetValue(state);
            break;
            
        case KRAID:
            XRCCTRL(*this, "IDC_MISC_BOSS_KRAID", wxCheckBox)->SetValue(state);
            break;
            
        case KRAID_STATUE:
            XRCCTRL(*this, "IDC_MISC_STATUE_KRAID",
                    wxCheckBox)->SetValue(state);
            break;
            
        default:
            // one of the unknowns -- do nothing
            break;
    }
    
    updatePasswordText();
}

void MPGFrame::onShiftTextChanged(wxCommandEvent &) {
    if (ignoreTextEvent) {
        return;
    }
    
    wxSpinCtrl *ctrl = XRCCTRL(*this, "IDSC_RAW_SHIFT", wxSpinCtrl);
    unsigned char value = static_cast<unsigned char>(ctrl->GetValue());
    
    password.setShift(value);
    
    updatePasswordText();
}

void MPGFrame::onStartLocationChanged(wxCommandEvent &event) {
    wxRadioBox *ptr = dynamic_cast<wxRadioBox *>(event.GetEventObject());
    int location = ptr->GetSelection();
    bool nf, kl, rl;
    
    switch (location) {
        case 0:
            // Brinstar
            nf = false;
            kl = false;
            rl = false;
            break;
            
        case 1:
            // Kraid's Lair
            nf = false;
            kl = true;
            rl = false;
            break;
            
        case 2:
            // Norfair
            nf = true;
            kl = false;
            rl = false;
            break;
            
        case 3:
            // Ridley's Lair
            nf = false;
            kl = false;
            rl = true;
            break;
            
        default:
            // Tourian
            nf = true;
            kl = true;
            rl = false;
            break;
    };
    
    wxCheckListBox *ctrl = XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox);
    ctrl->Check(START_NF, nf);
    ctrl->Check(START_KL, kl);
    ctrl->Check(START_RL, rl);
    
    password.setBit(START_NF, nf);
    password.setBit(START_KL, kl);
    password.setBit(START_RL, rl);
    
    updatePasswordText();
}

void MPGFrame::onStatueChanged(wxCommandEvent &event) {
    int id = event.GetId();
    bool state = event.IsChecked();
    int bit;
    
    if (id == XRCID("IDC_MISC_STATUE_KRAID")) {
        bit = KRAID_STATUE;
    } else {
        bit = RIDLEY_STATUE;
    }
    
    XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox)->Check(bit, state);
    password.setBit(bit, state);
    
    updatePasswordText();
}

void MPGFrame::onZebetiteChanged(wxCommandEvent &event) {
    int id = event.GetId();
    bool state = event.IsChecked();
    int bit;
    
    if (id == XRCID("IDC_MISC_ZEBETITE1")) {
        bit = ZEBETITE1;
    } else if (id == XRCID("IDC_MISC_ZEBETITE2")) {
        bit = ZEBETITE2;
    } else if (id == XRCID("IDC_MISC_ZEBETITE3")) {
        bit = ZEBETITE3;
    } else if (id == XRCID("IDC_MISC_ZEBETITE4")) {
        bit = ZEBETITE4;
    } else {
        bit = ZEBETITE5;
    }
    
    XRCCTRL(*this, "IDCLB_RAW_BITS", wxCheckListBox)->Check(bit, state);
    password.setBit(bit, state);
    
    updatePasswordText();
}

IMPLEMENT_CLASS(MPGFrame, wxFrame)

