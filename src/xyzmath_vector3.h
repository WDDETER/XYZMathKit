/*
*		xyzmath_vector3.h
*
*		By Jaidev Bormann
*/


#ifndef _XYZMATHVECTOR3_
#define _XYZMATHVECTOR3_


#include "xyzmath_vector.h"


// !!! USAGE INFORMATION READ !!!:
//		ALL FUNCTIONS ASSUME THE VECTOR IS NORMALIZED AND ERROR-CHECKED BEFOREHAND
//		THESE FUNCTIONS DO NOT HOLD YOUR HAND


static inline VectorN xyzvector3_add(VectorN a, VectorN b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;

	return a;
}


static inline VectorN xyzvector3_sub(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;

	return a;
}

static inline VectorN xyzvector3_mulscalar(VectorN a, const float scalar)
{
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;

	return a;
}

static inline VectorN xyzvector3_mulcomponent(VectorN a, VectorN b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;

	return a;
}

static inline VectorN xyzvector3_cross(VectorN a, VectorN b)
{
	VectorN result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;

	return result;
}

static inline VectorN xyzvector3_norm(VectorN a)
{
	const float magSq = a.x * a.x + a.y * a.y + a.z * a.z;
	const float mag = xyzmath_invsqrtf(magSq);

	a.x *= mag;
	a.y *= mag;
	a.z *= mag;

	return a;
}

static inline VectorN xyzvector3_lerp(VectorN a, VectorN b, float t)
{
	a.x += t * (b.x - a.x);
	a.y += t * (b.y - a.y);
	a.z += t * (b.z - a.z);

	return a;
}

static inline VectorN xyzvector3_reflect(VectorN a, VectorN n)
{
	const float dot = 2.0f * (a.x * n.x + a.y * n.y + a.z * n.z);

	n.x *= dot;
	n.y *= dot;
	n.z *= dot;

	a.x -= n.x;
	a.y -= n.y;
	a.z -= n.z;

	return a;
}

static inline VectorN xyzvector3_max(VectorN a, VectorN b)
{
	a.x = (a.x > b.x) ? a.x : b.x;
	a.y = (a.y > b.y) ? a.y : b.y;
	a.z = (a.z > b.z) ? a.z : b.z;

	return a;
}

static inline VectorN xyzvector3_min(VectorN a, VectorN b)
{
	a.x = (a.x < b.x) ? a.x : b.x;
	a.y = (a.y < b.y) ? a.y : b.y;
	a.z = (a.z < b.z) ? a.z : b.z;

	return a;
}

static inline VectorN xyzvector3_project(VectorN a, VectorN b)
{
	const float dot = a.x * b.x + a.y * b.y + a.z * b.z;

	b.x *= dot;
	b.y *= dot;
	b.z *= dot;

	return b;
}

static inline float xyzvector3_mag(VectorN a)
{
	const float c = xyzmath_sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);

	return c;
}

static inline float xyzvector3_dot(VectorN a, VectorN b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline float xyzvector3_dist(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;

	return xyzmath_sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

static inline float xyzvector3_distsq(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;

	return a.x * a.x + a.y * a.y + a.z * a.z;
}

static inline float xyzvector3_anglebetween(VectorN a, VectorN b)
{
	float dot = a.x * b.x + a.y * b.y + a.z * b.z;

	return xyzmath_acosf(dot);
}


#endif