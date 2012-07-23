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
