#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

typedef enum {false, true} bool;


/*************************************/
/******  Operation on fraction  ******/
/*************************************/

static int pgcd (int a, int b) {
	int c;
	if (a < b) c = a, a = b, b = c;
	while ((c = a % b) != 0) a = b, b = c;
	return b;
}

static void reduceFraction (frac_t * f) {
	if (f->num == 0) {
		f->den = 1;
		return;
	}
	int sign = (f->num * f->den > 0) ? 1 : -1;
	if (f->num < 0) f->num *= -1;
	if (f->den < 0) f->den *= -1;
	int d = pgcd(f->num, f->den);
	f->num /= d;
	f->den /= d;
	f->num *= sign;

}

static frac_t multiplyFraction(frac_t f1, frac_t f2) {
	frac_t res;
	res.num = f1.num * f2.num;
	res.den = f1.den * f2.den;
	return res;
}

static frac_t addFraction (frac_t f1, frac_t f2) {
	frac_t res;
	res.den = f1.den * f2.den;
	res.num = (f1.num * f2.den) + (f2.num * f1.den);
	return res;
}


/****************************************/
/*********  Creation of matrix  *********/
/****************************************/

extern frac_t ** createMatrix (int lines, int cols) {
	frac_t ** mat = malloc (lines * sizeof(frac_t*));
	int i;
	for (i = 0; i < lines; i++) {
		mat[i] = malloc (cols * sizeof(frac_t));
	}
	return mat;
}

frac_t ** createMatrixFromInt(void * matInt, int lines, int cols) {
	int i, j;
	int si = sizeof(int);
	frac_t ** mat = createMatrix(lines, cols);
	for (i = 0; i < lines; i++) {
		for (j = 0; j < cols; j++) {
			int * matIntIJ = matInt + i * cols * si + j * si;
			mat[i][j].num = *matIntIJ;
			mat[i][j].den = 1;
		}
	}
	return mat;
}

extern frac_t ** copyMatrix (frac_t ** mat, int lines, int cols) {
	frac_t ** cpy = createMatrix(lines, cols);
	int i, j;
	for (i = 0; i < lines; i++) for (j = 0; j < cols; j++)
		cpy[i][j] = mat[i][j];
	return cpy;
}

/*********************************************/
/***********  Operation on matrix  ***********/
/*********************************************/

static void exchangeLines (frac_t ** mat, int l1, int l2) {
	frac_t * tmpLine = mat[l1];
	mat[l1] = mat[l2];
	mat[l2] = tmpLine;
}

static void exchangeCols (frac_t ** mat, int c1, int c2, int lines) {
	frac_t * tmpCol = malloc(lines * sizeof(frac_t));
	int i;
	for (i = 0; i < lines; i++) tmpCol[i] = mat[i][c1];
	for (i = 0; i < lines; i++) mat[i][c1] = mat[i][c2];
	for (i = 0; i < lines; i++) mat[i][c2] = tmpCol[i];
	free(tmpCol);
}

static void addLine (frac_t ** mat, int dstLine, int srcLine, frac_t mult, int cols, int firstCol) {
	int j;
	for (j = firstCol; j < cols; j++) {
		frac_t fadd = multiplyFraction(mat[srcLine][j], mult);
		mat[dstLine][j] = addFraction(mat[dstLine][j], fadd);
	}
}

static bool firstNonZero (frac_t ** mat, int firstLine, int firstCol, int n, int * line, int * col) {
	int i, j;
	for (i = firstLine; i < n; i++) {
		for (j = firstCol; j < n; j++) {
			if (mat[i][j].num != 0) {
				*line = i;
				*col = j;
				return true;
			}
		}
	}
	return false;
}

extern void triangulation (frac_t ** mat, int n, int * sign) { // the matrix must be a square
	int i, j, k, lines = n, cols = n, step = n-1;
	*sign = 1;
	for (k = 0; k < step; k++) {
		i = j = k;

		// look for a non-zero on the first column
		while (i < lines && mat[i][j].num == 0) i++;

		// if there isn't then look for a non-zero on the sub matrix
		// starting at line k and col k+1
		// (because col k as already been checked)
		if (i >= lines) {
			// if everything is at 0 then the matrix is already triangularized
			if (firstNonZero(mat, k, k+1, n, &i, &j) == false)
				return;
		}

		// once a non-zero value is found, place it at the k,k position
		if (i != k) exchangeLines (mat, k, i);
		if (j != k) exchangeCols (mat, k, j, lines);

		// and do stuff with the sign
		if ((i + j) % 2 == 1) (*sign) *= -1;

		for (i = k+1; i < lines; i++) {
			if (mat[i][k].num != 0) {
				frac_t mult;// mult = first/pivot
				mult.num = mat[i][k].num * mat[k][k].den * -1;
				mult.den = mat[i][k].den * mat[k][k].num;
				addLine (mat, i, k, mult, cols, k);
			}
		}
	}
	for (i = 0; i < lines; i++) for (j = 0; j < cols; j++)
		reduceFraction(&(mat[i][j]));
}


/************************************************/
/*********  Calculation of determinant  *********/
/************************************************/

extern frac_t detMatTriangle (frac_t ** mat, int n, int sign) {
	frac_t det = {sign, 1};
	int i;
	for (i = 0; i < n; i++) det = multiplyFraction(det, mat[i][i]);
	reduceFraction(&det);
	return det;
}

extern frac_t detMat (frac_t ** mat, int n) {
	int sign;
	frac_t ** tri = copyMatrix(mat, n, n);
	triangulation(tri, n, &sign);
	return detMatTriangle(tri, n, sign);
}

/*********************************************/
/*****************  Display  *****************/
/*********************************************/

extern void dispFrac (frac_t frac, char * sep) {
	printf ("%3d/%3d%s", frac.num, frac.den, sep);
}


extern void dispMatrix (frac_t ** mat, int lines, int cols) {
	int i, j;
	for (i = 0; i < lines; i++) {
		for (j = 0; j < cols; j++)
			dispFrac(mat[i][j], " ");
		printf("\n");
	}
	printf("\n\n");
}
