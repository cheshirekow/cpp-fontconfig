/*
 *  \file   common.h
 *
 *  \date   Jul 19, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_COMMON_H_
#define FONTCONFIGMM_COMMON_H_





#define FCMM_DONT_CONSTRUCT( TYPE ) \
private:                        \
    template <typename T>       \
    TYPE( const T& param )      \
    {                           \
        struct TYPE##_is_an_opaque_type_use_create_method{} obj;    \
        int i = obj;            \
    }                           \


namespace fontconfig
{


const unsigned int MAJOR    = 2;
const unsigned int MINOR    = 10;
const unsigned int REVISION = 0;
const unsigned int VERSION  = ((MAJOR * 10000) + (MINOR * 100) + (REVISION));

/**
 * Current font cache file format version
 * This is appended to the cache files so that multiple
 * versions of the library will peacefully coexist
 *
 * Change this value whenever the disk format for the cache file
 * changes in any non-compatible way.  Try to avoid such changes as
 * it means multiple copies of the font information.
 */
const char* CACHE_VERSION = "3";


typedef unsigned char   Char8_t;
typedef unsigned short  Char16_t;
typedef unsigned int    Char32_t;
typedef int             Bool_t;
typedef int             Object_t;

/// property keys
const char* FAMILY          = "family";         ///< String
const char* STYLE           = "style";          ///< String
const char* SLANT           = "slant";          ///< Int
const char* WEIGHT          = "weight";         ///< Int
const char* SIZE            = "size";           ///< Double
const char* ASPECT          = "aspect";         ///< Double
const char* PIXEL_SIZE      = "pixelsize";      ///< Double
const char* SPACING         = "spacing";        ///< Int
const char* FOUNDRY         = "foundry";        ///< String
const char* ANTIALIAS       = "antialias";      ///< Bool (depends)
const char* HINTING         = "hinting";        ///< Bool (true)
const char* HINT_STYLE      = "hintstyle";      ///< Int
const char* VERTICAL_LAYOUT = "verticallayout"; ///< Bool (false)
const char* AUTOHINT        = "autohint";       ///< Bool (false)

/* GLOBAL_ADVANCE is deprecated. this is simply ignored on freetype 2.4.5 or later */
const char* GLOBAL_ADVANCE  = "globaladvance";  ///< Bool (true)
const char* WIDTH           = "width";          ///< Int
const char* FILE            = "file";           ///< String
const char* INDEX           = "index";          ///< Int
const char* FT_FACE         = "ftface";         ///< FT_Face
const char* RASTERIZER      = "rasterizer";     ///< String
const char* OUTLINE         = "outline";        ///< Bool
const char* SCALABLE        = "scalable";       ///< Bool
const char* SCALE           = "scale";          ///< double
const char* DPI             = "dpi";            ///< double
const char* RGBA            = "rgba";           ///< Int
const char* MINSPACE        = "minspace";       ///< Bool use minimum line spacing
const char* SOURCE          = "source";         ///< String (deprecated)
const char* CHARSET         = "charset";        ///< CharSet
const char* LANG            = "lang";           ///< String RFC 3066 langs
const char* FONTVERSION     = "fontversion";    ///< Int from 'head' table
const char* FULLNAME        = "fullname";       ///< String
const char* FAMILYLANG      = "familylang";     ///< String RFC 3066 langs
const char* STYLELANG       = "stylelang";      ///< String RFC 3066 langs
const char* FULLNAMELANG    = "fullnamelang";   ///< String RFC 3066 langs
const char* CAPABILITY      = "capability";     ///< String
const char* FONTFORMAT      = "fontformat";     ///< String
const char* EMBOLDEN        = "embolden";       ///<  Bool - true if emboldening needed
const char* EMBEDDED_BITMAP = "embeddedbitmap"; ///< Bool - true to enable embedded bitmaps
const char* DECORATIVE      = "decorative";     ///< Bool - true if style is a decorative variant
const char* LCD_FILTER      = "lcdfilter";      ///< Int
const char* NAMELANG        = "namelang";       ///< String RFC 3866 langs

