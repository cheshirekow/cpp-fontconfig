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
