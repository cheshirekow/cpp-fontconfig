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
 *  @file   include/cppfontconfig/StrSet.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFONTCONFIG_STRSET_H_
#define CPPFONTCONFIG_STRSET_H_

#include <cppfontconfig/common.h>

namespace fontconfig
{

/// holds a list of strings that can be appended to and enumerated.
/**
 *  Its unique characteristic is that the enumeration works even while strings
 *  are appended during enumeration.
 *
 *  String sets are not reference counted object and the StrSet class is
 *  mearly a container for the pointer. It is safe to copy an StrSet but
 *  be sure to only call destroy on one of the copies.
 *
 *  Also, since StrSet is a wrapper for the pointer, you should probably
 *  only allocate an StrSet on the stack.
 */
class StrSet
{
    private:
        void* m_ptr;

    public:
        StrSet(void* ptr);
        void* get_ptr();

        /// create a string set
        /**
         *  Create an empty set.
         */
        static StrSet  create(void);

        /// check set for membership
        /**
         *  Returns whether s is a member of set.
         */
        bool setMember (const Char8_t *s);

        ///  check sets for equality
        /**
         *  Returns whether set_a contains precisely the same strings as set_b.
         *  Ordering of strings within the two sets is not considered.
         */
        bool equal (StrSet other);

        /// add to a string set
        /**
         *  Adds a copy of s to set.
         */
        bool add (const Char8_t *s);

        /// add a filename to a string set
        /**
         *  Adds a copy s to set, The copy is created with FcStrCopyFilename so
         *  that leading '~' values are replaced with the value of the HOME
         *  environment variable.
         */
        bool addFilename (const Char8_t *s);

        /// delete from a string set
        /**
         *  Removes s from set, returning FcTrue if s was a member else FcFalse.
         */
        bool del (const Char8_t *s);

        /// destroy a string set
        /**
         *  Destroys set.
         */
        void destroy ();
};


} // namespace fontconfig 

#endif // STRSET_H_
