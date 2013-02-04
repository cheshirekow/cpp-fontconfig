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
 *  \file   StrList.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFONTCONFIG_STRLIST_H_
#define CPPFONTCONFIG_STRLIST_H_

#include <cppfontconfig/common.h>
#include <cppfontconfig/StrSet.h>

namespace fontconfig
{

/// used during enumeration to safely and correctly walk the list of strings
/// even while that list is edited in the middle of enumeration.
/**
 *  String iterators are not reference counted object and the StrList class is
 *  mearly a container for the pointer. It is safe to copy an StrList but
 *  be sure to only call destroy on one of the copies.
 *
 *  Also, since StrList is a wrapper for the pointer, you should probably
 *  only allocate an StrList on the stack.
 */
class StrList
{
    private:
        void* m_ptr;

    public:
        StrList( void* ptr );

        void* get_ptr();

        /// create a string iterator
        /**
         *  Creates an iterator to list the strings in set.
         */
        static StrList create (StrSet set);

        /// get next string in iteration
        /**
         *  Returns the next string in set.
         */
        Char8_t* next ();

        /// destroy a string iterator
        /**
         *  Destroys the enumerator list.
         */
        void done();
};

} // namespace fontconfig 

#endif // STRLIST_H_
