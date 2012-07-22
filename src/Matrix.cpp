/*
 *  \file   Matrix.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/Matrix.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

Matrix::Matrix()
{
    m_ptr = new FcMatrix;
}

Matrix::Matrix(void* ptr):
    m_ptr(ptr)
{
}

Matrix::Matrix(const Matrix& other)
{
    m_ptr = FcMatrixCopy( (FcMatrix*) (other.m_ptr));
}

Matrix::~Matrix()
{
    if (m_ptr)
        delete (FcMatrix*) (m_ptr);
}
void* Matrix::get_ptr()
{
    return m_ptr;
}

const void* Matrix::get_ptr() const
{
    return m_ptr;
}

Matrix& Matrix::operator =(const Matrix& other)
{
    FcMatrix* this_m = (FcMatrix*) (m_ptr);
    FcMatrix* other_m = (FcMatrix*) (other.m_ptr);
    *this_m = *other_m;
    return *this;
}

double& Matrix::xx()
{
    return ((FcMatrix*) (m_ptr))->xx;
}

double& Matrix::xy()
{
    return ((FcMatrix*) (m_ptr))->xy;
}

double& Matrix::yx()
{
    return ((FcMatrix*) (m_ptr))->yx;
}

double& Matrix::yy()
{
    return ((FcMatrix*) (m_ptr))->yy;
}



void Matrix::init()
{
    xx() = yy() = 1;
    xy() = yx() = 0;
}

Matrix Matrix::copy()
{
    return Matrix( FcMatrixCopy( (FcMatrix*) m_ptr ) );
}

bool Matrix::equal(const Matrix& other) const
{
    return FcMatrixEqual(   (const FcMatrix*)m_ptr,
                            (const FcMatrix*)other.m_ptr );
}

void Matrix::rotate(double c, double s)
{
    FcMatrixRotate( (FcMatrix*)m_ptr, c, s );
}

void Matrix::scale(double sx, double sy)
{
    FcMatrixScale( (FcMatrix*)m_ptr, sx, sy );
}

void Matrix::shear(double sh, double sv)
{
    FcMatrixShear( (FcMatrix*)m_ptr, sh, sv );
}



Matrix operator*(const Matrix& a, const Matrix& b)
{
    Matrix newMat;
    FcMatrixMultiply(
            (FcMatrix*)newMat.get_ptr(),
            (const FcMatrix*)a.get_ptr(),
            (const FcMatrix*)b.get_ptr() );
    return newMat;
}

bool operator==(const Matrix& a, const Matrix& b)
{
    return a.equal(b);
}


}// namespace fontconfig
