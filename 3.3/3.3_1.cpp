#include <iostream>
using namespace std;

int main() {
	int columns, rows, countAll = 0, count, el;
	double** A;
	double sum = 0;
	int* C;

	cout << "columns = "; cin >> columns;
	cout << "rows = "; cin >> rows;
	

	A = new double* [rows];
	C = new int [rows];

	for (int i = 0; i < rows; i++) {
		A[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		count = 0;
		for (int j = 0; j < columns; j++) {
			el = A[i][j];
			if (el >= 0) {
				count++;
				countAll++;
				sum += el;
			}
		}
		cout << "count[" << i << "] = " << count << endl;

	}

	cout << "mean = " << countAll / sum << endl;
	

	system("pause");
	return 0;

}

/*
Результат:
columns = 2
rows = 3
A[0][0] = 0
A[0][1] = 2
A[1][0] = -1
A[1][1] = 6
A[2][0] = 7
A[2][1] = 8
count[0] = 2
count[1] = 1
count[2] = 2
mean = 0.217391
*/
