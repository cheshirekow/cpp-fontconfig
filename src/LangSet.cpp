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

LangSet* LangSet::create()
{
    return (LangSet*) FcLangSetCreate( );
}

void LangSet::destroy()
{
    return FcLangSetDestroy( (FcLangSet*)this );
}

LangSet* LangSet::copy()
{
    return (LangSet*) FcLangSetCopy( (FcLangSet*)this );
}

bool LangSet::add(const Char8_t* lang)
{
    return FcLangSetAdd( (FcLangSet*)this, lang);
}

bool LangSet::del(const Char8_t* lang)
{
    return FcLangSetDel( (FcLangSet*)this, lang);
}

LangResult_t LangSet::hasLang(const Char8_t* lang)
{
    return (LangResult_t) FcLangSetHasLang( (FcLangSet*)this, lang);
}

LangResult_t LangSet::compare(const LangSet* lsb)
{
    return (LangResult_t) FcLangSetCompare( (FcLangSet*)this, (FcLangSet*)lsb);
}

bool LangSet::contains(const LangSet* lsb)
{
    return FcLangSetContains( (FcLangSet*)this, (FcLangSet*)lsb);
}

bool LangSet::equal(const LangSet* lsb)
{
    return FcLangSetEqual( (FcLangSet*)this, (FcLangSet*)lsb);
}

Char32_t LangSet::hash()
{
    return FcLangSetHash( (FcLangSet*)this );
}

StrSet* LangSet::getLangs()
{
    return (StrSet*) FcLangSetGetLangs( (FcLangSet*)this );
}

LangSet* LangSet::creatUnion(const LangSet* b)
{
    return (LangSet*) FcLangSetUnion( (FcLangSet*)this, (FcLangSet*)b );
}

LangSet* LangSet::subtract(const LangSet* b)
{
    return (LangSet*) FcLangSetSubtract( (FcLangSet*)this, (FcLangSet*)b);
}

} // namespace fontconfig 
