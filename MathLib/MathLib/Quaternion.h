#pragma once
#include "Vector.h"

class Quaternion
{
public:
    Quaternion();
    Quaternion(std::array<double, 3> qv, double qw);

    //Multiplication
    Quaternion& operator*=(const Quaternion& rhs);
    friend Quaternion operator*(Quaternion lhs, const Quaternion& rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    //Addition
    Quaternion& operator+=(const Quaternion& rhs);
    friend Quaternion operator+(Quaternion lhs, const Quaternion& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    //Equals
    friend bool operator==(const Quaternion &lhs, const Quaternion& rhs)
    {
        return (lhs.mQv == rhs.mQv && lhs.mQw == rhs.mQw);
    }

private:
    Vec3 mQv;
    double mQw;
};

