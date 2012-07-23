/*
 *  \file   String.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/String.h>
#include <fontconfig/fontconfig.h>
#include <cassert>

namespace fontconfig
{

template <typename Ptr_t>
String<Ptr_t>::String(Ptr_t ptr):
    m_ptr(ptr)
{

}


template <>
Char8_t* String<Char8_t*>::get_mutable_ptr()
{
    return m_ptr;
}

template <>
Char8_t* String<const Char8_t*>::get_mutable_ptr()
{
    assert(0 == "ConstString_t cannot access a mutable pointer");
    return 0;
}

template <typename Ptr_t>
String_t String<Ptr_t>::copy() const
{
    return String_t( FcStrCopy(m_ptr) );
}

template <typename Ptr_t>
String_t String<Ptr_t>::copyFilename() const
{
    return String( FcStrCopyFilename(m_ptr) );
}

template <typename Ptr_t>
template <typename OtherPtr_t>
String_t String<Ptr_t>::plus(const String<OtherPtr_t>& other) const
{
    return String_t( FcStrPlus(m_ptr, other.m_ptr) );
}

template <>
void String<Char8_t*>::free()
{
    FcStrFree(m_ptr);
}

template <>
void String<const Char8_t*>::free()
{
    assert(0 == "ConstString_t cannot be free'd");
}

template <typename Ptr_t>
String_t String<Ptr_t>::downcase() const
{
    return String_t(FcStrDowncase(m_ptr) );
}

template <typename Ptr_t>
template <typename OtherPtr_t>
int String<Ptr_t>::cmpIgnoreCase(const String<OtherPtr_t>& other)
{
    return FcStrCmpIgnoreCase( m_ptr, other.m_ptr );
}

template <typename Ptr_t>
template <typename OtherPtr_t>
int String<Ptr_t>::cmp(const String<OtherPtr_t>& other)
{
    return FcStrCmp( m_ptr, other.m_ptr );
}

template <typename Ptr_t>
template <typename OtherPtr_t>
ConstString_t String<Ptr_t>::findIgnoreCase(const String<OtherPtr_t>& needle)
{
    return ConstString_t( FcStrStrIgnoreCase(needle.m_ptr, m_ptr) );
}

template <typename Ptr_t>
template <typename OtherPtr_t>
ConstString_t String<Ptr_t>::find(const String<OtherPtr_t>& needle)
{
    return ConstString_t( FcStrStr(needle.m_ptr, m_ptr) );
}

template <typename Ptr_t>
String_t String<Ptr_t>::dirName() const
{
    return String_t( FcStrDirname(m_ptr) );
}

template <typename Ptr_t>
String_t String<Ptr_t>::baseName() const
{
    return String_t( FcStrBasename(m_ptr) );
}


} // namespace fontconfig 
