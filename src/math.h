/** math.h
 * 
 * Collection of math functions and classes,
 * specifically a Vector class.
 */

#ifndef MATH_H
#define MATH_H

#include <cmath>

namespace Math{

	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOver2 = Pi / 2.0f;
//	const float Infinity = std::numeric_limits<float>::infinity();
//	const float NegInfinity = -std::numeric_limits<float>::infinity();

    // Convert degrees to radians
	inline float ToRadians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

    // Convert radians to degrees
	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}

    // Checks whether float value is near zero
	inline bool NearZero(float value, float epsilon = 0.001f)
	{
		return (fabs(value) <= epsilon);
	}

    // Square root of float
    inline float Sqrt(float value){
        return sqrtf(value);
    }

// --------------------------------------------------
// Trigonometric Functions

	// Cosine from Radians
	inline float Cos(float radians)
	{
		return cosf(radians);
	}

	// Sine from Radians
	inline float Sin(float radians)
	{
		return sinf(radians);
	}

	// Tangent from Radians
	inline float Tan(float radians)
	{
		return tanf(radians);
	}

	// Cotangent from Radians
	inline float Cot(float radians)
	{
		return 1.0f / Tan(radians);
	}

	// Arccosine in Radians
	inline float Acos(float value)
	{
		return acosf(value);
	}

	// Arcsine in Radians
	inline float Asin(float value)
	{
		return asinf(value);
	}
	
	// Arctangent in Radians
	inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

// --------------------------------------------------

	inline float Slope(float aX, float aY, float bX, float bY){
		return (bY - aY) / (bX - aX);
	}

	// Get y-coordinate via linear equation
	inline float LinearY(float slope, float x, float b){
		return slope * x + b;
	}

}

#endif