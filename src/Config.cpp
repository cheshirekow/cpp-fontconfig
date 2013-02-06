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

/// Increment config reference count
/**
 *  Add another reference to config. Configs are freed only when the
 *  reference count reaches zero. If config is NULL, the current
 *  configuration is used. In that case this function will be similar
 *  to FcConfigGetCurrent() except that it increments the reference
 *  count before returning and the user is responsible for destroying
 *  the configuration when not needed anymore.
 */
template <>
void RefPtr<Config>::reference()
{
    if(m_ptr)
        m_ptr = FcConfigReference(m_ptr);
}

/// Destroy a configuration
/**
 *  Decrements the config reference count. If all references are gone,
 *  destroys the configuration and any data associated with it. Note
 *  that calling this function with the return from FcConfigGetCurrent
 *  will cause a new configuration to be created for use as current
 *  configuration.
 */
template <>
void RefPtr<Config>::dereference()
{
    if(m_ptr)
        FcConfigDestroy(m_ptr);
}



bool ConfigDelegate::setCurrent()
{
    return FcConfigSetCurrent( m_ptr  );
}



bool ConfigDelegate::upToDate()
{
    return FcConfigUptoDate( m_ptr );
}

bool ConfigDelegate::buildFonts()
{
    return FcConfigBuildFonts ( m_ptr );
}

StrList ConfigDelegate::getFontDirs()
{
    return StrList( FcConfigGetFontDirs( m_ptr ) );
}

StrList ConfigDelegate::getConfigDirs()
{
    return StrList( FcConfigGetConfigDirs( m_ptr  ) );
}

StrList ConfigDelegate::getConfigFiles()
{
    return StrList( FcConfigGetConfigFiles( m_ptr  ) );
}

RefPtr<Blanks> ConfigDelegate::getBlanks()
{
    return RefPtr<Blanks>( FcConfigGetBlanks( m_ptr  ) ) ;
}

StrList ConfigDelegate::getCacheDirs() const
{
    return StrList( FcConfigGetCacheDirs( m_ptr  ) );
}

int ConfigDelegate::getRescanInterval()
{
    return FcConfigGetRescanInterval( m_ptr );
}

bool ConfigDelegate::setRescanInterval(int rescanInterval)
{
    return FcConfigSetRescanInterval( m_ptr, rescanInterval );
}

RefPtr<FontSet> ConfigDelegate::getFonts(SetName_t set)
{
    return RefPtr<FontSet>( FcConfigGetFonts( m_ptr , (FcSetName)set ) );
}

bool ConfigDelegate::appFontAddFile(const Char8_t* file)
{
    return FcConfigAppFontAddFile( m_ptr , file );
}

bool ConfigDelegate::appFontAddDir(const Char8_t* dir)
{
    return FcConfigAppFontAddDir( m_ptr , dir );
}

void ConfigDelegate::appFontClear()
{
    return FcConfigAppFontClear( m_ptr );
}

bool ConfigDelegate::substituteWithPat(Pattern p, Pattern p_pat, MatchKind_t kind)
{
    return FcConfigSubstituteWithPat(
                m_ptr ,
                (FcPattern*)p.get_ptr(),
                (FcPattern*)p_pat.get_ptr(),
                (FcMatchKind)kind );
}

bool ConfigDelegate::substitute(Pattern p, MatchKind_t kind)
{
    return FcConfigSubstitute(
                m_ptr,
                (FcPattern*)p.get_ptr(),
                (FcMatchKind)kind );
}

Pattern ConfigDelegate::fontMatch(Pattern p, Result_t& result)
{
    FcResult result2;
    Pattern returnMe = Pattern(
            FcFontMatch( m_ptr,
                         (FcPattern*)p.get_ptr(),
                         &result2)
        );

    result = (Result_t)result2;

    return returnMe;
}

