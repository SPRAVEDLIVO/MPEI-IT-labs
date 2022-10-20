#include <iostream>
#include <math.h>
#define rows 2
#define columns 10
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double A[rows][columns];
	double mul;
	bool flag = true;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	for (int j = 0; j < columns; j++) {
		mul = A[0][j] * A[1][j];

		if (mul < 0) {
			flag = false;
			break;
		}

		cout << mul << endl;
	}
	if (flag) cout << "Рассмотрен весь двумерный массив" << endl;
	system("pause");
	return 0;

}
