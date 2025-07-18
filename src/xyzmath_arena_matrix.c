/*
*		xyzmath_arena_matrix.c
*
*		By Jaidev Bormann
*/


#include "xyzmath_matrix.h"


#include <stdlib.h>


MatrixStandardModel xyzmatrix_arenaMatrix(MatrixArenaModel* arena, uint32_t rows, uint32_t columns)
{
	if (!arena || !arena->data) return;

	const uint32_t totalsize = rows * columns;

	MatrixStandardModel matrix = { 0 };
	matrix.rows = rows;
	matrix.columns = columns;

	if (totalsize > arena->capacityelements || arena->offset + totalsize > arena->capacityelements) return;

	matrix.data = arena->data + arena->offset;

	arena->offset += totalsize;

	return matrix;
}


MatrixArenaModel xyzmatrix_arenaInit(uint32_t capacitybytes) 
{
	MatrixArenaModel arena = { 0 };
	arena.data = (float*)calloc(1, capacitybytes);
	arena.capacitybytes = capacitybytes;
	arena.capacityelements = arena.capacitybytes / sizeof(float);
	arena.offset = 0;

	return arena;
}

void xyzmatrix_arenaFree(MatrixArenaModel* arena)
{
	if (arena && arena->data) 
	{
		free(arena->data);
		arena->capacitybytes = 0;
		arena->capacityelements = 0;
		arena->offset = 0;

		arena->data = NULL;
	}
}