Pattern ConfigDelegate::fontSetMatch(
        RefPtr<FontSet>* sets, int nsets,
        Pattern pattern,
        Result_t& result)
{
    FcFontSet** ptrs = new FcFontSet*[nsets];
    for(int i=0; i < nsets; i++)
        ptrs[i] = sets[i].subvert();

    FcResult result2;

    Pattern returnMe(
            FcFontSetMatch(
                    m_ptr,
                    ptrs,
                    nsets,
                    (FcPattern*)pattern.get_ptr(),
                    &result2) );

    delete [] ptrs;

    result = (Result_t) result2;
    return returnMe;
}

Pattern ConfigDelegate::renderPrepare(Pattern pat, Pattern font)
{
    return Pattern(
        FcFontRenderPrepare( m_ptr,
                             (FcPattern*)pat.get_ptr(),
                             (FcPattern*)font.get_ptr() )
    );
}

RefPtr<FontSet> ConfigDelegate::fontSetSort(
            RefPtr<FontSet>* sets,
            int nsets,
            Pattern p,
            bool trim,
            RefPtr<CharSet>* csp,
            Result_t& result)
{
    FcFontSet** ptrs = new FcFontSet*[nsets];
    for(int i=0; i < nsets; i++)
        ptrs[i] = sets[i].subvert();

    FcCharSet*  csp2;
    FcResult    result2;

    RefPtr<FontSet> returnMe(
            FcFontSetSort(
                    m_ptr,
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

RefPtr<FontSet> ConfigDelegate::fontSort(
        Pattern p, bool trim,
        RefPtr<CharSet>* csp,
        Result_t& result)
{
    FcCharSet*  csp2;
    FcResult    result2;

    //FIXME: need to copy csp2 to csp, and add option to not return csp

    RefPtr<FontSet> returnMe(
            FcFontSort( m_ptr,
                        (FcPattern*)p.get_ptr(),
                        trim ? FcTrue : FcFalse,
                        csp ? &csp2 : (FcCharSet**)0,
                        &result2 ) );

    if(csp)
        *csp = csp2;
    result = (Result_t)result2;

    return returnMe;
}

RefPtr<FontSet> ConfigDelegate::fontSetList(
        RefPtr<FontSet>* sets, int nsets,
        Pattern p, ObjectSet os)
{
    FcFontSet** ptrs = new FcFontSet*[nsets];
    for(int i=0; i < nsets; i++)
        ptrs[i] = sets[i].subvert();

    RefPtr<FontSet> returnMe(
                FcFontSetList( m_ptr,
                                ptrs,nsets,
                                (FcPattern*)p.get_ptr(),
                                (FcObjectSet*)os.get_ptr() ) );
    delete [] ptrs;

    return returnMe;
}

RefPtr<FontSet> ConfigDelegate::fontList(Pattern p, ObjectSet os)
{
    return RefPtr<FontSet>(
            FcFontList( m_ptr,
                        (FcPattern*)p.get_ptr(),
                        (FcObjectSet*)os.get_ptr() ) );
}


bool ConfigDelegate::parseAndLoad(const Char8_t* file, bool complain)
{
    return FcConfigParseAndLoad(
                m_ptr,
                file, complain ? FcTrue : FcFalse );
}

bool ConfigDelegate::unlink(const Char8_t* dir)
{
    return FcDirCacheUnlink(dir, m_ptr );
}

void ConfigDelegate::createTagFile() const
{
    return FcCacheCreateTagFile((const FcConfig*)m_ptr);
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

RefPtr<Config> Config::create()
{
    return RefPtr<Config>( FcConfigCreate() );
}

RefPtr<Config> Config::getCurrent()
{
    // note: FcConfigGetCurrent does not increase reference count of the
    // returned pointer so we use FcConfigReference(0) which returns
    // the current but increases the reference count, we could also
    // do that part ourselves if we wnated to
    return RefPtr<Config>( FcConfigReference(0) );
}



} // namespace fontconfig 
