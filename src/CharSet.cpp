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
 *  \file   CharSet.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/CharSet.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

CharSet::CharSet( void* ptr ):
    m_ptr(ptr)
{

}

CharSet::CharSet( const CharSet& other )
{
    m_ptr = FcCharSetCopy( (FcCharSet*)other.m_ptr );
}

CharSet::~CharSet()
{
    FcCharSetDestroy( (FcCharSet*)m_ptr );
}

void* CharSet::get_ptr()
{
    return m_ptr;
}

const void* CharSet::get_ptr() const
{
    return m_ptr;
}

CharSet& CharSet::operator=( const CharSet& other )
{
    FcCharSetDestroy( (FcCharSet*)m_ptr );
    m_ptr =  FcCharSetCopy( (FcCharSet*)other.m_ptr );
    return *this;
}

CharSet CharSet::create(void)
{
    return CharSet ( FcCharSetCreate() );
}

//void CharSet::destroy()
//{
//    FcCharSetDestroy( (FcCharSet*)m_ptr );
//}

bool CharSet::addChar(Char32_t ucs4)
{
    return FcCharSetAddChar( (FcCharSet*)m_ptr, ucs4 );
}

bool CharSet::delChar(Char32_t ucs4)
{
    return FcCharSetDelChar( (FcCharSet*)m_ptr, ucs4 );
}

//CharSet CharSet::copy()
//{
//    return CharSet( FcCharSetCopy( (FcCharSet*)m_ptr ) );
//}

bool CharSet::equal(const CharSet& other)
{
    return FcCharSetEqual( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr );
}

CharSet CharSet::intersect(const CharSet& other)
{
    return CharSet(
            FcCharSetIntersect( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr ) );
}

CharSet CharSet::createUnion(const CharSet& other)
{
    return CharSet(
            FcCharSetUnion((FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr ) );
}

CharSet CharSet::subtract(const CharSet& other)
{
    return CharSet(
            FcCharSetSubtract( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr ) );
}

bool CharSet::merge(const CharSet& other, bool& changed)
{
    FcBool changed2;
    bool result = FcCharSetMerge( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr, &changed2 );
    changed = changed2;
    return result;
}

bool CharSet::merge(const CharSet& other)
{
    return FcCharSetMerge( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr, 0 );
}

bool CharSet::hasChar(Char32_t ucs4)
{
    return FcCharSetHasChar( (FcCharSet*)m_ptr, ucs4 );
}

Char32_t CharSet::count()
{
    return FcCharSetCount( (FcCharSet*)m_ptr );
}

Char32_t CharSet::intersectCount(const CharSet& other)
{
    return FcCharSetIntersectCount( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr );
}

Char32_t CharSet::subtractCount(const CharSet& other)
{
    return FcCharSetSubtractCount( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr );
}

bool CharSet::isSubset(const CharSet& other)
{
    return FcCharSetIsSubset( (FcCharSet*)m_ptr, (FcCharSet*)other.m_ptr );
}

Char32_t CharSet::firstPage(Char32_t map[MAP_SIZE], Char32_t* next)
{
    return FcCharSetFirstPage( (FcCharSet*)m_ptr, map, next );
}

Char32_t CharSet::nextPage(Char32_t map[MAP_SIZE], Char32_t* next)
{
    return FcCharSetNextPage( (FcCharSet*)m_ptr, map, next );
}

} // namespace fontconfig 
