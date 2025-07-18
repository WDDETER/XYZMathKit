/*
*		xyzmath_matrix.h
*
*		By Jaidev Bormann
*/


#ifndef _XYZMATHMATRIX_
#define _XYZMATHMATRIX_


#include "xyzmath_float.h"

#include <stdint.h>


typedef struct 
{
	float* data;
	uint32_t capacityelements;
	uint32_t capacitybytes;
	uint32_t offset;
} MatrixArenaModel;

typedef struct 
{
	float* data;
	uint32_t rows;
	uint32_t columns;
} MatrixStandardModel;


void xyzmatrix_mul(MatrixStandardModel* matrix1, MatrixStandardModel* matrix2, MatrixStandardModel* result);
void xyzmatrix_transpose(MatrixStandardModel* matrix, MatrixStandardModel* result);
void xyzmatrix_fillVertex(MatrixStandardModel* matrix, uint32_t count, ...);

MatrixStandardModel xyzmatrix_arenaMatrix(MatrixArenaModel* arena, uint32_t rows, uint32_t columns);
MatrixArenaModel xyzmatrix_arenaInit(uint32_t capacitybytes);
void xyzmatrix_arenaFree(MatrixArenaModel* arena);


static inline void xyzmatrix_fillTranslate3D(MatrixStandardModel* matrix, float x, float y, float z)
{
	matrix->data[0] = 1.0f; matrix->data[1] = 0; matrix->data[2] = 0; matrix->data[3] = 0;
	matrix->data[4] = 0; matrix->data[5] = 1.0f; matrix->data[6] = 0; matrix->data[7] = 0;
	matrix->data[8] = 0; matrix->data[9] = 0; matrix->data[10] = 1.0f; matrix->data[11] = 0;
	matrix->data[12] = x; matrix->data[13] = y; matrix->data[14] = z; matrix->data[15] = 1.0f;
}

static inline void xyzmatrix_fillScale3D(MatrixStandardModel* matrix, float x, float y, float z)
{
	matrix->data[0] = x; matrix->data[1] = 0; matrix->data[2] = 0; matrix->data[3] = 0;
	matrix->data[4] = 0; matrix->data[5] = y; matrix->data[6] = 0; matrix->data[7] = 0;
	matrix->data[8] = 0; matrix->data[9] = 0; matrix->data[10] = z; matrix->data[11] = 0;
	matrix->data[12] = 0; matrix->data[13] = 0; matrix->data[14] = 0; matrix->data[15] = 1.0f;
}

static inline void xyzmatrix_fillRotateX3D(MatrixStandardModel* matrix, float theta)
{
	const float sin = xyzmath_sinf(theta);
	const float cos = xyzmath_cosf(theta);

	matrix->data[0] = 1.0f;
	matrix->data[1] = 0;
	matrix->data[2] = 0;
	matrix->data[3] = 0;

	matrix->data[4] = 0;
	matrix->data[5] = cos;
	matrix->data[6] = sin;
	matrix->data[7] = 0;

	matrix->data[8] = 0;
	matrix->data[9] = -sin;
	matrix->data[10] = cos;
	matrix->data[11] = 0;

	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = 0;
	matrix->data[15] = 1.0f;
}

static inline void xyzmatrix_fillRotateY3D(MatrixStandardModel* matrix, float theta)
{
	const float sin = xyzmath_sinf(theta);
	const float cos = xyzmath_cosf(theta);

	matrix->data[0] = cos;
	matrix->data[1] = 0;
	matrix->data[2] = -sin;
	matrix->data[3] = 0;

	matrix->data[4] = 0;
	matrix->data[5] = 1.0f;
	matrix->data[6] = 0;
	matrix->data[7] = 0;

	matrix->data[8] = 0;
	matrix->data[9] = sin;
	matrix->data[10] = cos;
	matrix->data[11] = 0;

	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = 0;
	matrix->data[15] = 1.0f;
}

