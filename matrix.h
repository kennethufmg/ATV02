#ifndef MATRIX_H
#define MATRIX_H
// matrix.h (header file)
#include <iostream>

class Matrix {
private:

	double** m; // m é um array 2D a ser implementado como um pointer de pointers
	int nRows;  // numero de linhas
	int nCols;  //  numero de colunas

public:

	// Construtores
	Matrix();
	Matrix(int rows, int cols);
	// destrutor
	~Matrix();

	// basic getters
	int getRows() const;
	int getCols() const;
	//double getValue(int ls, int cs) const;


	// other methods
	void transpose();
	void print() const;


};
#endif //MATRIX_H
