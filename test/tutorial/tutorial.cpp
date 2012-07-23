/*
 *  \file   tutorial.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/fontconfigmm.h>
#include <iostream>

int main( int argc, char** argv )
{
    // shorten namespace for ease
    namespace fc = fontconfig;

    // we'll use the second argument as the font name
    if( argc < 2 )
    {
        std::cerr << "usage: tutorial [Font Name]" << std::endl;
        return 1;
    }

    // initialize font config
    fc::init();

    // we put this in a separate block because we want the pattern objects
    // to destruct before we call fc::fini... otherwise (and I'm not sure but)
    // it might be possible that the patterns will try to free memory that
    // fontconfig free's on fc::fini
    {
        // create a pattern to search for
        fc::Pattern pat = fc::Pattern::create();

        // type safe version, but will not give compiler error if the
        // argument is the wrong type for the key
        //pat.add(fc::FAMILY, (fc::Char8_t*)argv[1]);

        // type safe but inextensible version that works only on built in
        // types, will give a compiler error if the parameter is not the
        // right type for the key
        pat.add<fc::key::FAMILY>( (const fc::Char8_t*)argv[1] );

        // get a pointer to the default configuration
        fc::Config  config = fc::Config::getCurrent();

        // perform substitutions
        pat.substitute(fc::match::Pattern);
        pat.defaultSubstitute();

        // get the match
        fc::Result_t result;
        fc::Pattern match = config.fontMatch(pat, result);

        // get the closest matching font file
        fc::Char8_t*    file;
        int             index;

        match.get( fc::FILE, 0, file);
        match.get( fc::INDEX, 0, index);

        // at this point, we probably want to use freetype to get a face

        // but for now, we'll just print the font file
        std::cout << "Font found for query [" << argv[1] << "] at "
                  << file << std::endl;

        // no need to do cleanup, pattern and match will free their memory
        // when their destructors are called
    }

    // unload fontconfig
    fc::fini();

    return 0;
}




