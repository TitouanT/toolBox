#ifndef MATRIX_H
#define MATRIX_H


typedef struct {
	int num;
	int den;
} frac_t;

frac_t detMatTriangle (frac_t ** mat, int n, int sign);
frac_t detMat (frac_t ** mat, int n);

void triangulation (frac_t ** mat, int n, int * sign);

void dispMatrix (frac_t ** mat, int lines, int cols);
frac_t ** copyMatrix (frac_t ** mat, int lines, int cols);
frac_t ** createMatrix (int lines, int cols);
frac_t ** createMatrixFromInt(void * matInt, int lines, int cols);

#endif /* end of include guard: MATRIX_H */