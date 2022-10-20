#include <iostream>
using namespace std;

int main() {
	int size;
	double** A, el, sum = 0;
	bool flag;

	cout << "size = "; cin >> size;

	A = new double* [size];
	int* X = new int[size];

	for (int i = 0; i < size; i++) {
		A[i] = new double[size];
		for (int j = 0; j < size; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		el = A[i][i];
		flag = true;
		for (int j = 0; j < size; j++) {
			flag = flag && ((el > A[i][j]) || j == i);
			sum += A[i][j];
		}
		X[i] = flag;
	}
	for (int i = 0; i < size; i++) {
		cout << "X[" << i << "] = " << X[i] << endl;
	}

	cout << "sum = " << sum << endl;
}

/* 
size = 2
A[0][0] = 100
A[0][1] = 5
A[1][0] = 0
A[1][1] = -1
X[0] = 1
X[1] = 0
sum = 104
*/
