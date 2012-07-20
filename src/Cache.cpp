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


const Char8_t* Cache::dir()
{
    return FcCacheDir( (FcCache*)this );
}

const Char8_t* Cache::subdir(int i)
{
    return FcCacheSubdir( (FcCache*)this, i );
}

int Cache::numSubdir()
{
    return FcCacheNumSubdir( (FcCache*)this );
}

int Cache::numFont()
{
    return FcCacheNumFont( (FcCache*)this );
}




} // namespace fontconfig
