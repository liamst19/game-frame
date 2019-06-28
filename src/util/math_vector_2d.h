/** math_vector_2d.h
 * 
 * A 2-dimensional Vector class.
 */

#ifndef MATH_VECTOR_2D_H
#define MATH_VECTOR_2D_H

namespace Util{
    namespace Math{

        class Vector2d{

        public:
            float x,y;

            Vector2d():
                x(0.0),
                y(0.0)
                {};

            explicit Vector2d(
                    float xIn,
                    float yIn):
                x(xIn),
                y(yIn)
                {};

            // Get x-coordinate integer
            int xInt()
                {
                    return static_cast<int>(x);
                }

            // Get y-coordinate integer
            int yInt()
                {
                    return static_cast<int>(y);
                }

// ----------------------------------------
//  Shorthand Assignment Operators

            // Vector Addition +=
            Vector2d operator+=(
                    const Vector2d& addend);

            // Vector Subtraction -=
            Vector2d operator-=(
                    const Vector2d& subtrahend);

            // Vector Scaling *=
            Vector2d operator*=(
                    const float scalar);

// ----------------------------------------
// Vector functions

            // Length squared
            float lengthSq();

            // Length
            float length();

            // Normalizes, convert to unit vector
            void normalize();

            // Rotate Vector along a given axis
            Vector2d rotate(
                    const Vector2d& axis,
                    const float angle_radians);

// ----------------------------------------
// Static functions

            // Normalizes a vector
            static Vector2d Normalize(
                    const Vector2d& vector);

            // Dot product of vectors: determines the angle between
            static float Dot(
                    const Vector2d& a,
                    const Vector2d& b);

            // Lerp from A to B by f
            static Vector2d Lerp(
                    const Vector2d& a,
                    const Vector2d& b,
                    float f);

            // Reflect V about (normalized) N
            static Vector2d Reflect(
                    const Vector2d& v,
                    const Vector2d& n);

            // Get forward vector from rotation angle
            static Vector2d GetForward(
                    float angle);

            // Get angle of a vector using arctangent
            static float GetAngle(
                    const Vector2d& vec);

            // Rotate a vector along an axis
            static Vector2d Rotate(
                    const Vector2d& vector,
                    const Vector2d& axis,
                    float angle_radian);

            // Transform vector by matrix
            // static Vector2d Transform(const Vector2d& vec, const class Matrix3& mat, float w = 1.0f);

            static const Vector2d Zero;
            static const Vector2d UnitX;
            static const Vector2d UnitY;
            static const Vector2d NegUnitX;
            static const Vector2d NegUnitY;	

        };

// ----------------------------------------
// Vector Operators

// Vector Addition (a + b)
        Vector2d operator+(
                const Vector2d& a,
                const Vector2d& b);

// Vector Subtraction (a - b)
        Vector2d operator-(
                const Vector2d& minuend,
                const Vector2d& subtrahend);

// Vector Scaling (vector * scalar)
        Vector2d operator*(
                const Vector2d vector,
                const float scalar);

// Vector Scaling, commutative (scalar * vector) 
        Vector2d operator*(
                const float scalar,
                const Vector2d vector);

    } // namespace Math
} // namespace Util
#endif
