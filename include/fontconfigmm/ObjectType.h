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

/// wraps FcObjectType
class ObjectType
{
    private:
        const void* m_ptr;

    public:
        ObjectType(const void* ptr);

        const void* get_ptr() const;

        const char* get_object();
        Type_t get_type();
};

} // namespace fontconfig 

#endif // OBJECTTYPE_H_
