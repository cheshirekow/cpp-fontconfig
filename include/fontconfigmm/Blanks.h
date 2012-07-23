/*
 *  \file   Blanks.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_BLANKS_H_
#define FONTCONFIGMM_BLANKS_H_

#include <fontconfigmm/common.h>

namespace fontconfig
{


///< holds a list of Unicode chars which are expected to be blank
/**
 *  unexpectedly
 *  blank chars are assumed to be invalid and are elided from the charset
 *  associated with the font.
 *
 *  Blanks structures are not reference counted. It is safe to pass around
 *  copies of this object, however you must remember to call destroy on
 *  one and only one copy when you're done with it
 *
 *  It contains only one data member which is a pointer
 *  and the copy constructor will simply copy that pointer so there is no
 *  reason to allocate a Blank on the heap.
 */
class Blanks
{
    private:
        void* m_ptr;

    public:
        /// Constructs a new Blanks object wrapping the underlying
        /// c structure
        Blanks(void* ptr);

        /// Destroys an FcBlanks object, freeing any associated memory.
        /**
         *  @see FcBlanksDestroy
         */
        void destroy();

        /// Add a character to an FcBlanks
        /**
         *  Adds a single character to an FcBlanks object, returning FcFalse if
         *  this process ran out of memory.
         *
         *  @see FcBlanksAdd
         */
        bool add( Char32_t ucs4 );

        /// Query membership in an FcBlanks
        /**
         *  Returns whether the specified FcBlanks object contains the
         *  indicated Unicode value.
         *  @see FcBlanksIsMember
         */
        bool isMember( Char32_t ucs4 );

        /// Creates an empty FcBlanks oject
        /**
         *  @see FcBlanksCreate
         */
        static Blanks* create();
};

} // namespace fontconfig 

#endif // BLANKS_H_
