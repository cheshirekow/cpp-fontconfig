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
 *  \file   Atomic.cpp
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/Atomic.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{


Atomic::Atomic(void* ptr):
    m_ptr(ptr)
{
}

Atomic Atomic::create(const Char8_t* file)
{
    return Atomic(
            FcAtomicCreate(file) );
}

bool Atomic::lock()
{
    return FcAtomicLock( (FcAtomic*)m_ptr );
}

Char8_t* Atomic::newFile()
{
    return FcAtomicNewFile( (FcAtomic*)m_ptr );
}

Char8_t* Atomic::origFile()
{
    return FcAtomicOrigFile( (FcAtomic*)m_ptr );
}

bool Atomic::replaceOrig()
{
    return FcAtomicReplaceOrig( (FcAtomic*)m_ptr );
}

void Atomic::deleteNew()
{
    return FcAtomicDeleteNew( (FcAtomic*)m_ptr );
}

void Atomic::unlock()
{
    return FcAtomicUnlock( (FcAtomic*)m_ptr );
}

void Atomic::destroy()
{
    return FcAtomicDestroy( (FcAtomic*)m_ptr );
}

} // namespace fontconfig 
