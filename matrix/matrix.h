#ifndef MATRIX_H
#define MATRIX_H


typedef struct {
	int num;
	int den;
} frac_t;

extern frac_t detMatTriangle (frac_t ** mat, int n, int sign);
extern frac_t detMat (frac_t ** mat, int n);

extern void triangulation (frac_t ** mat, int n, int * sign);

extern frac_t ** createMatrix (int lines, int cols);
extern frac_t ** createMatrixFromInt(void * matInt, int lines, int cols);
extern frac_t ** copyMatrix (frac_t ** mat, int lines, int cols);

extern void dispMatrix (frac_t ** mat, int lines, int cols);
extern void dispFrac (frac_t frac, char * sep);

#endif /* end of include guard: MATRIX_H */