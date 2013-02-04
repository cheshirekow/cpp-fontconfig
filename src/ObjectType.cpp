/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of cppfontconfig.
 *
 *  cppfontconfig is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cppfontconfig is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cppfontconfig.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  \file   ObjectType.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/ObjectType.h>
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
