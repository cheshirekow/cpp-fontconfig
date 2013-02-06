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
 *  @file   src/FontSet.cpp
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/FontSet.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

FontSet::FontSet(void* ptr):
    m_ptr(ptr)
{
}

void* FontSet::get_ptr()
{
    return m_ptr;
}

const void* FontSet::get_ptr() const
{
    return m_ptr;
}

FontSet FontSet::create(void)
{
    return FontSet( FcFontSetCreate() );
}

void FontSet::destroy()
{
    FcFontSetDestroy( (FcFontSet*)m_ptr );
}

bool FontSet::add(Pattern font)
{
    return FcFontSetAdd( (FcFontSet*)m_ptr, (FcPattern*)font.get_ptr() );
}

void FontSet::print()
{
    FcFontSetPrint( (FcFontSet*)m_ptr );
}


} // namespace fontconfig 
