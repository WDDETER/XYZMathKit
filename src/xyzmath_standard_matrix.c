/*
*		xyzmath_standard_matrix.c
*
*		By Jaidev Bormann
*/


#include "xyzmath_matrix.h"


#include <stdarg.h>


void xyzmatrix_fillVertex(MatrixStandardModel* matrix, uint32_t count, ...)
{
	va_list args;
	va_start(args, count);


	for (uint32_t i = 0; i < count; i++)
	{
		matrix->data[i] = (float)va_arg(args, double);
	}

	va_end(args);
}

void xyzmatrix_mul(MatrixStandardModel* matrix1, MatrixStandardModel* matrix2, MatrixStandardModel* result) 
{
	for (uint32_t row = 0; row < matrix1->rows; ++row)
	{
		for (uint32_t column = 0; column < matrix2->columns; ++column)
		{
			float sum = 0.0f;

			for (uint32_t k = 0; k < matrix1->columns; ++k) 
			{
				sum += matrix1->data[row * matrix1->columns + k] * matrix2->data[k * matrix2->columns + column];
			}

			result->data[row * matrix2->columns + column] = sum;
		}
	}
}

void xyzmatrix_transpose(MatrixStandardModel* matrix, MatrixStandardModel* result) 
{
	for (uint32_t row = 0; row < matrix->rows; ++row)
	{
		for (uint32_t column = 0; column < matrix->columns; ++column)
		{
			result->data[column * result->columns + row] = matrix->data[row * matrix->columns + column];
		}
	}
}