static inline void xyzmatrix_fillRotateZ3D(MatrixStandardModel* matrix, float theta)
{
	const float sin = xyzmath_sinf(theta);
	const float cos = xyzmath_cosf(theta);

	matrix->data[0] = cos;
	matrix->data[1] = sin;
	matrix->data[2] = 0;
	matrix->data[3] = 0;

	matrix->data[4] = -sin;
	matrix->data[5] = cos;
	matrix->data[6] = 0;
	matrix->data[7] = 0;

	matrix->data[8] = 0;
	matrix->data[9] = 0;
	matrix->data[10] = 1.0f;
	matrix->data[11] = 0;

	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = 0;
	matrix->data[15] = 1.0f;
}

static inline void xyzmatrix_fillTranslate2D(MatrixStandardModel* matrix, float x, float y)
{
	matrix->data[0] = 1.0f; matrix->data[1] = 0; matrix->data[2] = 0;
	matrix->data[4] = 0; matrix->data[5] = 1.0f; matrix->data[6] = 0;
	matrix->data[12] = x; matrix->data[13] = y; matrix->data[14] = 1.0f;
}

static inline void xyzmatrix_fillScale2D(MatrixStandardModel* matrix, float x, float y)
{
	matrix->data[0] = x; matrix->data[1] = 0; matrix->data[2] = 0;
	matrix->data[4] = 0; matrix->data[5] = y; matrix->data[6] = 0;
	matrix->data[8] = 0; matrix->data[9] = 0; matrix->data[10] = 1.0f;
}

static inline void xyzmatrix_fillRotate2D(MatrixStandardModel* matrix, float theta)
{
	const float sin = xyzmath_sinf(theta);
	const float cos = xyzmath_cosf(theta);

	matrix->data[0] = cos;
	matrix->data[1] = sin;
	matrix->data[2] = 0;

	matrix->data[3] = -sin;
	matrix->data[4] = cos;
	matrix->data[5] = 0;

	matrix->data[6] = 0;
	matrix->data[7] = 0;
	matrix->data[8] = 1.0f;
}

static inline void xyzmatrix_fillOrthogonal(MatrixStandardModel* matrix, float top, float bottom, float left, float right, float nearZ, float farZ) 
{
	float rightleftDiff = right - left;
	float topbottomDiff = top - bottom;
	float farnearDiff = farZ - nearZ;

	float invRightleft = 1.0f / rightleftDiff;
	float invTopbottom = 1.0f / topbottomDiff;
	float invFarnear = 1.0f / farnearDiff;

	matrix->data[0] = 2.0f * invRightleft;
	matrix->data[1] = 0;
	matrix->data[2] = 0;
	matrix->data[3] = 0;

	matrix->data[4] = 0;
	matrix->data[5] = 2.0f * invTopbottom;
	matrix->data[6] = 0;
	matrix->data[7] = 0;

	matrix->data[8] = 0;
	matrix->data[9] = 0;
	matrix->data[10] = -2.0f * invFarnear;
	matrix->data[11] = 0;

	matrix->data[12] = -(right + left) * invRightleft;
	matrix->data[13] = -(top + bottom) * invTopbottom;
	matrix->data[14] = -(farZ + nearZ) * invFarnear;
	matrix->data[15] = 1.0f;
}

static inline void xyzmatrix_fillPerspective(MatrixStandardModel* matrix, float fovRad, float aspectRatio, float nearZ, float farZ)
{
	float invTanFov2 = 1.0f / xyzmath_tanf(fovRad * 0.5);
	float invAspect = 1.0f / aspectRatio;

	float invZRange = 1.0f / (farZ - nearZ);

	matrix->data[0] = invAspect * invTanFov2;
	matrix->data[1] = 0;
	matrix->data[2] = 0;
	matrix->data[3] = 0;

	matrix->data[4] = 0;
	matrix->data[5] = invTanFov2;
	matrix->data[6] = 0;
	matrix->data[7] = 0;

	matrix->data[8] = 0;
	matrix->data[9] = 0;
	matrix->data[10] = -(farZ + nearZ) * invZRange;
	matrix->data[11] = -2.0f * farZ * nearZ * invZRange;

	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = -1;
	matrix->data[15] = 0;
}


#endif