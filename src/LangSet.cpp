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
 *  \file   LangSet.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/LangSet.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

LangSet::LangSet( void* ptr ):
    m_ptr(ptr)
{

}

void* LangSet::get_ptr()
{
    return m_ptr;
}

const void* LangSet::get_ptr() const
{
    return m_ptr;
}

LangSet LangSet::create()
{
    return LangSet( FcLangSetCreate( ) );
}

void LangSet::destroy()
{
    return FcLangSetDestroy( (FcLangSet*)m_ptr );
}

LangSet LangSet::copy()
{
    return LangSet( FcLangSetCopy( (FcLangSet*)m_ptr ) );
}

bool LangSet::add(const Char8_t* lang)
{
    return FcLangSetAdd( (FcLangSet*)m_ptr, lang);
}

bool LangSet::del(const Char8_t* lang)
{
    return FcLangSetDel( (FcLangSet*)m_ptr, lang);
}

LangResult_t LangSet::hasLang(const Char8_t* lang)
{
    return (LangResult_t) FcLangSetHasLang( (FcLangSet*)m_ptr, lang);
}

LangResult_t LangSet::compare(const LangSet lsb)
{
    return (LangResult_t) FcLangSetCompare( (FcLangSet*)m_ptr, (FcLangSet*)lsb.m_ptr);
}

bool LangSet::contains(const LangSet lsb)
{
    return FcLangSetContains( (FcLangSet*)m_ptr, (FcLangSet*)lsb.m_ptr);
}

bool LangSet::equal(const LangSet lsb)
{
    return FcLangSetEqual( (FcLangSet*)m_ptr, (FcLangSet*)lsb.m_ptr);
}

Char32_t LangSet::hash()
{
    return FcLangSetHash( (FcLangSet*)m_ptr );
}

StrSet LangSet::getLangs()
{
    return StrSet( FcLangSetGetLangs( (FcLangSet*)m_ptr ) );
}

LangSet LangSet::creatUnion(const LangSet b)
{
    return LangSet( FcLangSetUnion( (FcLangSet*)m_ptr, (FcLangSet*)b.m_ptr ) );
}

LangSet LangSet::subtract(const LangSet b)
{
    return LangSet( FcLangSetSubtract( (FcLangSet*)m_ptr, (FcLangSet*)b.m_ptr) );
}

} // namespace fontconfig 
