/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of cppfontconfig.
 *
 *  cppfontconfig is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cppfontconfig is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cppfontconfig.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  @file   src/Config.cpp
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/Config.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

Config::Config(void* ptr):
    m_ptr(ptr)
{

}

Config::Config(const Config& config)
{
    m_ptr = config.m_ptr;
    FcConfigReference( (FcConfig*)m_ptr );
}

Config::~Config()
{
    FcConfigDestroy( (FcConfig*)m_ptr );
}

void* Config::get_ptr()
{
    return m_ptr;
}

const void* Config::get_ptr() const
{
    return m_ptr;
}

Char8_t* Config::home(void)
{
    return FcConfigHome();
}

bool Config::enableHome(bool enable)
{
    return FcConfigEnableHome(enable ? FcTrue : FcFalse );
}

Char8_t* Config::filename(const Char8_t* url)
{
    return FcConfigFilename(url);
}

Config Config::create()
{
    return Config( FcConfigCreate() );
}

bool Config::setCurrent()
{
    return FcConfigSetCurrent( (FcConfig*)m_ptr  );
}

Config Config::getCurrent()
{
    // note: FcConfigGetCurrent does not increase reference count of the
    // returned pointer so we use FcConfigReference(0) which returns
    // the current but increases the reference count, we could also
    // do that part ourselves if we wnated to
    return Config( FcConfigReference(0) );
}

bool Config::upToDate()
{
    return FcConfigUptoDate( (FcConfig*)m_ptr );
}

bool Config::buildFonts()
{
    return FcConfigBuildFonts ( (FcConfig*)m_ptr );
}

StrList Config::getFontDirs()
{
    return StrList( FcConfigGetFontDirs( (FcConfig*)m_ptr ) );
}

StrList Config::getConfigDirs()
{
    return StrList( FcConfigGetConfigDirs( (FcConfig*)m_ptr  ) );
}

StrList Config::getConfigFiles()
{
    return StrList( FcConfigGetConfigFiles( (FcConfig*)m_ptr  ) );
}

RefPtr<Blanks> Config::getBlanks()
{
    return RefPtr<Blanks>( FcConfigGetBlanks( (FcConfig*)m_ptr  ) ) ;
}

StrList Config::getCacheDirs() const
{
    return StrList( FcConfigGetCacheDirs( (FcConfig*)m_ptr  ) );
}

int Config::getRescanInterval()
{
    return FcConfigGetRescanInterval( (FcConfig*)m_ptr );
}

bool Config::setRescanInterval(int rescanInterval)
{
    return FcConfigSetRescanInterval( (FcConfig*)m_ptr, rescanInterval );
}

FontSet Config::getFonts(SetName_t set)
{
    return FontSet( FcConfigGetFonts( (FcConfig*)m_ptr , (FcSetName) set ) );
}

bool Config::appFontAddFile(const Char8_t* file)
{
    return FcConfigAppFontAddFile( (FcConfig*)m_ptr , file );
}

bool Config::appFontAddDir(const Char8_t* dir)
{
    return FcConfigAppFontAddDir( (FcConfig*)m_ptr , dir );
}

void Config::appFontClear()
{
    return FcConfigAppFontClear( (FcConfig*)m_ptr );
}

bool Config::substituteWithPat(Pattern p, Pattern p_pat, MatchKind_t kind)
{
    return FcConfigSubstituteWithPat(
                (FcConfig*)m_ptr ,
                (FcPattern*)p.get_ptr(),
                (FcPattern*)p_pat.get_ptr(),
                (FcMatchKind)kind );
}

bool Config::substitute(Pattern p, MatchKind_t kind)
{
    return FcConfigSubstitute(
                (FcConfig*)m_ptr,
                (FcPattern*)p.get_ptr(),
                (FcMatchKind)kind );
}

