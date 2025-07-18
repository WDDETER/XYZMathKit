/*
*		xyzmath_vector4.h
*
*		By Jaidev Bormann
*/


#ifndef _XYZMATHVECTOR4_
#define _XYZMATHVECTOR4_


#include "xyzmath_vector.h"


// !!! USAGE INFORMATION READ !!!:
//		ALL FUNCTIONS ASSUME THE VECTOR IS NORMALIZED AND ERROR-CHECKED BEFOREHAND
//		THESE FUNCTIONS DO NOT HOLD YOUR HAND


static inline VectorN xyzvector4_add(VectorN a, VectorN b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;

	return a;
}

static inline VectorN xyzvector4_sub(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;

	return a;
}

static inline VectorN xyzvector4_mulScalar(VectorN a, const float scalar)
{
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	a.w *= scalar;

	return a;
}

static inline VectorN xyzvector4_mulComponent(VectorN a, VectorN b) 
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;

	return a;
}

static inline VectorN xyzvector4_norm(VectorN a)
{
	const float magSq = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
	const float mag = xyzmath_invsqrtf(magSq);

	a.x *= mag;
	a.y *= mag;
	a.z *= mag;
	a.w *= mag;

	return a;
}

static inline VectorN xyzvector4_lerp(VectorN a, VectorN b, float t)
{
	a.x += t * (b.x - a.x);
	a.y += t * (b.y - a.y);
	a.z += t * (b.z - a.z);
	a.w += t * (b.w - a.w);

	return a;
}

static inline VectorN xyzvector4_reflect(VectorN a, VectorN n)
{
	const float dot = 2.0f * (a.x * n.x + a.y * n.y + a.z * n.z + a.w * n.w);

	n.x *= dot;
	n.y *= dot;
	n.z *= dot;
	n.w *= dot;

	a.x -= n.x;
	a.y -= n.y;
	a.z -= n.z;
	a.w -= n.w;

	return a;
}

static inline VectorN xyzvector4_max(VectorN a, VectorN b) 
{
	a.x = (a.x > b.x) ? a.x : b.x;
	a.y = (a.y > b.y) ? a.y : b.y;
	a.z = (a.z > b.z) ? a.z : b.z;
	a.w = (a.w > b.w) ? a.w : b.w;

	return a;
}

static inline VectorN xyzvector4_min(VectorN a, VectorN b)
{
	a.x = (a.x < b.x) ? a.x : b.x;
	a.y = (a.y < b.y) ? a.y : b.y;
	a.z = (a.z < b.z) ? a.z : b.z;
	a.w = (a.w < b.w) ? a.w : b.w;

	return a;
}

static inline VectorN xyzvector4_project(VectorN a, VectorN b) 
{
	const float dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;

	b.x *= dot;
	b.y *= dot;
	b.z *= dot;
	b.w *= dot;

	return b;
}

static inline float xyzvector4_mag(VectorN a)
{
	const float c = xyzmath_sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);

	return c;
}

static inline float xyzvector4_dot(VectorN a, VectorN b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

static inline float xyzvector4_dist(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;

	return xyzmath_sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

static inline float xyzvector4_distSq(VectorN a, VectorN b) 
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;

	return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

static inline float xyzvector4_angleBetween(VectorN a, VectorN b) 
{
	float dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;

	return xyzmath_acosf(dot);
}


#endif