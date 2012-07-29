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
 *  \file   Constant.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/Constant.h>
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
