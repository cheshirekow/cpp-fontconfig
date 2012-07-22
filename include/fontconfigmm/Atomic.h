/*
 *  \file   Atomic.h
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_ATOMIC_H_
#define FONTCONFIGMM_ATOMIC_H_

#include <fontconfigmm/common.h>

namespace fontconfig
{

/// Used for locking access to configuration files. Provides a safe way to
/// update configuration files.
/**
 *  These functions provide a safe way to update configuration files, allowing
 *  ongoing reading of the old configuration file while locked for writing and
 *  ensuring that a consistent and complete version of the configuration file
 *  is always available.
 */
class Atomic
{
    private:
        void* m_ptr;

    public:

        /// wrapp constructor
        /**
         *  wraps the pointer with this interface, does nothing else
         */
        Atomic(void* ptr);

        /// create an FcAtomic object
        /**
         *  Creates a data structure containing data needed to control access
         *  to file. Writing is done to a separate file. Once that file is
         *  complete, the original configuration file is atomically replaced
         *  so that reading process always see a consistent and complete file
         *  without the need to lock for reading.
         */
        Atomic create (const Char8_t *file);

        /// lock a file
        /**
         *  Attempts to lock the file referenced by atomic. Returns FcFalse if
         *  the file is already locked, else returns FcTrue and leaves the
         *  file locked.
         */
        bool   lock   ();

        /// return new temporary file name
        /**
         *  Returns the filename for writing a new version of the file
         *  referenced by atomic.
         */
        Char8_t* newFile();

        /// return original file name
        /**
         *  Returns the file referenced by atomic.
         */
        Char8_t* origFile();

        /// replace original with new
        /**
         *  Replaces the original file referenced by atomic with the new file.
         *  Returns FcFalse if the file cannot be replaced due to permission
         *  issues in the filesystem. Otherwise returns FcTrue.
         */
        bool replaceOrig();

        /// delete new file
        /**
         *  Deletes the new file. Used in error recovery to back out changes.
         */
        void deleteNew();

        /// unlock a file
        /**
         *  Unlocks the file.
         */
        void unlock();

        /// destroy an FcAtomic object
        /**
         *  Destroys atomic.
         */
        void destroy();
};

} // namespace fontconfig 

#endif // ATOMIC_H_
