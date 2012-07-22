/*
 *  \file   LangSet.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/LangSet.h>
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
