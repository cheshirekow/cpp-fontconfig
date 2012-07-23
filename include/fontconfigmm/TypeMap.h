/*
 *  \file   TypeMap.h
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_TYPEMAP_H_
#define FONTCONFIGMM_TYPEMAP_H_

#include <fontconfigmm/common.h>
#include <fontconfigmm/CharSet.h>

#define FCMM_MAP_KEY(KEY,TYPE)                  \
template<>                                      \
struct TypeMap<key::KEY>                        \
{                                               \
    typedef TYPE Type;                          \
    static const char* const object;            \
};                                              \
                                                \


namespace fontconfig
{


/// Ensures typesafety of pattern add,get by mapping property keys to their
/// type in a compile-time queriable map
template <Key_t key>
struct TypeMap;


// This does not work, a const char* const cant be used as a template parameter,
// though I'm not sure why... isn't it a constant expression? I guess not, I
// guess it's an address.

// we could perhaps alter type map to provide both the type and the string
// and then map to the strings using an enum. In other words
// use
// template < BuiltInTypes TypeId >
// struct TypeMap;
//
// template <>
// struct TypeMap<object::FAMILY>
// {
//    typedef   const Char8_t*  Type;
//    const char* const object = fontconfig::Family;
// }
//
// but then this becomes nothing more than a template version of the
// ObjectType structure... so I'm no sure what really to do here
//
// I guess it would still be useful... but only for the built int types,
// i.e. the ones here
FCMM_MAP_KEY(FAMILY          , const Char8_t*    );
FCMM_MAP_KEY(STYLE           , const Char8_t*    );
FCMM_MAP_KEY(SLANT           , int               );
FCMM_MAP_KEY(WEIGHT          , int               );
FCMM_MAP_KEY(SIZE            , double            );
FCMM_MAP_KEY(ASPECT          , double            );
FCMM_MAP_KEY(PIXEL_SIZE      , double            );
FCMM_MAP_KEY(SPACING         , int               );
FCMM_MAP_KEY(FOUNDRY         , const Char8_t*    );
FCMM_MAP_KEY(ANTIALIAS       , bool              );
FCMM_MAP_KEY(HINTING         , bool              );
FCMM_MAP_KEY(HINT_STYLE      , int               );
FCMM_MAP_KEY(VERTICAL_LAYOUT , bool              );
FCMM_MAP_KEY(AUTOHINT        , bool              );
FCMM_MAP_KEY(GLOBAL_ADVANCE  , bool              );
FCMM_MAP_KEY(WIDTH           , int               );
FCMM_MAP_KEY(FILE            , const Char8_t*    );
FCMM_MAP_KEY(INDEX           , int               );
//FCMM_MAP_KEY(FT_FACE         , FT_Face );
FCMM_MAP_KEY(RASTERIZER      , const Char8_t*    );
FCMM_MAP_KEY(OUTLINE         , bool              );
FCMM_MAP_KEY(SCALABLE        , bool              );
FCMM_MAP_KEY(SCALE           , double            );
FCMM_MAP_KEY(DPI             , double            );
FCMM_MAP_KEY(RGBA            , int               );
FCMM_MAP_KEY(MINSPACE        , bool              );
FCMM_MAP_KEY(SOURCE          , const Char8_t*    );
FCMM_MAP_KEY(CHARSET         , CharSet           );
FCMM_MAP_KEY(LANG            , const Char8_t*    );
FCMM_MAP_KEY(FONTVERSION     , int               );
FCMM_MAP_KEY(FULLNAME        , const Char8_t*    );
FCMM_MAP_KEY(FAMILYLANG      , const Char8_t*    );
FCMM_MAP_KEY(STYLELANG       , const Char8_t*    );
FCMM_MAP_KEY(FULLNAMELANG    , const Char8_t*    );
FCMM_MAP_KEY(CAPABILITY      , const Char8_t*    );
FCMM_MAP_KEY(FONTFORMAT      , const Char8_t*    );
FCMM_MAP_KEY(EMBOLDEN        , bool              );
FCMM_MAP_KEY(EMBEDDED_BITMAP , bool              );
FCMM_MAP_KEY(DECORATIVE      , bool              );
FCMM_MAP_KEY(LCD_FILTER      , int               );
FCMM_MAP_KEY(NAMELANG        , const Char8_t*    );



}













#endif // TYPEMAP_H_