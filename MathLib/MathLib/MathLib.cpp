#include <iostream>
#include <assert.h>
#include <cmath>

#include "Matrix.h"
#include "Vector.h"
#include "Transformations.h"
#include "Quaternion.h"

void testMatrix()
{
    //Create 2 equal Matrix
    Mat3 m1({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    Mat3 m2({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    assert(m1 == m2);

    //Test for a different Matrix
    Mat3 m3({ 1, 1, 1, 1, 1, 1, 1, 1, 1 });
    assert(!(m1 == m3));

    //2 equal matrix in R3
    Mat4 m5({ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 });
    Mat4 m6({ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 });
    assert(m5 == m6);
}

void testMatrixOperations()
{
    //Simple addition
    Mat3 m1({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    Mat3 m2({ 2, 3, 4, 5, 0, -1, -3, -5, -7 });
    assert(m1 + m2 == Mat3({ 3, 5, 7, 9, 5, 5, 4, 3, 2 }));
    assert(m2 + m1 == Mat3({ 3, 5, 7, 9, 5, 5, 4, 3, 2 }));

    //Substraction
    Mat3 m3({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    Mat3 m4({ 5, 3, 4, 1, 0, -1, -2, 0, 4 });
    assert(m3 - m4 == Mat3({ -4, -1, -1, 3, 5, 7, 9, 8, 5 }));
    assert(!(m3 - m4 == Mat3({ 4, -1, -1, 3, 5, 7, 9, 8, 5 })));

    //Product
    Mat3 m5({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    Mat3 m6({ 9, 8, 7, 6, 5, 4, 3, 2, 1 });
    assert(m5 * m6 == Mat3({ 30, 24, 18, 84, 69, 54, 138, 114, 90 }));

    //Product against the Identity matrix
    Mat3 identity({ 1, 0, 0, 0, 1, 0, 0, 0, 1 });
    assert(m1 == m1 * identity);
    assert(m1 == identity * m1);
}

void testVector()
{ 
    Vec3 v1({ 1, 2, 3});
    Vec3 v2({ 1, 2, 3 });
    assert(v1 == v2);

    //Different vector
    Vec3 v3({ 1, 1, 1 });
    assert(!(v1 == v3));

    //For R4
    Vec4 v5({ 1, 0, 0, 0 });
    Vec4 v6({ 1, 0, 0, 0 });
    assert(v5 == v6);

    Vec4 v7({ 1, 0, 0, 1 });
    assert(!(v5 == v7));
}

void testVectorOperations()
{
    //Addition
    Vec3 v1({ 1, 2, 3 });
    Vec3 v2({ 2, 3, 4 });
    assert(v1 + v2 == Vec3({ 3, 5, 7 }));
    assert(v2 + v1 == Vec3({ 3, 5, 7 })); //Symmetric

    //Substraction
    Vec3 v3({ 1, 2, 3 });
    Vec3 v4({ 2, 1, 1 });
    assert(v3 - v4 == Vec3({ -1, 1, 2 }));
    assert(!(v4 - v3 == Vec3({ -1, 1, 2 })));

    //Cross Product
    Vec3 v5({ 1, 2, 3 });
    Vec3 v6({ 1, 5, 7 });
    assert(v5 * v6 == Vec3({ -1, -4, 3 }));
    assert(!(v5 * v6 == v6 * v5));

    //Should return one that is paralel to the xy plane
    assert(Vec3({ 1, 0, 0 }) * Vec3({ 0, 1, 0 }) == Vec3({ 0, 0, 1 }));

    //Paralel vectors should return a null vector
    assert(Vec3({ 1, 0, 0 }) * Vec3({ 2, 0, 0 }) == Vec3({ 0, 0, 0 }));

    //Dot product
    Vec3 v7({ 1, 2, 3 });
    Vec3 v8({ 1, 5, 7 });
    assert(v6.dotProduct(v7) == 1 + 2 * 5 + 3 * 7); 
    assert(v7.dotProduct(v8) == 1 + 2 * 5 + 3 * 7); //Symmetric

    //Perpendicular vectors
    Vec3 v9({ 1, 0, 0 });
    Vec3 v10({ 0, 1, 0 });
    assert(v9.dotProduct(v10) == 0);

    //Scalar product
    Vec3 v11({ 1, 2, 3 });
    assert(v1 * 2 == Vec3({ 2, 4, 6 })); 
    assert(2 * v1 == Vec3({ 2, 4, 6 })); //Symmetric
    assert(v1 * 0 == Vec3({ 0, 0, 0 })); //Product with 0
}

void testTranslation()
{
    auto translationMatrix = Transformations::translation(1, 2, 3);

    Vec3 v1({ 1, 1, 1 });

    //Convert to Vec4
    Vec4 v = Transformations::toVec4(v1);
    assert(v == Vec4({ 1, 1, 1, 1 }));

    //Translate 
    Vec4 v2 = translationMatrix * v;
    assert(v2 == Vec4({ 2, 3, 4, 1 }));

    //Return to Vec3
    Vec3 result = Transformations::toVec3(v2);
    assert(result == Vec3({ 2, 3, 4}));
}

void testScale()
{
    auto scaleMatrix = Transformations::scale(1, 2, 3);

    Vec3 v1({ 1, 1, 1 });

    //Convert to Vec4
    Vec4 v = Transformations::toVec4(v1);
    assert(v == Vec4({ 1, 1, 1, 1 }));

    //Resize
    Vec4 v2 = scaleMatrix * v;
    assert(v2 == Vec4({ 1, 2, 3, 1 }));

    //Return to Vec3
    Vec3 result = Transformations::toVec3(v2);
    assert(result == Vec3({ 1, 2, 3 }));
}

void testRotate()
{
    const double PI = 3.14159265358979323846;

    auto rotateXMatrix = Transformations::rotateX(PI);

    Vec3 v1({ 1, 1, 1 });

    //Convert to Vec4
    Vec4 v = Transformations::toVec4(v1);
    assert(v == Vec4({ 1, 1, 1, 1 }));

    //Rotate
    Vec4 v2 = rotateXMatrix * v;
}

void testQuaternion()
{
    //Product
    Quaternion q1({ 3, 2, 1 }, 4);
    assert( q1 * q1 == Quaternion({ 24, 16, 8 }, 2));

    //Addition
    assert(q1 + q1 == Quaternion({ 6, 4, 2 }, 8));
}

int main()
{
    //Matrix tests
    testMatrix();
    testMatrixOperations();

    //Vector tests
    testVector();
    testVectorOperations();

    //Transformation tests
    testTranslation();
    testScale();
    testRotate();

    //Quaternions
    testQuaternion();
    return 0;
}
