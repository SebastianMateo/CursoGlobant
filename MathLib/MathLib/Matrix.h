#pragma once
#include <iostream>
#include <array>
#include "Vector.h"

template <unsigned int N>
class Matrix
{
public:
    Matrix();
    Matrix(std::array<double, N*N> values);

    //Addition
    Matrix& operator+=(const Matrix& rhs);
    friend Matrix operator+(Matrix lhs, const Matrix& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    //Substraction
    Matrix& operator-=(const Matrix& rhs);
    friend Matrix operator-(Matrix lhs, const Matrix& rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    //Product
    Matrix& operator*=(const Matrix& rhs);
    friend Matrix operator*(Matrix lhs, const Matrix& rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    //Equals
    friend bool operator==(Matrix lhs, const Matrix& rhs)
    {
        return (lhs.mMatrix == rhs.mMatrix);
    }

    //Matrix * Vector
    friend Vector<N> operator*(Matrix<N> matrix, const Vector<N>& vector)
    {
        Vector<N> result;
        for (int i = 0; i < N; i++)
        {
            result[i] = 0;
            for (int j = 0; j < N; j++)
            {
                result[i] += matrix.get(i, j) * vector[j];
            }
        }
        return result;
    }

    //streams
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                os << matrix.get(i, j) << " ";
            }
            os << std::endl;
        }

        return os;
    }

private:

    //The matrix is represented as a 1 dimensional fixed sizearray
    std::array<double, N*N> mMatrix;

    inline double get(int row, int column) const { return mMatrix[row * N + column]; }
    inline double& get(int row, int column) { return mMatrix[row * N + column]; }
};

using Mat3 = Matrix<3>;
using Mat4 = Matrix<4>;