#include "Vector.h"

template <unsigned int N>
Vector<N>::Vector(std::array<double, N> values) : mVector(values) { }

template <unsigned int N>
Vector<N>::Vector() { }

//Addition
template <unsigned int N>
Vector<N>& Vector<N>::operator+=(const Vector<N>& rhs)
{
    for (int i = 0; i < N; i++)
        this->mVector[i] += rhs.mVector[i];

    return *this;
}

//Substraction
template <unsigned int N>
Vector<N>& Vector<N>::operator-=(const Vector<N>& rhs)
{
    for (int i = 0; i < N; i++)
        this->mVector[i] -= rhs.mVector[i];

    return *this;
}

//Cross product for Vec3
template <>
Vector<3>& Vector<3>::operator*=(const Vector<3>& rhs)
{
    double x = mVector[1] * rhs[2] - mVector[2] * rhs.mVector[1];
    double y = mVector[2] * rhs.mVector[0] - mVector[0] * rhs.mVector[2];
    double z = mVector[0] * rhs.mVector[1] - mVector[1] * rhs.mVector[0];

    this->mVector[0] = x;
    this->mVector[1] = y;
    this->mVector[2] = z;

    return *this;
}

//Cross product for Vec3
template <>
Vector<4>& Vector<4>::operator*=(const Vector<4>& rhs)
{
    //TODO
    return *this;
}

//Dot product
template <unsigned int N>
double Vector<N>::dotProduct(const Vector<N>& rhs)
{
    double result = 0;

    for (int i = 0; i < N; i++)
        result += mVector[i] * rhs.mVector[i];

    return result;
}

// explicit instantiations
template class Vector<3>;
template class Vector<4>;