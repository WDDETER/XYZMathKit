/*
*		xyzmath_vector2.h
*
*		By Jaidev Bormann
*/


#ifndef _XYZMATHVECTOR2_
#define _XYZMATHVECTOR2_


#include "xyzmath_vector.h"


// !!! USAGE INFORMATION READ !!!:
//		ALL FUNCTIONS ASSUME THE VECTOR IS NORMALIZED AND ERROR-CHECKED BEFOREHAND
//		THESE FUNCTIONS DO NOT HOLD YOUR HAND


static inline VectorN xyzvector2_add(VectorN a, VectorN b)
{
	a.x += b.x;
	a.y += b.y;

	return a;
}


static inline VectorN xyzvector2_sub(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

static inline VectorN xyzvector2_mulscalar(VectorN a, const float scalar)
{
	a.x *= scalar;
	a.y *= scalar;

	return a;
}

static inline VectorN xyzvector2_mulcomponent(VectorN a, VectorN b)
{
	a.x *= b.x;
	a.y *= b.y;

	return a;
}

static inline VectorN xyzvector2_norm(VectorN a)
{
	const float magSq = a.x * a.x + a.y * a.y;
	const float mag = xyzmath_invsqrtf(magSq);

	a.x *= mag;
	a.y *= mag;

	return a;
}

static inline VectorN xyzvector2_lerp(VectorN a, VectorN b, float t)
{
	a.x += t * (b.x - a.x);
	a.y += t * (b.y - a.y);

	return a;
}

static inline VectorN xyzvector2_reflect(VectorN a, VectorN n)
{
	const float dot = 2.0f * (a.x * n.x + a.y * n.y);

	n.x *= dot;
	n.y *= dot;

	a.x -= n.x;
	a.y -= n.y;

	return a;
}

static inline VectorN xyzvector2_max(VectorN a, VectorN b)
{
	a.x = (a.x > b.x) ? a.x : b.x;
	a.y = (a.y > b.y) ? a.y : b.y;

	return a;
}

static inline VectorN xyzvector2_min(VectorN a, VectorN b)
{
	a.x = (a.x < b.x) ? a.x : b.x;
	a.y = (a.y < b.y) ? a.y : b.y;

	return a;
}

static inline VectorN xyzvector2_project(VectorN a, VectorN b)
{
	const float dot = a.x * b.x + a.y * b.y;

	b.x *= dot;
	b.y *= dot;

	return b;
}

static inline float xyzvector2_mag(VectorN a)
{
	const float c = xyzmath_sqrtf(a.x * a.x + a.y * a.y);

	return c;
}

static inline float xyzvector2_dot(VectorN a, VectorN b)
{
	return a.x * b.x + a.y * b.y;
}

static inline float xyzvector2_cross(VectorN a, VectorN b)
{
	return a.x * b.y - a.y * b.x;
}

static inline float xyzvector2_dist(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;

	return xyzmath_sqrtf(a.x * a.x + a.y * a.y);
}

static inline float xyzvector2_distsq(VectorN a, VectorN b)
{
	a.x -= b.x;
	a.y -= b.y;

	return a.x * a.x + a.y * a.y;
}

static inline float xyzvector2_anglebetween(VectorN a, VectorN b)
{
	float dot = a.x * b.x + a.y * b.y;

	return xyzmath_acosf(dot);
}


#endif