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
 *  \file   Blanks.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cassert>
#include <cppfontconfig/Blanks.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{


Blanks::Blanks(void* ptr):
    m_ptr(ptr)
{
}

void* Blanks::get_ptr()
{
    return m_ptr;
}

const void* Blanks::get_ptr() const
{
    return m_ptr;
}

void Blanks::destroy()
{
    FcBlanksDestroy( (FcBlanks*) (m_ptr));
}

bool Blanks::add(Char32_t ucs4)
{
    return FcBlanksAdd((FcBlanks*) (m_ptr), ucs4);
}

bool Blanks::isMember(Char32_t ucs4)
{
    return FcBlanksIsMember((FcBlanks*) (m_ptr), ucs4);
}



Blanks* Blanks::create()
{
    return (Blanks*) (FcBlanksCreate());
}

} // namespace fontconfig 
