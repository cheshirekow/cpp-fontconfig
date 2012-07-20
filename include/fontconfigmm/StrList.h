/*
 *  \file   StrList.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_STRLIST_H_
#define FONTCONFIGMM_STRLIST_H_

#include <fontconfigmm/common.h>
#include <fontconfigmm/StrSet.h>

namespace fontconfig
{

struct _StrList
{
    StrSet      *set;
    int         n;
};

/// used during enumeration to safely and correctly walk the list of strings
/// even while that list is edited in the middle of enumeration.
class StrList
{
    public:
        /// create a string iterator
        /**
         *  Creates an iterator to list the strings in set.
         */
        static StrList* create (StrSet *set);

        /// get next string in iteration
        /**
         *  Returns the next string in set.
         */
        Char8_t* next ();

        /// destroy a string iterator
        /**
         *  Destroys the enumerator list.
         */
        void done();
};

} // namespace fontconfig 

#endif // STRLIST_H_
