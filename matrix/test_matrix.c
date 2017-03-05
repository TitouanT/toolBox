#include <stdio.h>
#include "matrix.h"
#define N 3

int main () {
	int lines = N, cols = N;
	int i, j;
	frac_t ** mat;
	int matInt [N][N] = {
		{-2,2,-3},
		{-1,1,3},
		{2,0,-1},
	};
	mat = createMatrixFromInt(matInt, lines, cols);

	frac_t det = detMat(mat, N);

	dispMatrix(mat, lines, cols);
	printf("det: %d/%d\n", det.num, det.den);
	return 0;
}