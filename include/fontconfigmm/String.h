/*
 *  \file   String.h
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_STRING_H_
#define FONTCONFIGMM_STRING_H_

#include <fontconfigmm/common.h>

namespace fontconfig
{

template <typename Ptr_t>
class StringOther;

template<>
struct StringOther<Char8_t*>
{
    typedef const Char8_t* Type;
};

template<>
struct StringOther<const Char8_t*>
{
    typedef Char8_t* Type;
};


template <typename Ptr_t>
class String
{
    public:
        typedef String<Ptr_t>           This_t;
        typedef String<Char8_t*>        String_t;
        typedef String<const Char8_t*>  ConstString_t;

        typedef typename StringOther<Ptr_t>::Type      Other_t;

    private:
        Ptr_t m_ptr;

    public:
        String(Ptr_t ptr);

        Char8_t* get_mutable_ptr();
        const Char8_t* get_const_ptr() const;

        String_t copy() const;
        String_t copyFilename() const;

        template <typename OtherPtr_t>
        String_t plus(const String<OtherPtr_t>& other) const;
        void   free();
        String_t downcase() const;

        template <typename OtherPtr_t>
        int    cmpIgnoreCase(const String<OtherPtr_t>& other);

        template <typename OtherPtr_t>
        int    cmp(const String<OtherPtr_t>& other);

        template <typename OtherPtr_t>
        ConstString_t findIgnoreCase(const String<OtherPtr_t>& needle);

        template <typename OtherPtr_t>
        ConstString_t find(const String<OtherPtr_t>& needle);

        String_t dirName() const;
        String_t baseName() const;
};


typedef String<Char8_t*>        String_t;
typedef String<const Char8_t*>  ConstString_t;






} // namespace fontconfig 

#endif // STRING_H_
