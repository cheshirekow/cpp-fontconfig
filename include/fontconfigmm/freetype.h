/*
 *  \file   freetype.h
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_FREETYPE_H_
#define FONTCONFIGMM_FREETYPE_H_

#include <fontconfigmm/common.h>

namespace freetype
{
    class Face;
}

namespace fontconfig {
namespace ft         {

/// map Unicode to glyph id
/**
 *  Maps a Unicode char to a glyph index. This function uses information from
 *  several possible underlying encoding tables to work around broken fonts.
 *  As a result, this function isn't designed to be used in performance
 *  sensitive areas; results from this function are intended to be cached by
 *  higher level functions.
 */
Char32_t CharIndex(freetype::Face face, Char32_t ucs4);

/// compute Unicode coverage
/**
 *  Scans a FreeType face and returns the set of encoded Unicode chars. This
 *  scans several encoding tables to build as complete a list as possible. If
 *  'blanks' is not 0, the glyphs in the font are examined and any blank
 *  glyphs not in 'blanks' are not placed in the returned FcCharSet.
 */
CharSet CharSet(freetype::Face face, Blanks blanks);

/// compute Unicode coverage and spacing type
/**
 *  Scans a FreeType face and returns the set of encoded Unicode chars. This
 *  scans several encoding tables to build as complete a list as possible. If
 *  'blanks' is not 0, the glyphs in the font are examined and any blank
 *  glyphs not in 'blanks' are not placed in the returned FcCharSet. spacing
 *  receives the computed spacing type of the font, one of FC_MONO for a font
 *  where all glyphs have the same width, FC_DUAL, where the font has glyphs
 *  in precisely two widths, one twice as wide as the other, or FC_PROPORTIONAL
 *  where the font has glyphs of many widths.
 */
CharSet CharSetAndSpacing(freetype::Face face, Blanks blanks, int *spacing);

/// compute pattern from font file (and index)
/**
 *  Constructs a pattern representing the 'id'th font in 'file'. The number of
 *  fonts in 'file' is returned in 'count'.
 */
Pattern Query(const Char8_t *file, int id, Blanks blanks, int *count);

/// compute pattern from FT_Face
/**
 *  Constructs a pattern representing 'face'. 'file' and 'id' are used solely
 *  as data for pattern elements (FC_FILE, FC_INDEX and sometimes FC_FAMILY).
 */
Pattern QueryFace(const freetype::Face& face, const Char8_t *file, int id, Blanks blanks);


}
}














#endif // FREETYPE_H_
