#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int columns, rows, xSize;
	double** A, sum, *C, *X;

	cout << "rows = "; cin >> rows;
	cout << "columns = "; cin >> columns;

	A = new double* [rows];
	C = new double[columns];
	X = new double[columns];

	for (int i = 0; i < rows; i++) {
		A[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
			cout << "X[" << i << "] = "; cin >> X[i];
	}
	
	for (int i = 0; i < rows; i++) {

		sum = 0;
		for (int j = 0; j < columns; j++) {
			sum += A[i][j];
		}
		C[i] = X[i] < sum ? sum : X[i];
	}

	for (int i = 0; i < rows; i++) {
		cout << "C[" << i << "] = " << C[i] << endl;
	}
	system("pause");
}

/* 
rows = 2
columns = 2
A[0][0] = 1
A[0][1] = 2
A[1][0] = 5
A[1][1] = 4
X[0] = 0
X[1] = 100
C[0] = 3
C[1] = 100
*/
