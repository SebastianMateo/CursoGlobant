#pragma once

#include "Matrix.h"

class Transformations
{
public:
    static Mat4 translation(double dx, double dy, double dz);
    static Mat4 scale(double sx, double sy, double sz);
    static Mat4 rotateX(double angle);
    static Mat4 rotateY(double angle);
    static Mat4 rotateZ(double angle);

    static Vec4 toVec4(Vec3 vec)
    {
        return Vec4({ vec[0], vec[1], vec[2], 1 });
    }

    static Vec3 toVec3(Vec4 vec)
    {
        double h = vec[3];
        return Vec3( { vec[0]/h, vec[1]/h, vec[2]/h });
    }
};

