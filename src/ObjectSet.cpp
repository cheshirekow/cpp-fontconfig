/*
 *  \file   ObjectSet.cpp
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/ObjectSet.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

ObjectSet::ObjectSet(void* ptr):
    m_ptr(ptr)
{

}

ObjectSet ObjectSet::create()
{
    return ObjectSet( FcObjectSetCreate() );
}

bool ObjectSet::add(const char* obj)
{
    return FcObjectSetAdd( (FcObjectSet*) (m_ptr), obj);
}

void ObjectSet::destroy()
{
    FcObjectSetDestroy((FcObjectSet*) (m_ptr));
}

void* ObjectSet::get_ptr()
{
    return m_ptr;
}

const void* ObjectSet::get_ptr() const
{
    return m_ptr;
}

ObjectSet ObjectSet::build(const char* first, ...)
{

    va_list argp;
    va_start(argp, first);
    ObjectSet result( FcObjectSetVaBuild(first, argp) );
    va_end(argp);

    return result;
}


ObjectSet::Builder::Builder( ObjectSet objset ):
    m_objset(objset)
{

}

ObjectSet::Builder& ObjectSet::Builder::operator()( const char* object )
{
    m_objset.add(object);
    return *this;
}

ObjectSet ObjectSet::Builder::done()
{
    return m_objset;
}






}// namespace fontconfig
