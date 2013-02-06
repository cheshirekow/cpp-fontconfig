/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of cppfontconfig.
 *
 *  cppfontconfig is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cppfontconfig is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cppfontconfig.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  @file   include/cppfontconfig/Blanks.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFONTCONFIG_BLANKS_H_
#define CPPFONTCONFIG_BLANKS_H_

#include <cppfontconfig/common.h>

namespace fontconfig
{


///< holds a list of Unicode chars which are expected to be blank
/**
 *  unexpectedly
 *  blank chars are assumed to be invalid and are elided from the charset
 *  associated with the font.
 *
 *  Blanks structures are not reference counted. It is safe to pass around
 *  copies of this object, however you must remember to call destroy on
 *  one and only one copy when you're done with it
 *
 *  It contains only one data member which is a pointer
 *  and the copy constructor will simply copy that pointer so there is no
 *  reason to allocate a Blank on the heap.
 */
class Blanks
{
    private:
        void* m_ptr;

    public:
        void* get_ptr();
        const void* get_ptr() const;

        /// Constructs a new Blanks object wrapping the underlying
        /// c structure
        Blanks(void* ptr);

        /// Destroys an FcBlanks object, freeing any associated memory.
        /**
         *  @see FcBlanksDestroy
         */
        void destroy();

        /// Add a character to an FcBlanks
        /**
         *  Adds a single character to an FcBlanks object, returning FcFalse if
         *  this process ran out of memory.
         *
         *  @see FcBlanksAdd
         */
        bool add( Char32_t ucs4 );

        /// Query membership in an FcBlanks
        /**
         *  Returns whether the specified FcBlanks object contains the
         *  indicated Unicode value.
         *  @see FcBlanksIsMember
         */
        bool isMember( Char32_t ucs4 );

        /// Creates an empty FcBlanks oject
        /**
         *  @see FcBlanksCreate
         */
        static Blanks* create();
};

} // namespace fontconfig 

#endif // BLANKS_H_
