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

/// used during enumeration to safely and correctly walk the list of strings
/// even while that list is edited in the middle of enumeration.
/**
 *  String iterators are not reference counted object and the StrList class is
 *  mearly a container for the pointer. It is safe to copy an StrList but
 *  be sure to only call destroy on one of the copies.
 *
 *  Also, since StrList is a wrapper for the pointer, you should probably
 *  only allocate an StrList on the stack.
 */
class StrList
{
    private:
        void* m_ptr;
        StrList( void* ptr );

    public:
        void* get_ptr();

        /// create a string iterator
        /**
         *  Creates an iterator to list the strings in set.
         */
        static StrList create (StrSet set);

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
