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
	inline bool NearZero(float val, float epsilon = 0.001f)
	{
		if (fabs(val) <= epsilon)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

    // Square root of float
    inline float Sqrt(float value){
        return sqrtf(value);
    }

// --------------------------------------------------
// Trigonometric Functions

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline float Tan(float angle)
	{
		return tanf(angle);
	}

	inline float Acos(float value)
	{
		return acosf(value);
	}
	
	inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	inline float Cot(float angle)
	{
		return 1.0f / Tan(angle);
	}

// --------------------------------------------------

	inline float GetSlope(float aX, float aY, float bX, float bY){
		return (bY - aY)/(bX - aX);
	}

	// Get y-coordinate via linear equation
	inline float GetLinearY(float slope, float x, float b){
		return (slope * x) + b;
	}

}

#endif