Pattern Config::fontMatch(Pattern p, Result_t& result)
{
    FcResult result2;
    Pattern returnMe = Pattern(
            FcFontMatch( (FcConfig*)m_ptr,
                         (FcPattern*)p.get_ptr(),
                         &result2)
        );

    result = (Result_t)result2;

    return returnMe;
}

Pattern Config::fontSetMatch(FontSet* sets, int nsets, Pattern pattern,
        Result_t& result)
{
    FcFontSet** ptrs = new FcFontSet*[nsets];
    for(int i=0; i < nsets; i++)
        ptrs[i] = (FcFontSet*)sets[i].get_ptr();

    FcResult result2;

    Pattern returnMe(
            FcFontSetMatch(
                    (FcConfig*)m_ptr,
                    ptrs,
                    nsets,
                    (FcPattern*)pattern.get_ptr(),
                    &result2) );

    delete [] ptrs;

    result = (Result_t) result2;
    return returnMe;
}

Pattern Config::renderPrepare(Pattern pat, Pattern font)
{
    return Pattern(
        FcFontRenderPrepare( (FcConfig*)m_ptr,
                             (FcPattern*)pat.get_ptr(),
                             (FcPattern*)font.get_ptr() )
    );
}

FontSet Config::fontSetSort(
            FontSet* sets,
            int nsets,
            Pattern p,
            bool trim,
            RefPtr<CharSet>* csp,
            Result_t& result)
{
    FcFontSet** ptrs = new FcFontSet*[nsets];
    for(int i=0; i < nsets; i++)
        ptrs[i] = (FcFontSet*)sets[i].get_ptr();

    FcCharSet*  csp2;
    FcResult    result2;

    FontSet returnMe(
            FcFontSetSort(
                    (FcConfig*)m_ptr,
                    ptrs,
                    nsets,
                    (FcPattern*)p.get_ptr(),
                    trim ? FcTrue : FcFalse,
                    csp ? &csp2 : (FcCharSet**)0,
                    &result2) );

    delete [] ptrs;

    if(csp)
        *csp = csp2;

    result = (Result_t) result2;
    return returnMe;
}

FontSet Config::fontSort(Pattern p, bool trim,
                            RefPtr<CharSet>* csp, Result_t& result)
{
    FcCharSet*  csp2;
    FcResult    result2;

    //FIXME: need to copy csp2 to csp, and add option to not return csp

    FontSet returnMe(
            FcFontSort( (FcConfig*)m_ptr,
                        (FcPattern*)p.get_ptr(),
                        trim ? FcTrue : FcFalse,
                        csp ? &csp2 : (FcCharSet**)0,
                        &result2 ) );

    if(csp)
        *csp = csp2;
    result = (Result_t)result2;

    return returnMe;
}

FontSet Config::fontSetList(FontSet* sets, int nsets, Pattern p, ObjectSet os)
{
    FcFontSet** ptrs = new FcFontSet*[nsets];
    for(int i=0; i < nsets; i++)
        ptrs[i] = (FcFontSet*)sets[i].get_ptr();

    FontSet returnMe(
                FcFontSetList( (FcConfig*)m_ptr,
                                ptrs,nsets,
                                (FcPattern*)p.get_ptr(),
                                (FcObjectSet*)os.get_ptr() ) );
    delete [] ptrs;

    return returnMe;
}

FontSet Config::fontList(Pattern p, ObjectSet os)
{
    return FontSet(
            FcFontList( (FcConfig*)m_ptr,
                        (FcPattern*)p.get_ptr(),
                        (FcObjectSet*)os.get_ptr() ) );
}


bool Config::parseAndLoad(Config config, const Char8_t* file, bool complain)
{
    return FcConfigParseAndLoad(
                (FcConfig*)config.get_ptr(),
                file, complain ? FcTrue : FcFalse );
}

bool Config::unlink(const Char8_t* dir)
{
    return FcDirCacheUnlink(dir, (FcConfig*)m_ptr );
}

void Config::createTagFile() const
{
    return FcCacheCreateTagFile((const FcConfig*)m_ptr);
}



} // namespace fontconfig 
