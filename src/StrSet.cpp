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
 *  \file   StrSet.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/StrSet.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

StrSet::StrSet(void* ptr):
    m_ptr(ptr)
{

}

StrSet StrSet::create(void)
{
    return StrSet( FcStrSetCreate() );
}

void* StrSet::get_ptr()
{
    return m_ptr;
}

bool StrSet::setMember(const Char8_t* s)
{
    return FcStrSetMember( (FcStrSet*)this, s );
}

bool StrSet::equal(StrSet other)
{
    return FcStrSetEqual(   (FcStrSet*)m_ptr,
                            (FcStrSet*)other.m_ptr );
}

bool StrSet::add(const Char8_t* s)
{
    return FcStrSetAdd( (FcStrSet*)m_ptr, s );
}

bool StrSet::addFilename(const Char8_t* s)
{
    return FcStrSetAddFilename( (FcStrSet*)m_ptr, s );
}

bool StrSet::del(const Char8_t* s)
{
    return FcStrSetDel( (FcStrSet*)m_ptr, s );
}

void StrSet::destroy()
{
    return FcStrSetDestroy( (FcStrSet*)m_ptr );
}

} // namespace fontconfig 
