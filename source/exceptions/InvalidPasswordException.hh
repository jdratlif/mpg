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
 
// $Id: InvalidPasswordException.hh,v 1.6 2005/09/27 09:32:14 technoplaza Exp $

#ifndef _INVALIDPASSWORDEXCEPTION_HH_
#define _INVALIDPASSWORDEXCEPTION_HH_

#include <stdexcept>
#include <string>

namespace mpg {
    /// enumeration for the invalid password errors
    enum PasswordError {
        INVALID_ALPHABET, INVALID_CHECKSUM, INVALID_LENGTH
    };
    
    /**
     * Exception thrown when an invalid password is given, such as an invalid
     * character (outside the Metroid alphabet), invalid checksum, or invalid
     * password length.
     */
    class InvalidPasswordException : public std::runtime_error {
    private:
        enum PasswordError error;
        
    public:
        /**
         * Creates a new InvalidPasswordException.
         *
         * @param message The error messsage.
         * @param error The password error.
         */
        InvalidPasswordException(const std::string &message,
                                 enum PasswordError error);
                                 
        /**
         * Gets the error that triggered this InvalidPasswordException.
         *
         * @return The error.
         */
        enum PasswordError getError() const;
    };
    
    inline InvalidPasswordException::InvalidPasswordException(
        const std::string &message, enum PasswordError error) : 
        std::runtime_error(message), error(error) {}
    inline enum PasswordError InvalidPasswordException::getError() const
        { return error; }
}

#endif

