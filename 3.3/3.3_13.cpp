#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int columns, rows, count = 0, localCount;
	double** A;

	cout << "rows = "; cin >> rows;
	cout << "columns = "; cin >> columns;

	A = new double* [rows];

	for (int i = 0; i < rows; i++) {
		A[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		localCount = 0;
		for (int j = 0; j < columns; j++) {
			if (A[i][j] < 0) {
				A[i][j] += j == 0 ? A[i][columns - 1] : A[i][j - 1];
				localCount++;
			}

		}
		count += localCount == 0;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = " << A[i][j] << endl;
		}
	}
	cout << "count = " << count << endl;
}

/* 
rows = 3
columns = 3
A[0][0] = -15
A[0][1] = 0
A[0][2] = 15
A[1][0] = 2
A[1][1] = 5
A[1][2] = -5
A[2][0] = 1
A[2][1] = 2
A[2][2] = 3
A[0][0] = 0
A[0][1] = 0
A[0][2] = 15
A[1][0] = 2
A[1][1] = 5
A[1][2] = 0
A[2][0] = 1
A[2][1] = 2
A[2][2] = 3
count = 1
*/
