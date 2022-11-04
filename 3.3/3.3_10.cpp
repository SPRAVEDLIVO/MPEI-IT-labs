#include <iostream>
using namespace std;

int main() {
	double rows, columns, sum = 0;
	int count = 0;
	bool flag;
	cout << "rows = "; cin >> rows;
	cout << "columns = "; cin >> columns;
	double** A = new double* [rows];
	for (int i = 0; i < rows; i++) {
		A[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		flag = true;
		for (int j = 0; j < columns; j++) {
			sum += A[i][j];
			if (j > 0 && A[i][j] <= A[i][j - 1]) {
				flag = false;
			}
		}
		if (flag) count++;
	}

	cout << "sum = " << sum << endl;
	cout << "count = " << count << endl;
}

/*
rows = 2
columns = 2
A[0][0] = 2
A[0][1] = 3
A[1][0] = 3
A[1][1] = 2
sum = 10
count = 1*/