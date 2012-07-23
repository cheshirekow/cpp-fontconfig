/*
 *  \file   FontSet.cpp
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/FontSet.h>
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


} // namespace fontconfig 
