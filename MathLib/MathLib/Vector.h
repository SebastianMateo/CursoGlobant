#pragma once
#include <iostream>
#include <array>

//Column vector
template <unsigned int N>
class Vector
{
public:
    Vector();
    Vector(std::array<double, N> values);

    //Addition
    Vector& operator+=(const Vector& rhs);
    friend Vector operator+(Vector lhs, const Vector& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    //Substraction
    Vector& operator-=(const Vector& rhs);
    friend Vector operator-(Vector lhs, const Vector& rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    //Dot product
    double dotProduct(const Vector& rhs);

    //Cross product
    Vector& operator*=(const Vector& rhs);
    friend Vector operator*(Vector lhs, const Vector& rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    //Equals
    friend bool operator==(const Vector &lhs, const Vector& rhs)
    {
        return (lhs.mVector == rhs.mVector);
    }

    //Product with a scalar
    friend Vector operator*(Vector lhs, double scalar)
    {
        for (int i = 0; i < N; i++)
            lhs.mVector[i] *= scalar;

        return lhs;
    }
    friend Vector operator*(double scalar, Vector lhs) { return lhs * scalar; }

    //Overload [] operator
    double& operator[](const int i) { return mVector[i]; }
    const double& operator[](const int i) const { return mVector[i]; }

    //streams
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec)
    {
        for (auto value : vec.mVector)
            os << value << std::endl;
        return os;
    }
private:

    //The vector can be stored as a fixed size array
    std::array<double, N> mVector;
};

using Vec3 = Vector<3>;
using Vec4 = Vector<4>;