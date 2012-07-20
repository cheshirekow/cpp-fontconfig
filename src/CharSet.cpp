/*
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

CharSet* CharSet::create(void)
{
    return (CharSet*) FcCharSetCreate();
}

void CharSet::destroy()
{
    FcCharSetDestroy( (FcCharSet*)this );
}

bool CharSet::addChar(Char32_t ucs4)
{
    return FcCharSetAddChar( (FcCharSet*)this, ucs4 );
}

bool CharSet::delChar(Char32_t ucs4)
{
    return FcCharSetDelChar( (FcCharSet*)this, ucs4 );
}

CharSet* CharSet::copy()
{
    return (CharSet*) FcCharSetCopy( (FcCharSet*)this );
}

bool CharSet::equal(const CharSet* other)
{
    return FcCharSetEqual( (FcCharSet*)this, (FcCharSet*)other );
}

CharSet* CharSet::intersect(const CharSet* other)
{
    return (CharSet*) FcCharSetIntersect( (FcCharSet*)this, (FcCharSet*)other );
}

CharSet* CharSet::createUnion(const CharSet* other)
{
    return (CharSet*) FcCharSetUnion((FcCharSet*)this, (FcCharSet*)other );
}

CharSet* CharSet::subtract(const CharSet* other)
{
    return (CharSet*) FcCharSetSubtract( (FcCharSet*)this, (FcCharSet*)other );
}

bool CharSet::merge(const CharSet* other, bool& changed)
{
    int changed2;
    bool result = FcCharSetMerge( (FcCharSet*)this, (FcCharSet*)other, &changed2 );
    changed = changed2 != 0;

    return result;
}

bool CharSet::hasChar(Char32_t ucs4)
{
    return FcCharSetHasChar( (FcCharSet*)this, ucs4 );
}

Char32_t CharSet::count()
{
    return FcCharSetCount( (FcCharSet*)this );
}

Char32_t CharSet::intersectCount(const CharSet* other)
{
    return FcCharSetIntersectCount( (FcCharSet*)this, (FcCharSet*)other );
}

Char32_t CharSet::subtractCount(const CharSet* other)
{
    return FcCharSetSubtractCount( (FcCharSet*)this, (FcCharSet*)other );
}

bool CharSet::isSubset(const CharSet* other)
{
    return FcCharSetIsSubset( (FcCharSet*)this, (FcCharSet*)other );
}

Char32_t CharSet::firstPage(Char32_t map[MAP_SIZE], Char32_t* next)
{
    return FcCharSetFirstPage( (FcCharSet*)this, map, next );
}

Char32_t CharSet::nextPage(Char32_t map[MAP_SIZE], Char32_t* next)
{
    return FcCharSetNextPage( (FcCharSet*)this, map, next );
}

} // namespace fontconfig 
