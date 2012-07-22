/*
 *  \file   Blanks.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cassert>
#include <fontconfigmm/Blanks.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{


Blanks::Blanks(void* fc_blanks):
    m_fc_blanks(fc_blanks)
{
}

void Blanks::destroy()
{
    FcBlanksDestroy( (FcBlanks*)m_fc_blanks );
}

bool Blanks::add(Char32_t ucs4)
{
    return FcBlanksAdd( (FcBlanks*)this, ucs4 );
}

bool Blanks::isMember(Char32_t ucs4)
{
    return FcBlanksIsMember( (FcBlanks*)this, ucs4 );
}

Blanks* Blanks::create()
{
    return (Blanks*) FcBlanksCreate();
}

} // namespace fontconfig 
