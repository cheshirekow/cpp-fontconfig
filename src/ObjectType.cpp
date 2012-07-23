/*
 *  \file   ObjectType.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/ObjectType.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

ObjectType::ObjectType(const void* ptr):
    m_ptr(ptr)
{

}

const void* ObjectType::get_ptr() const
{
    return m_ptr;
}

const char* ObjectType::get_object()
{
    FcObjectType* ot = (FcObjectType*)m_ptr;
    return ot->object;
}

Type_t ObjectType::get_type()
{
    FcObjectType* ot = (FcObjectType*)m_ptr;
    return (Type_t)ot->type;
}




} // namespace fontconfig 
