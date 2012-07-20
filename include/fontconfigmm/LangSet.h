/*
 *  \file   LangSet.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_LANGSET_H_
#define FONTCONFIGMM_LANGSET_H_

#include <fontconfigmm/common.h>
#include <fontconfigmm/StrSet.h>

namespace fontconfig
{

namespace lang
{

const unsigned int NUM_CHAR_SET = 243;
const unsigned int NUM_SET_MAP  = 8;

}

struct _LangSet
{
    StrSet*   extra;
    Char32_t  map_size;
    Char32_t  map[lang::NUM_SET_MAP];
};

/// An LangSet is an abstract type that holds the set of languages supported
/// by a font.
/**
 *  Operations to build and compare these sets are provided. These are computed
 *  for a font based on orthographic information built into the fontconfig
 *  library. Fontconfig has orthographies for all of the ISO 639-1 languages
 *  except for MS, NA, PA, PS, QU, RN, RW, SD, SG, SN, SU and ZA. If you have
 *  orthographic information for any of these languages, please submit them.
 */
class LangSet
{
    public:
        LangSet();

        /// create a langset object
        /**
         *  FcLangSetCreate creates a new FcLangSet object.
         */
        static LangSet*  create (void);

        /// destroy a langset object
        /**
         *  FcLangSetDestroy destroys a FcLangSet object, freeing all memory
         *  associated with it.
         */
        void  destroy ();

        /// copy a langset object
        /**
         *  FcLangSetCopy creates a new FcLangSet object and populates it with
         *  the contents of ls.
         */
        LangSet*  copy ();

        /// add a language to a langset
        /**
         *  lang is added to ls. lang should be of the form Ll-Tt where Ll is
         *  a two or three letter language from ISO 639 and Tt is a territory
         *  from ISO 3166.
         */
        bool  add (const Char8_t *lang);

        /// delete a language from a langset
        /**
         *  lang is removed from ls. lang should be of the form Ll-Tt where Ll
         *  is a two or three letter language from ISO 639 and Tt is a
         *  territory from ISO 3166.
         */
        bool  del (const Char8_t *lang);

        /// test langset for language support
        /**
         *  FcLangSetHasLang checks whether ls supports lang. If ls has a
         *  matching language and territory pair, this function returns
         *  FcLangEqual. If ls has a matching language but differs in which
         *  territory that language is for, this function returns
         *  FcLangDifferentTerritory. If ls has no matching language, this
         *  function returns FcLangDifferentLang.
         */
        LangResult_t  hasLang (const Char8_t *lang);

        /// compare language sets
        /**
         *  FcLangSetCompare compares language coverage for ls_a and ls_b. If
         *  they share any language and territory pair, this function returns
         *  FcLangEqual. If they share a language but differ in which
         *  territory that language is for, this function returns
         *  FcLangDifferentTerritory. If they share no languages in common,
         *  this function returns FcLangDifferentLang.
         */
        LangResult_t  compare (const LangSet *lsb);

        /// check langset subset relation
        /**
         *  FcLangSetContains returns FcTrue if ls_a contains every language
         *  in ls_b. ls_a will 'contain' a language from ls_b if ls_a has
         *  exactly the language, or either the language or ls_a has no
         *  territory.
         */
        bool  contains (const LangSet *lsb);

        /// test for matching langsets
        /**
         *  Returns FcTrue if and only if ls_a supports precisely the same
         *  language and territory combinations as ls_b.
         */
        bool  equal (const LangSet *lsb);

        /// return a hash value for a langset
        /**
         *  This function returns a value which depends solely on the
         *  languages supported by ls. Any language which equals ls will have
         *  the same result from FcLangSetHash. However, two langsets with the
         *  same hash value may not be equal.
         */
        Char32_t  hash ();

        /// Get list of languages
        /**
         *
         */
        StrSet * getLangs ();

        /// Add langsets
        /**
         *  Returns a set including only those languages found in either
         *  ls_a or ls_b.
         */
        LangSet *  creatUnion (const LangSet *b);

        /// Subtract langsets
        /**
         *  Returns a set including only those languages found in ls_a but
         *  not in ls_b.
         */
        LangSet *  subtract (const LangSet *b);
};

} // namespace fontconfig 

#endif // LANGSET_H_
