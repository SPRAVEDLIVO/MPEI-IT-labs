#include <iostream>
using namespace std;

int main() {
	double** A;
	double sumLocal, sumMain = 0, el, sum = 0;
	int size, count = 0; cout << "size = "; cin >> size;
	A = new double* [size];

	for (int i = 0; i < size; i++) {
		A[i] = new double[size];
		for (int j = 0; j < size; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int j = 0; j < size; j++) {
		sumLocal = 0;
		for (int i = 0; i < size; i++) {
			el = A[i][j];
			if (i == j) {
				sumMain += el;
			}
			sumLocal += el;
		}
		if (sumLocal > 0) sum += sumLocal;
	}
	cout << "sumMain = " << sumMain << endl << "sum = " << sum << endl;
}

/*
size = 3
A[0][0] = 2
A[0][1] = -5
A[0][2] = 3
A[1][0] = 4
A[1][1] = 1
A[1][2] = 8
A[2][0] = 3
A[2][1] = 1
A[2][2] = 4
sumMain = 7
sum = 24
*/