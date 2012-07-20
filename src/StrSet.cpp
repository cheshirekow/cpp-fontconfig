/*
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


StrSet* StrSet::create(void)
{
    return (StrSet*) FcStrSetCreate();
}

bool StrSet::setMember(const Char8_t* s)
{
    return FcStrSetMember( (FcStrSet*)this, s );
}

bool StrSet::equal(StrSet* other)
{
    return FcStrSetEqual( (FcStrSet*)this, (FcStrSet*)other );
}

bool StrSet::add(const Char8_t* s)
{
    return FcStrSetAdd( (FcStrSet*)this, s );
}

bool StrSet::addFilename(const Char8_t* s)
{
    return FcStrSetAddFilename( (FcStrSet*)this, s );
}

bool StrSet::del(const Char8_t* s)
{
    return FcStrSetDel( (FcStrSet*)this, s );
}

void StrSet::destroy()
{
    return FcStrSetDestroy( (FcStrSet*)this );
}

} // namespace fontconfig 
