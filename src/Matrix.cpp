/*
 *  \file   Matrix.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include "fontconfigmm/Matrix.h"

namespace fontconfig
{

void Matrix::init()
{
    xx = yy = 1;
    xy = yx = 0;
}


} // namespace fontconfig
