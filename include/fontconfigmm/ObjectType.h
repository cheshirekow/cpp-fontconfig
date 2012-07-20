/*
 *  \file   ObjectType.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_OBJECTTYPE_H_
#define FONTCONFIGMM_OBJECTTYPE_H_

#include <fontconfigmm/common.h>

namespace fontconfig
{

/// same as FcObjectType
struct _ObjectType
{
    const char  *object;
    Type_t      type;
} ;

/// wraps FcObjectType
class ObjectType:
    public _ObjectType
{

};

} // namespace fontconfig 

#endif // OBJECTTYPE_H_
