/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of Fontconfigmm.
 *
 *  Fontconfigmm is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Fontconfigmm is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Fontconfigmm.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  \file   CharSet.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_CHARSET_H_
#define FONTCONFIGMM_CHARSET_H_

#include <cppfontconfig/common.h>
#include <unistd.h>

namespace fontconfig
{

/// An CharSet is an abstract type that holds the set of encoded Unicode
/// chars in a font. Operations to build and compare these sets are provided.
/**
 *  The underlying FcCharSet object is reference counted, so this CharSet
 *  wrapper provides a copy constructor which increments the reference count,
 *  and a destructor which decrements the reference count
 */
class CharSet
{
    private:
        void* m_ptr;

    public:
        static const unsigned int MAP_SIZE = 256/32;

        /// Wrap constructor, takes ownership of the pointer and will destroy
        /// it (i.e. decrement reference count) in the destructor
        CharSet( void* ptr );

        /// copy a charset
        /**
         *  Makes a copy of src; note that this may not actually do anything
         *  more than increment the reference count on src.
         */
        CharSet( const CharSet& other );

        /// calls FcCharSetDestroy, decrementing reference count and deleting
        /// data only when the reference count reaches zero
        /**
         *  FcCharSetDestroy decrements the reference count fcs. If the
         *  reference count becomes zero, all memory referenced is freed.
         */
        ~CharSet();

        /// returns the underlying FcCharSet pointer
        void* get_ptr();
        const void* get_ptr() const;

        /// assignment operator
        /**
         *  Since charsets are reference counted, this operator drops the
         *  current reference and increments the reference of the other by
         *  calling FcCharSetDestroy on the old pointer and
         *  FcCharSetCopy on the new pointer
         */
        CharSet& operator=( const CharSet& other );

        /// Create an empty character set
        /**
         *  FcCharSetCreate allocates and initializes a new empty character
         *  set object.
         */
        static CharSet create (void);

        /// Destroy a character set
        /**
         *  FcCharSetDestroy decrements the reference count fcs. If the
         *  reference count becomes zero, all memory referenced is freed.
         */
        // void destroy ();

        /// Add a character to a charset
        /**
         *  FcCharSetAddChar adds a single Unicode char to the set, returning
         *  FcFalse on failure, either as a result of a constant set or from
         *  running out of memory.
         */
        bool addChar (Char32_t ucs4);

        /// Remove a character from a charset
        /**
         *  FcCharSetDelChar deletes a single Unicode char from the set,
         *  returning FcFalse on failure, either as a result of a constant set
         *  or from running out of memory.
         */
        bool delChar (Char32_t ucs4);

        /// Copy a charset
        /**
         *  Makes a copy of src; note that this may not actually do anything
         *  more than increment the reference count on src.
         */
        // CharSet copy ();

        /// Compare two charsets
        /**
         *  Returns whether a and b contain the same set of Unicode chars.
         */
        bool equal (const CharSet& other);

        /// Intersect charsets
        /**
         *  Returns a set including only those chars found in both a and b.
         */
        CharSet intersect (const CharSet& other);

        /// Add charsets
        /**
         *  Returns a set including only those chars found in either a or b.
         */
        CharSet createUnion(const CharSet& other);

        /// Subtract charsets
        /**
         *  Returns a set including only those chars found in a but not b.
         */
        CharSet subtract (const CharSet& other);

        /// Merge charsets
        /**
         *  Adds all chars in b to a. In other words, this is an in-place
         *  version of FcCharSetUnion. If changed is not NULL, then it returns
         *  whether any new chars from b were added to a. Returns FcFalse on
         *  failure, either when a is a constant set or from running out of
         *  memory.
         */
        bool merge (const CharSet& other, bool& changed);
        bool merge (const CharSet& other);

        /// Check a charset for a char
        /**
         *  Returns whether fcs contains the char ucs4.
         */
        bool hasChar (Char32_t ucs4);

        /// Count entries in a charset
        /**
         *  Returns the total number of Unicode chars in a.
         */
        Char32_t count ();

        /// Intersect and count charsets
        /**
         *  Returns the number of chars that are in both a and b.
         */
        Char32_t intersectCount (const CharSet& other);

        /// Subtract and count charsets
        /**
         *  Returns the number of chars that are in a but not in b.
         */
        Char32_t subtractCount (const CharSet& other);

        /// Test for charset inclusion
        /**
         *  Returns whether a is a subset of b.
         */
        bool isSubset (const CharSet& other);

        /// Start enumerating charset contents
        /**
         *  Builds an array of bits marking the first page of Unicode coverage
         *  of a. Returns the base of the array. next contains the next page
         *  in the font.
         */
        Char32_t firstPage (
                Char32_t        map[MAP_SIZE],
                Char32_t        *next);

        /// Continue enumerating charset contents
        /**
         *  Builds an array of bits marking the Unicode coverage of a for page
         *  *next. Returns the base of the array. next contains the next page
         *  in the font.
         */
        Char32_t nextPage (
               Char32_t     map[MAP_SIZE],
               Char32_t     *next);
};

} // namespace fontconfig 

#endif // CHARSET_H_
