п»ї#include <string>
#include <iostream>

using namespace std;

void input(double* A, int size, string name) {
	for (int i = 0; i < size; i++) {
		cout << name << "[" << i << "] = "; cin >> A[i];
	}
}

void output(double* A, int size, string name) {
	for (int i = 0; i < size; i++) {
		cout << name << "[" << i << "] = " << A[i] << endl;
	}
}

int maxIdxAbs(double* A, int size) {
	double maxIdx = 0;
	double maxValue = 0;

	for (int i = 1; i < size; i++) {
		if (A[i] > maxValue) {
			maxIdx = i;
			maxValue = A[i];
		}
	}

	return maxIdx;
}

int main() {
	int rsize, qsize;
	cout << "rsize = "; cin >> rsize;
	cout << "qsize = "; cin >> qsize;
	double* R = new double[rsize], * Q = new double[qsize];
	input(R, rsize, "R");
	input(Q, qsize, "Q");
	int maxIdxR = maxIdxAbs(R, rsize);
	int maxIdxQ = maxIdxAbs(Q, qsize);

	if (maxIdxR == maxIdxQ && maxIdxR > 1) output(R, rsize, "R");
	else output(Q, qsize, "Q");
	system("pause");

}

/*
rsize = 3
qsize = 3
R[0] =  1
R[1] =  2
R[2] =  3
Q[0] =  4
Q[1] =  5
Q[2] =  6
R[0] =  1
R[1] =  2
R[2] =  3
*/