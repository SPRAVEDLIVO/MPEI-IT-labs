#include <iostream>
#include <math.h>
#define rows 2
#define columns 2
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double A[rows][columns];
	bool flag = true;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	for (int j = 0; j < columns-1; j++) {
		if ((A[0][j] < A[0][j+1]) && (A[1][j] > A[1][j + 1])) {
			cout << pow(A[0][j], 2) - pow(A[1][j], 2) << endl;
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) cout << "Рассмотрен весь двумерный массив" << endl;
	system("pause");
	return 0;

}
