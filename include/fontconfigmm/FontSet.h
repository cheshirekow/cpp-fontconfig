/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of Fontconfigmm.
 *
 *  Fontconfigmm is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Fontconfigmm is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Fontconfigmm.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  \file   FontSet.h
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_FONTSET_H_
#define FONTCONFIGMM_FONTSET_H_

#include <fontconfigmm/common.h>
#include <fontconfigmm/Pattern.h>

namespace fontconfig
{

/// An FcFontSet simply holds a list of patterns; these are used to return the
/// results of listing available fonts.
/**
 *  An FcFontSet contains a list of FcPatterns. Internally fontconfig uses
 *  this data structure to hold sets of fonts. Externally, fontconfig returns
 *  the results of listing fonts in this format. 'nfont' holds the number of
 *  patterns in the 'fonts' array; 'sfont' is used to indicate the size of
 *  that array.
 */
class FontSet
{
    private:
        void* m_ptr;

    public:
        ///
        /**
         *
         */
        FontSet( void* ptr );

        ///
        /**
         *
         */
        void* get_ptr();

        ///
        /**
         *
         */
        const void* get_ptr() const;

        /// Create a font set
        /**
         *  Creates an empty font set.
         */
        FontSet create (void);

        /// Destroy a font set
        /**
         *  Destroys a font set. Note that this destroys any referenced
         *  patterns as well.
         */
        void destroy ();

        /// Add to a font set
        /**
         *  Adds a pattern to a font set. Note that the pattern is not copied
         *  before being inserted into the set. Returns FcFalse if the pattern
         *  cannot be inserted into the set (due to allocation failure).
         *  Otherwise returns FcTrue.
         */
        bool add(Pattern font);

        /// Print a set of patterns to stdout
        void print();



};

} // namespace fontconfig 

#endif // FONTSET_H_
