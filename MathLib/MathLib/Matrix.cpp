#include "Matrix.h"

template <unsigned int N>
Matrix<N>::Matrix(std::array<double, N*N> values) : mMatrix(values) { }

template <unsigned int N>
Matrix<N>::Matrix() { }

//Addition
template <unsigned int N>
Matrix<N>& Matrix<N>::operator+=(const Matrix<N>& rhs)
{
    for (int i = 0; i < N * N; i++)
        this->mMatrix[i] += rhs.mMatrix[i];

    return *this;
}

//Substraction
template <unsigned int N>
Matrix<N>& Matrix<N>::operator-=(const Matrix<N>& rhs)
{
    for (int i = 0; i < N * N; i++)
        this->mMatrix[i] -= rhs.mMatrix[i];

    return *this;
}

//Product
template <unsigned int N>
Matrix<N>& Matrix<N>::operator*=(const Matrix<N>& rhs)
{
    Matrix<N> result;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result.get(i, j) = 0;
            for (int k = 0; k < N; k++)
            {
                result.get(i,j) += this->get(i,k) * rhs.get(k,j);
            }
        }
    }
    *this = result;
    return *this;
}

// explicit instantiations
template class Matrix<3>;
template class Matrix<4>;