// these "3" should probably not be written by hand, but I'm trying to
// avoid any macros... this can be done with boost::mpl
// (http://stackoverflow.com/questions/4693819/c-template-string-concatenation)
// but it seems kind of ridiculous to add that dependency to save 6 seconds
// of maintanance
const char* CACHE_SUFFIX    = ".cache-3";
const char* DIR_CACHE_FILE  = "fonts.cache-3";
const char* USER_CACHE_FILE = ".fonts.cache-3";

// Adjust outline rasterizer
const char* CHAR_WIDTH  = "charwidth";  ///< Int
const char* CHAR_HEIGHT = "charheight"; ///< Int
const char* MATRIX      = "matrix";     ///< FcMatrix



namespace weight
{

const unsigned int THIN         = 0;
const unsigned int EXTRALIGHT   = 40;
const unsigned int ULTRALIGHT   = EXTRALIGHT;
const unsigned int LIGHT        = 50;
const unsigned int BOOK         = 75;
const unsigned int REGULAR      = 80;
const unsigned int NORMAL       = REGULAR;
const unsigned int MEDIUM       = 100;
const unsigned int DEMIBOLD     = 180;
const unsigned int SEMIBOLD     = DEMIBOLD;
const unsigned int BOLD         = 200;
const unsigned int EXTRABOLD    = 205;
const unsigned int ULTRABOLD    = EXTRABOLD;
const unsigned int BLACK        = 210;
const unsigned int HEAVY        = BLACK;
const unsigned int EXTRABLACK   = 215;
const unsigned int ULTRABLACK   = EXTRABLACK;

}


namespace slant
{

const unsigned int ROMAN    = 0;
const unsigned int ITALIC   = 100;
const unsigned int OBLIQUE  = 110;

}

namespace width
{

const unsigned int ULTRACONDENSED   = 50;
const unsigned int EXTRACONDENSED   = 63;
const unsigned int CONDENSED        = 75;
const unsigned int SEMICONDENSED    = 87;
const unsigned int NORMAL           = 100;
const unsigned int SEMIEXPANDED     = 113;
const unsigned int EXPANDED         = 125;
const unsigned int EXTRAEXPANDED    = 150;
const unsigned int ULTRAEXPANDED    = 200;

}

namespace rgba
{

const unsigned int UNKNOWN  = 0;
const unsigned int RGB      = 1;
const unsigned int BGR      = 2;
const unsigned int VRGB     = 3;
const unsigned int VBGR     = 4;
const unsigned int NONE     = 5;

}

namespace hint
{

const unsigned int NONE     = 0;
const unsigned int SLIGHT   = 1;
const unsigned int MEDIUM   = 2;
const unsigned int FULL     = 3;

}

namespace lcd
{

const unsigned int NONE     = 0;
const unsigned int DEFAULT  = 1;
const unsigned int LIGHT    = 2;
const unsigned int LEGACY   = 3;

}

namespace type
{

enum Type {
    Void,
    Integer,
    Double,
    String,
    Bool,
    Matrix,
    CharSet,
    FTFace,
    LangSet
};

}

typedef type::Type Type_t;

namespace match
{

enum MatchKind
{
    Pattern,
    Font,
    Scan
};

}

typedef match::MatchKind MatchKind_t;

namespace qual
{

enum Qual
{
    Any,
    All,
    First,
    NotFirst
};


}

typedef qual::Qual Qual_t;


namespace op
{

enum Op
{
    Integer, Double, String, Matrix, Range, Bool, CharSet, LangSet,
    Nil,
    Field, Const,
    Assign, AssignReplace,
    PrependFirst, Prepend, Append, AppendLast,
    Quest,
    Or, And, Equal, NotEqual,
    Contains, Listing, NotContains,
    Less, LessEqual, More, MoreEqual,
    Plus, Minus, Times, Divide,
    Not, Comma, Floor, Ceil, Round, Trunc,
    Invalid
};

}

typedef op::Op Op_t;


namespace lang
{

enum Result
{
    Equal                 = 0,
    DifferentCountry      = 1,
    DifferentTerritory    = 1,
    DifferentLang         = 2
};

}

typedef lang::Result LangResult_t;


namespace result
{

enum Result
{
    Match,
    NoMatch,
    TypeMismatch,
    NoId,
    OutOfMemory
};

}

typedef result::Result Result_t;


namespace setname
{

enum SetName
{
    System      = 0,
    Application = 1
};

}

typedef setname::SetName SetName_t;

}













#endif // COMMON_H_
