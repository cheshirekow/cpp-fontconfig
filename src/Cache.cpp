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

bool Cache::dirClean(const Char8_t* cache_dir, bool verbose)
{
    return FcDirCacheClean(cache_dir, verbose ? FcTrue: FcFalse );
}

bool Cache::dirValid(const Char8_t* dir)
{
    return FcDirCacheValid(dir);
}

Cache Cache::load(const Char8_t* dir, Config config, Char8_t** cache_file)
{
    return Cache(
            FcDirCacheLoad(dir, (FcConfig*)config.get_ptr(), cache_file)
    );
}

Cache Cache::read(const Char8_t* dir, bool force, Config config)
{
    return Cache(
            FcDirCacheRead(dir, force ? FcTrue : FcFalse, (FcConfig*)config.get_ptr() )
    );
}

Cache Cache::loadFile(const Char8_t* cache_file, struct stat* file_stat)
{
    return Cache(
            FcDirCacheLoadFile(cache_file, file_stat )
    );
}

void Cache::unload()
{
}




} // namespace fontconfig
