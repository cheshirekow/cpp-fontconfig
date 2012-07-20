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

///< same as _FcBlanks
/**
 *  holds a list of Unicode chars which are expected to be blank; unexpectedly
 *  blank chars are assumed to be invalid and are elided from the charset
 *  associated with the font.
 */
struct _Blanks
{
    int         nblank;
    int         sblank;
    Char32_t    *blanks;
};

class Blanks :
    public _Blanks
{
    private:
        /// Don't use the constructor, use create()
        /**
         *  The constructor should never be used as I haven't investigated
         *  what is actually going on in FcBlanksCreate.
         */
        Blanks();

    public:
        /// Destroys an FcBlanks object, freeing any associated memory.
        /**
         *  @see FcBlanksDestroy
         */
        ~Blanks();

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
