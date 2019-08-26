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
 
// $Id: Password.hh,v 1.10 2005/09/27 09:32:14 technoplaza Exp $

#ifndef _PASSWORD_HH_
#define _PASSWORD_HH_

#include <wx/string.h>

#include "exceptions/InvalidPasswordException.hh"

namespace mpg {
    const int PASSWORD_BITS = 128;
    const unsigned int PASSWORD_LENGTH = 24;
    const int PASSWORD_LENGTH_BYTES = 18;
    
    enum {
        MARUMARI_TAKEN, MISSILE_BS1, REDDOOR_BS_LONGBEAM,
        REDDOOR_BS_TOURIANBRIDGE, ENERGYTANK_BS1, REDDOOR_BS_BOMBS, BOMBS_TAKEN,
        REDDOOR_BS_ICEBEAM, MISSILE_BS2, ENERGYTANK_BS2, REDDOOR_BS_VARIA,
        VARIA_TAKEN, ENERGYTANK_BS3, MISSILE_NF1, MISSILE_NF2,
        REDDOOR_NF_ICEBEAM, MISSILE_NF3, MISSILE_NF4, MISSILE_NF5, MISSILE_NF6,
        MISSILE_NF7, MISSILE_NF8, MISSILE_NF9, REDDOOR_NF_HIGHJUMPBOOTS,
        HIGHJUMPBOOTS_TAKEN, REDDOOR_NF_SCREWATTACK, SCREWATTACK_TAKEN,
        MISSILE_NF10, MISSILE_NF11, REDDOOR_NF_WAVEBEAM, ENERGYTANK_NF,
        MISSILE_NF12, REDDOOR_KL1, MISSILE_KL1, MISSILE_KL2, REDDOOR_KL2,
        ENERGYTANK_KL, REDDOOR_KL3, REDDOOR_KL4, MISSILE_KL3, MISSILE_KL4,
        REDDOOR_KL_KRAID, ENERGYTANK_KL_KRAID, MISSILE_RL1, REDDOOR_RL,
        ENERGYTANK_RL, MISSILE_RL2, REDDOOR_RL_RIDLEY, ENERGYTANK_RL_RIDLEY,
        MISSILE_RL3, REDDOOR_T1, REDDOOR_T2, REDDOOR_T3, ZEBETITE1, ZEBETITE2,
        ZEBETITE3, ZEBETITE4, ZEBETITE5, MOTHERBRAIN, START_NF = 64, START_KL,
        START_RL, RESET, SWIMSUIT = 71, BOMBS, HIGHJUMPBOOTS, LONGBEAM,
        SCREWATTACK, MARUMARI, VARIA, WAVEBEAM, ICEBEAM, MISSILES,
        GAMETIME = 88, RIDLEY = 124, RIDLEY_STATUE, KRAID, KRAID_STATUE
    };
    
    /// Class to encapsulate a Metroid Password
    class Password {
    private:
        wxString encoded;
        unsigned char data[18];
        
        static const int MISSILE_COUNT_BYTE = 10;
        static const int GAME_TIME_BYTE = 11;
        static const int SHIFT_BYTE = 16;
        static const int CHECKSUM_BYTE = 17;
        static const unsigned char SPACE_VALUE = 0xFF;

        /**
         * Calculates the checksum value for this Password.
         *
         * @return The checksum.
         */
        unsigned char calcChecksum() const;
        
        /**
         * Decodes a Metroid password into our raw format.
         *
         * @param password The password to decode.
         * @param fixChecksum true if the checksum should be fixed to force a
         *                    valid password; false to accept only valid
         *                    Metroid passwords.
         *
         * @throw InvalidPasswordException if the given password is invalid.
         */
        void decode(const wxString &password, bool fixChecksum) 
            throw(InvalidPasswordException);
        
        /**
         * Encodes the raw password data into a Metroid password.
         */
        void encode();

    public:
        static const wxString ALPHABET;
    
        /**
         * Creates a new blank password.
         */
        Password();
        
        /**
         * Creates a password from a Metroid password.
         *
         * @param password The Metroid password.
         * @param fixChecksum true if the checksum should be fixed to force a
         *                    valid password; false to accept only valid
         *                    Metroid passwords.
         *
         * @throw InvalidPasswordException if an invalid password is supplied.
         */
        Password(const wxString &password, bool fixChecksum = false)
            throw(InvalidPasswordException);
        
        /**
         * Gets a bit from the raw password data.
         *
         * @param bit The bit to get (1-128).
         *
         * @return true if the bit is set; false otherwise.
         *
         * @throw std::out_of_range if the bit is outside the range [0,127].
         */
        bool getBit(int bit) const throw(std::out_of_range);
        
        /**
         * Sets a bit in the raw password data.
         *
         * @param bit the bit to set (1-128).
         * @param value true to set the bit; false to clear it.
         *
         * @throw std::out_of_range if the bit is outside the range [0,127].
         */
        void setBit(int bit, bool value = true) throw(std::out_of_range);
        
        /**
         * Gets the encoded Metroid password encapsulated by this Password.
         *
         * @return The Metroid password.
         */
        const wxString &getEncoded() const;
        
        /**
         * Gets the game time in ticks (1 tick = ~4 seconds).
         *
         * @return The game time in ticks.
         */
        wxUint32 getGameTime() const;
        
        /**
         * Sets the game time.
         *
         * @param time The game time in ticks (1 tick = ~4 seconds).
         */
        void setGameTime(wxUint32 time);
        
        /**
         * Gets the number of missiles held by Samus.
         *
         * @return The number of missiles.
         */
        unsigned char getMissiles() const;
        
        /**
         * Sets the number of missiles held by Samus.
         *
         * @param missiles The number of missiles.
         */
        void setMissiles(unsigned char missiles);
        
        /**
         * Gets the shift byte used by this Password.
         *
         * @return The shift byte.
         */
        unsigned char getShift() const;
        
        /**
         * Sets the shift byte used by this Password.
         *
         * @param shift The shift byte.
         */
        void setShift(unsigned char shift);
    };
    
    inline const wxString &Password::getEncoded() const { return encoded; }
    inline unsigned char Password::getMissiles() const
        { return data[MISSILE_COUNT_BYTE]; }
    inline unsigned char Password::getShift() const { return data[SHIFT_BYTE]; }
}

#endif

