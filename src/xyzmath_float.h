/*
*		xyzmath_float.h
* 
*		By Jaidev Bormann
*/


#ifndef _XYZMATHFLOAT_
#define _XYZMATHFLOAT_


#include <math.h>


// Want more precision with SQRT, INVSQRT? (located at the bottom of the header)
// 
//		Copy and Paste to add another Newton-Raphson iteration: 
//			sharedmem.f = 0.5f * (sharedmem.f + x / sharedmem.f);
// 
// Adding this is iterates the (INV)SQRT value more and more, each iteration providing a more and more precise result.


// The asin and acos functions use the standard sqrtf function for more precision.
// If you need speed but not accuracy use the xyzmath_sqrt of xyzmath_invsqrt functions.


#define PI 3.14159265359f
#define PI2 6.28318530718f
#define PID2 (PI / 2.0f)

#define DEG_TO_RAD(deg) ((deg) * (PI / 180.0f))
#define RAD_TO_DEG(rad) ((rad) * (180.0f / PI))

static inline int xyzmath_floorf(float x) 
{
	int i = (int)x;
	return i - (x < i);
}

static inline int xyzmath_ceilf(float x)
{
	int i = (int)x;
	return i + (x > i);
}

static inline float xyzmath_minf(float x, float y) 
{
	return (x < y) ? x : y;
}

static inline float xyzmath_maxf(float x, float y)
{
	return (x > y) ? x : y;
}

static inline float xyzmath_sinf(float x) 
{
	x = x - PI2 * floorf(x / PI2);
	float sign = 1.0f;

	if (x > PI) {
		x -= PI; 
		sign = -1.0f;
	}

	if (x > PID2) x = PI - x;

	return sign * (16 * x * (PI - x)) / (5 * PI * PI - 4 * x * (PI - x));
}

static inline float xyzmath_cosf(float x)
{
	x = x - PI2 * floorf(x / PI2);
	float sign = 1.0f;

	if (x > PI) {
		x -= PI;
		sign = -1.0f;
	}

	if (x > PID2) x = PI - x;

	const float shifted_x = PID2 - x;

	return sign * (16 * shifted_x * (PI - shifted_x)) / (5 * PI * PI - 4 * shifted_x * (PI - shifted_x));
}

static inline float xyzmath_asinf(float x)
{
	if (x > 1.0f) x = 1.0f;
	if (x < -1.0f) x = -1.0f;

	int negate = (x < 0);
	if (negate) x = -x;

	float ret = -0.0187293f;
	ret = ret * x;
	ret = ret + 0.0742610f;
	ret = ret * x;
	ret = ret - 0.2121144f;
	ret = ret * x;
	ret = ret + 1.5707288f;
	ret = ret * sqrtf(1.0f - x);
	ret = PID2 - ret;

	return negate ? -ret : ret;
}

static inline float xyzmath_acosf(float x) 
{
	return PID2 - xyzmath_asinf(x);
}

static inline float xyzmath_tanf(float x) 
{
	return xyzmath_sinf(x) / xyzmath_cosf(x);
}

static inline float xyzmath_invsqrtf(float x)
{	
	union
	{
		float f;
		int i;
	} sharedmem;
	
	sharedmem.f = x;

	const float xhalf = 0.5f * sharedmem.f;

	sharedmem.i = 0x5f3759df - (sharedmem.i >> 1);
	sharedmem.f *= (1.5f - xhalf * sharedmem.f * sharedmem.f);

	return sharedmem.f;
}

static inline float xyzmath_sqrtf(float x)
{
	union 
	{
		float f;
		int i;
	} sharedmem;

	sharedmem.f = x;
	sharedmem.i = (sharedmem.i >> 1) + 0x1fc00000;

	sharedmem.f = 0.5f * (sharedmem.f + x / sharedmem.f);

	return sharedmem.f;
}


#endif