/*
 *  \file   Atomic.cpp
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/Atomic.h>
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
