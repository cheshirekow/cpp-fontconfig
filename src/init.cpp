/*
 *  \file   init.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/init.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{


Config initLoadConfig()
{
    return Config( FcInitLoadConfig() );
}

Config initLoadConfigAndFonts()
{
    return Config( FcInitLoadConfigAndFonts() );
}

bool init()
{
    return FcInit();
}

void fini()
{
    FcFini();
}

int getVersion()
{
    return FcGetVersion();
}

bool initReinitialize()
{
    return FcInitReinitialize();
}

bool initBringUptoDate()
{
    return FcInitBringUptoDate();
}


}








