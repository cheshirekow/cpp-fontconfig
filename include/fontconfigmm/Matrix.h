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

/// wraps FcMatrix with it's member methods
/**
 *  Matrix inherits from matrix (lowercase) which is a struct with the same
 *  definition as FcMatrix. Furthermore Matrix does not declare any virtual
 *  members so it is binary compatable with FcMatrix and can be casted
 *  without reserve
 */
class Matrix
{
    private:
        void* m_ptr;

    public:
        /// stack constructor,
        /**
         *  if you want to create a new matrix you may declare it normally and
         *  the constructor will heap allocate a new matrix object
         */
        Matrix();

        /// wrap constructor
        /**
         *  takes ownership of the pointer and will delete it when the
         *  object is deallocated
         */
        Matrix( void* ptr );

        /// copy constructor
        /**
         *  heap-allocates a new matrix and copies the contents from \p other
         */
        Matrix( const Matrix& other );

        /// destroys underlying matrix object
        ~Matrix();

        void* get_ptr();
        const void* get_ptr() const;

        /// assignment operator, copies the values of the matrix in other
        Matrix& operator=( const Matrix& other );

        double& xx();   ///< r/w access to the xx element
        double& xy();   ///< r/w access to the xy element
        double& yx();   ///< r/w access to the yx element
        double& yy();   ///< r/w access to the yy element

        /// initializes the matrix to be the identity matrix
        void init();

        /// creates a new matrix and copies it's contents (you probably would
        /// rather use the copy constructor)
        Matrix copy();

        /// returns true if the two matrices are equal
        bool equal( const Matrix& other ) const;

        /// rotate a matrix
        void rotate(double c, double s);

        /// scale a matrix
        void scale(double sx, double sy);

        /// shear a matrix
        void shear(double sh, double sv);
};

/// multiply matricies
Matrix operator*( const Matrix& a, const Matrix& b );

/// test for equality
bool operator==( const Matrix& a, const Matrix& b );


} // namespace fontconfig

#endif // MATRIX_H_
