/*
 *  \file   Matrix.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIG_MATRIX_H_
#define FONTCONFIG_MATRIX_H_

namespace fontconfig
{

/// equivalent to FcMatrix and safe to cast between the two
struct matrix
{
    double xx, xy, yx, yy;
};

/// wraps FcMatrix with it's member methods
/**
 *  Matrix inherits from matrix (lowercase) which is a struct with the same
 *  definition as FcMatrix. Furthermore Matrix does not declare any virtual
 *  members so it is binary compatable with FcMatrix and can be casted
 *  without reserve
 */
class Matrix :
    public matrix
{
    inline void init();
};


} // namespace fontconfig

#endif // MATRIX_H_
