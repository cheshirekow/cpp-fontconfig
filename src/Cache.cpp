/*
 *  \file   Cache.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/Cache.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

Cache::Cache(void* ptr):
    m_ptr(ptr)
{
}

void* Cache::get_ptr()
{
    return m_ptr;
}

const void* Cache::get_ptr() const
{
    return m_ptr;
}

const Char8_t* Cache::dir()
{
    return FcCacheDir( (FcCache*) (m_ptr));
}

const Char8_t* Cache::subdir(int i)
{
    return FcCacheSubdir((FcCache*) (m_ptr), i);
}

int Cache::numSubdir()
{
    return FcCacheNumSubdir((FcCache*) (m_ptr));
}



int Cache::numFont()
{
    return FcCacheNumFont((FcCache*) (m_ptr));
}




} // namespace fontconfig
