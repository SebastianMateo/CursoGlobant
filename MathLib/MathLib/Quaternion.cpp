#include "Quaternion.h"

Quaternion::Quaternion() { }
Quaternion::Quaternion(std::array<double, 3> qv, double qw) : mQv(qv), mQw(qw) { }

//Multiplication
Quaternion& Quaternion::operator*=(const Quaternion& rhs)
{
    Vec3 v = mQv * rhs.mQv + rhs.mQw * mQv + mQw * rhs.mQv;
    double w = mQw * rhs.mQw - mQv.dotProduct(rhs.mQv);

    mQv = v;
    mQw = w;

    return *this;
}

//Addition
Quaternion& Quaternion::operator+=(const Quaternion& rhs)
{
    mQw += rhs.mQw;
    mQv += rhs.mQv;

    return *this;
}