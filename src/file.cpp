/*
 *  \file   file.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/file.h>
#include <fontconfig/fontconfig.h>


namespace fontconfig
{

bool fileScan(FontSet set, StrSet dirs, Blanks blanks,
        const Char8_t* file, bool force)
{
    return FcFileScan(
                (FcFontSet*)set.get_ptr(),
                (FcStrSet*)dirs.get_ptr(),
                0,
                (FcBlanks*)blanks.get_ptr(),
                file,
                force ? FcTrue : FcFalse );
}

bool fileIsDir(const Char8_t* file)
{
    return FcFileIsDir(file);
}

bool dirScan(FontSet set, StrSet dirs, Blanks blanks,
        const Char8_t* dir, bool force)
{
    return FcDirScan(
                (FcFontSet*)set.get_ptr(),
                (FcStrSet*)dirs.get_ptr(),
                (FcFileCache*) 0,
                (FcBlanks*)blanks.get_ptr(),
                dir,
                force ? FcTrue : FcFalse );
}



}









