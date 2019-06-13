/** math_vector_2d.cpp
 * 
 * A 2-dimensional Vector class.
 */

#include "math_vector_2d.h"
#include "math.h"

// ----------------------------------------
// Vector Operators

// Vector Addition (a + b)
Vector2d operator+(const Vector2d& a, const Vector2d& b)
{
    return Vector2d(a.x + b.x, a.y + b.y);
}

// Vector Subtraction (a - b)
Vector2d operator-(const Vector2d& minuend, const Vector2d& subtrahend)
{
    return Vector2d(minuend.x - subtrahend.x, minuend.y - subtrahend.y);
}

// Vector Scaling (vector * scalar)
Vector2d operator*(const Vector2d vector, const float scalar)
{
    return Vector2d(vector.x * scalar, vector.y * scalar);
}

// Vector Scaling, commutative (scalar * vector) 
Vector2d operator*(const float scalar, const Vector2d vector)
{
    return Vector2d(vector.x * scalar, vector.y * scalar);
}

// ----------------------------------------
//  Shorthand Assignment Operators

// Vector Addition +=
Vector2d Vector2d::operator+=(const Vector2d& addend)
{
    x += addend.x;
    y += addend.y;
    return *this;
}

// Vector Subtraction -=
Vector2d Vector2d::operator-=(const Vector2d& subtrahend)
{
    x -= subtrahend.x;
    y -= subtrahend.y;
    return *this;
}

// Vector Scaling *=
Vector2d Vector2d::operator*=(const float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

// ----------------------------------------
// Vector functions

// Length squared
float Vector2d::lengthSq()
{
    return (x*x + y*y);
}

// Length
float Vector2d::length()
{
    return Math::Sqrt(lengthSq());
}

// Normalizes, convert to unit vector
void Vector2d::normalize(){
    float len = length();
    x /= len;
    y /= len;
}

// ----------------------------------------
// Static functions

// Normalizes a vector
Vector2d Vector2d::Normalize(const Vector2d& vector){
    Vector2d tempVec = vector;
    tempVec.normalize();
    return tempVec;
}

// Dot product of vectors: determines the angle between
float Vector2d::Dot(const Vector2d& a, const Vector2d& b)
{
    return (a.x * b.x + a.y * b.y);
}

// Lerp from A to B by f
Vector2d Vector2d::Lerp(const Vector2d& a, const Vector2d& b, float f)
{
    return Vector2d(a + (f * (b - a)));
}

// Reflect V about (normalized) N
Vector2d Vector2d::Reflect(const Vector2d& v, const Vector2d& n)
{
    return v - 2.0f * Vector2d::Dot(v, n) * n;
}

// Get forward vector from rotation angle
Vector2d Vector2d::GetForward(float angle)
{
    // negative y-value because of screen
    return Vector2d(Math::Cos(angle), -Math::Sin(angle));
}

// Get angle of a vector using arctangent
float Vector2d::GetAngle(const Vector2d& vec)
{
    return Math::Atan2(vec.y, vec.x);
}
