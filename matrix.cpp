#include <iostream>
#include "matrix.h"
#include <iostream>

using namespace std;

//contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix() {
	nRows = 0;
	nCols = 0;
	m = NULL;
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a 0.0 (double)
Matrix::Matrix(int rows, int cols) {
	nRows = rows;
	nCols = cols;
	m = new double*[nRows];
	for (int i = 0; i < nRows; i++)
		m[i] = new double[nCols];
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			m[i][j] = 0;
	}
}
// destrutor
Matrix::~Matrix() {
	for (int i = 0; i < nRows; i++)
		delete[] m[i];
	delete [] m;
}
// obtem o numero de linhas
int Matrix::getRows() const {
	return nRows;
}
// obtem o numero de colunas
int Matrix::getCols() const {
	return nCols;
}
// torna a matriz transposta
void Matrix::transpose() {
	//Cria uma nova matriz com numero de linhas e colunsa trocadas
	//copia os elementos da matriz X para a nova matriz
	//troca os ponteiros duplos para que o destruir do objeto desaloque
	//as memorias de matrizes nao utilizadas
	Matrix Y(nCols, nRows);

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			Y.m[j][i] = m[i][j];
	}
	
	double **temp;
	// Reapontamento dos apontadores da matriz
	temp = m;
	m = Y.m;
	Y.m = temp;
	// Troca do numero de linhas e colunas da matriz transposta
	nCols = Y.nCols;
	nRows = Y.nRows;
}

// imprime o conteudo da matriz
void Matrix::print() const {
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			cout << m[i][j]<< " ";
		cout << "\n";
	}
}