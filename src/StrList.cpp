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
 *  @file   src/StrList.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/StrList.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

StrList::StrList( void* ptr )
:
    m_ptr(ptr)
{

}

void* StrList::get_ptr()
{
    return m_ptr;
}

StrList StrList::create(StrSet set)
{
    return StrList ( FcStrListCreate( (FcStrSet*)set.get_ptr() ) );
}

Char8_t* StrList::next()
{
    return FcStrListNext( (FcStrList*) this );
}

void StrList::done()
{
    FcStrListDone( (FcStrList*)this );
}

} // namespace fontconfig 
