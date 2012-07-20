/*
 *  \file   Cache.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_CACHE_H_
#define FONTCONFIGMM_CACHE_H_

#include <fontconfigmm/common.h>
#include <unistd.h>

namespace fontconfig
{


/// binary compatable with FcCache
struct _Cache
{
    int         magic;          ///<  FC_CACHE_MAGIC_MMAP or FC_CACHE_ALLOC
    int         version;        ///<  FC_CACHE_CONTENT_VERSION
    intptr_t    size;           ///<  size of file
    intptr_t    dir;            ///<  offset to dir name
    intptr_t    dirs;           ///<  offset to subdirs
    int         dirs_count;     ///<  number of subdir strings
    intptr_t    set;            ///<  offset to font set
    int         checksum;       ///<  checksum of directory state
};

/// Holds information about the fonts contained in a single directory.
/**
 *  Normal
 *  applications need not worry about this as caches for font access are
 *  automatically managed by the library. Applications dealing with cache
 *  management may want to use some of these objects in their work,
 *  however the included 'fc-cache' program generally suffices for all of that.
 *
 *  @see FcCache
 */
class Cache :
    public _Cache
{
    public:
        /// Return directory of cache
        /**
         *  This function returns the directory from which the cache was
         *  constructed.
         */
        const Char8_t* dir();

        /// Returns a copy of the fontset from cache
        /**
         *  The returned fontset contains each of the font patterns from cache.
         *  This fontset may be modified, but the patterns from the cache are
         *  read-only.
         */
        //FcFontSet * copySet();

        /// Return the i'th subdirectory.
        /**
         *  The set of subdirectories stored in a cache file are indexed by
         *  this function, i should range from 0 to n-1, where n is the return
         *  value from FcCacheNumSubdir.
         */
        const Char8_t * subdir (int i);

        /// Return the number of subdirectories in cache.
        /**
         *  This returns the total number of subdirectories in the cache.
         */
        int numSubdir ();

        /// Returns the number of fonts in cache.
        /**
         *  This returns the number of fonts which would be included in the
         *  return from FcCacheCopySet.
         */
        int numFont ();

        //static bool unlink (const Char8_t *dir, FcConfig *config);

        //static bool valid (const Char8_t *cache_file);

        ///  This tries to clean up the cache directory of cache_dir. This
        /// returns FcTrue if the operation is successfully complete.
        /// otherwise FcFalse.
        //static bool clean (const Char8_t *cache_dir, bool verbose);

        /// Create CACHEDIR.TAG at cache directory.
        /**
         *  This tries to create CACHEDIR.TAG file at the cache directory
         *  registered to config.
         */
        //void createTagFile (const FcConfig *config);
};

} // namespace fontconfig 

#endif // CACHE_H_
