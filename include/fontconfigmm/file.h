/*
 *  \file   file.h
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_FILE_H_
#define FONTCONFIGMM_FILE_H_

#include <fontconfigmm/common.h>
#include <fontconfigmm/FontSet.h>
#include <fontconfigmm/StrSet.h>
#include <fontconfigmm/Blanks.h>



namespace fontconfig
{

///  scan a font file
/**
 *  Scans a single file and adds all fonts found to set. If force is FcTrue,
 *  then the file is scanned even if associated information is found in cache.
 *  If file is a directory, it is added to dirs. Whether fonts are found
 *  depends on fontconfig policy as well as the current configuration.
 *  Internally, fontconfig will ignore BDF and PCF fonts which are not in
 *  Unicode (or the effectively equivalent ISO Latin-1) encoding as those are
 *  not usable by Unicode-based applications. The configuration can ignore
 *  fonts based on filename or contents of the font file itself. Returns
 *  FcFalse if any of the fonts cannot be added (due to allocation failure).
 *  Otherwise returns FcTrue.
 */
bool fileScan( FontSet set, StrSet dirs, Blanks blanks, const Char8_t* file, bool force );

/// check whether a file is a directory
/**
 *  Returns FcTrue if file is a directory, otherwise returns FcFalse.
 */
bool fileIsDir( const Char8_t* file);

/// scan a font directory without caching it
/**
 *  If cache is not zero or if force is FcFalse, this function currently
 *  returns FcFalse. Otherwise, it scans an entire directory and adds all
 *  fonts found to set. Any subdirectories found are added to dirs. Calling
 *  this function does not create any cache files. Use FcDirCacheRead() if
 *  caching is desired.
 */
bool dirScan( FontSet set, StrSet dirs, Blanks blanks, const Char8_t *dir, bool force);



}













#endif // FILE_H_
