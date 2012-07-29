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
 *  \file   Constant.h
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_CONSTANT_H_
#define FONTCONFIGMM_CONSTANT_H_

#include <cppfontconfig/common.h>

namespace fontconfig
{

class Constant
{
    private:
        const void* m_ptr;

    public:
        Constant(const void* ptr);

        const Char8_t*  get_name();
        const char*     get_object();
        int             get_value();
};

} // namespace fontconfig 

#endif // CONSTANT_H_
