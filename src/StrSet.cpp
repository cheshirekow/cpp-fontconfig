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

StrSet::StrSet(void* ptr):
    m_ptr(ptr)
{

}

StrSet StrSet::create(void)
{
    return StrSet( FcStrSetCreate() );
}

void* StrSet::get_ptr()
{
    return m_ptr;
}

bool StrSet::setMember(const Char8_t* s)
{
    return FcStrSetMember( (FcStrSet*)this, s );
}

bool StrSet::equal(StrSet other)
{
    return FcStrSetEqual(   (FcStrSet*)m_ptr,
                            (FcStrSet*)other.m_ptr );
}

bool StrSet::add(const Char8_t* s)
{
    return FcStrSetAdd( (FcStrSet*)m_ptr, s );
}

bool StrSet::addFilename(const Char8_t* s)
{
    return FcStrSetAddFilename( (FcStrSet*)m_ptr, s );
}

bool StrSet::del(const Char8_t* s)
{
    return FcStrSetDel( (FcStrSet*)m_ptr, s );
}

void StrSet::destroy()
{
    return FcStrSetDestroy( (FcStrSet*)m_ptr );
}

} // namespace fontconfig 
