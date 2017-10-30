#include "Transformations.h"
#include <cmath>

Mat4 Transformations::translation(double dx, double dy, double dz)
{
    return Matrix<4>({
        1, 0, 0, dx,
        0, 1, 0, dy,
        0, 1, 0, dz,
        0, 0, 0, 1
    });
}

Mat4 Transformations::scale(double sx, double sy, double sz)
{
    return Matrix<4>({
        sx, 0, 0, 0,
        0, sy, 0, 0,
        0, 0, sz, 0,
        0, 0, 0, 1
    });
}

Mat4 Transformations::rotateX(double angle)
{
    return Matrix<4>({
        1, 0, 0, 0,
        0, cos(angle), -sin(angle), 0,
        0, sin(angle), cos(angle), 0,
        0, 0, 0 , 1
    });
}

Mat4 Transformations::rotateY(double angle)
{
    return Matrix<4>({
        cos(angle), -sin(angle), 0, 0,
        sin(angle), cos(angle), 0, 0,
        0, 0, 1, 0,
        0, 0, 0 , 1
    });
}

Mat4 Transformations::rotateZ(double angle)
{
    return Matrix<4>({
        cos(angle), 0, sin(angle), 0,
        0, 1, 0, 0,
        -sin(angle), 0, cos(angle), 0,
        0, 0, 0 , 1
    });
}