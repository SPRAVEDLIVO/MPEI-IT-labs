#include <iostream>
using namespace std;

int main() {
	int columns, rows;
	bool flag;
	double** A, * C;

	cout << "rows = "; cin >> rows;
	cout << "columns = "; cin >> columns;
	A = new double* [rows];
	C = new double[columns];


	for (int i = 0; i < rows; i++) {
		A[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int j = 0; j < columns; j++) {
		flag = true;
		for (int i = 0; i < rows; i++) {
			flag = flag && A[i][j] == 0;
			if (!flag) break;
		}
		C[j] = !flag;
	}

	for (int j = 0; j < columns; j++) {
		cout << C[j] << endl;
	}

	return 0;
}

/* 
rows = 2
columns = 2
A[0][0] = 0
A[0][1] = 2
A[1][0] = 0
A[1][1] = 0
0
1
*/
