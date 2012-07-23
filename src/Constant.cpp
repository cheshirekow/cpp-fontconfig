/*
 *  \file   Constant.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/Constant.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

Constant::Constant(const void* ptr):
    m_ptr(ptr)
{

}

const Char8_t* Constant::get_name()
{
    const FcConstant* c = (const FcConstant*)m_ptr;
    return c->name;
}

const char* Constant::get_object()
{
    const FcConstant* c = (const FcConstant*)m_ptr;
    return c->object;
}

int Constant::get_value()
{
    const FcConstant* c = (const FcConstant*)m_ptr;
    return c->value;
}


} // namespace fontconfig 
