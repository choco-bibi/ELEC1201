Matrix createMatrix(const unsigned int nRows, const unsigned int nCols)
{
	Matrix mat;
	mat.rows = nRows;
	mat.cols = nCols;
	int i;
	mat.element = (double**) calloc(mat.rows, sizeof(double*));
	 for (i=0; i<mat.rows;i++){
		 mat.element [i] = (double*) calloc(mat.cols, sizeof(double));
	 }
	return mat;
}


void destroyMatrix(Matrix mat)
{
	unsigned int i;
	for (i = 0; i < mat.rows; free(mat.element[i++])) {
		free(mat.element);
	}
}

void printMatrix(const Matrix mat)
{
	unsigned int i, j;
	for (i=0; i<mat.rows; i++)
		for (j=0; j<mat.cols; j++)
			printf("[%d][%d] = %f\n", i, j, mat.element[i][j]);
}

int main() {
	Matrix m;
	m=createMatrixFromFile("example1.mat");
	printMatrix(m);
	destroyMatrix(m);
	return 0;
}
