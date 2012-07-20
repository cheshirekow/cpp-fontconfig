/*
 *  \file   StrList.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/StrList.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

StrList* StrList::create(StrSet* set)
{
    return (StrList*) FcStrListCreate( (FcStrSet*)set );
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
