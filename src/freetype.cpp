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
 *  \file   freetype.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */


#include <fontconfigmm/freetype.h>
#include <fontconfig/fontconfig.h>
#include <fontconfig/fcfreetype.h>

namespace fontconfig {
namespace         ft {


Char32_t CharIndex(freetype::Face face, Char32_t ucs4)
{
    return FcFreeTypeCharIndex( (FT_FACE) face.get_ptr(), ucs4 );
}

CharSet CharSet(freetype::Face face, Blanks blanks)
{
    return FcFreeTypeCharSet(   (FT_FACE) face.get_ptr(),
                                (FcBlanks*) blanks.get_ptr() );
}

CharSet CharSetAndSpacing(freetype::Face face, Blanks blanks,
        int* spacing)
{
    return FcFreeTypeCharSetAndSpacing(
                                (FT_FACE)face.get_ptr(),
                                (Blanks*)blanks.get_ptr() );
}

Pattern Query(const Char8_t* file, int id, Blanks blanks,
        int* count)
{
    return Pattern(
            FcFreeTypeQuery(file, id, (FcBlanks*)blanks.get_ptr(), count ) );
}

Pattern QueryFace(const freetype::Face& face,
        const Char8_t* file, int id, Blanks blanks)
{
    return Pattern(
            FcFreeTypeQueryFace(
                    (FT_FACE)face.get_ptr(),
                    id,
                    (FcBlanks*)blanks.get_ptr() ) );
}





}
}







