/*
 *  \file   StrSet.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_STRSET_H_
#define FONTCONFIGMM_STRSET_H_

#include <fontconfigmm/common.h>

namespace fontconfig
{

struct _StrSet
{
    int         ref;    /* reference count */
    int         num;
    int         size;
    Char8_t     **strs;
};

/// holds a list of strings that can be appended to and enumerated.
/**
 *  Its unique characteristic is that the enumeration works even while strings
 *  are appended during enumeration.
 */
class StrSet
{
    public:
        /// create a string set
        /**
         *  Create an empty set.
         */
        static StrSet*  create(void);

        /// check set for membership
        /**
         *  Returns whether s is a member of set.
         */
        bool setMember (const Char8_t *s);

        ///  check sets for equality
        /**
         *  Returns whether set_a contains precisely the same strings as set_b.
         *  Ordering of strings within the two sets is not considered.
         */
        bool equal (StrSet *other);

        /// add to a string set
        /**
         *  Adds a copy of s to set.
         */
        bool add (const Char8_t *s);

        /// add a filename to a string set
        /**
         *  Adds a copy s to set, The copy is created with FcStrCopyFilename so
         *  that leading '~' values are replaced with the value of the HOME
         *  environment variable.
         */
        bool addFilename (const Char8_t *s);

        /// delete from a string set
        /**
         *  Removes s from set, returning FcTrue if s was a member else FcFalse.
         */
        bool del (const Char8_t *s);

        /// destroy a string set
        /**
         *  Destroys set.
         */
        void destroy ();
};

} // namespace fontconfig 

#endif // STRSET_H_
