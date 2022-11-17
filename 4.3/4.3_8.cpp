#include <string>
#include <iostream>

using namespace std;

void input(double* A, int size, string name) {
	for (int i = 0; i < size; i++) {
		cout << name << "[" << i << "] = "; cin >> A[i];
	}
}



int count(double* A, int size) {
	int c = 0;
	for (int i = 0; i < size; i++) {
		if (A[i] == 0) c++;
	}
	return c;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int asize, bsize, csize;
	cout << "asize = "; cin >> asize;
	cout << "bsize = "; cin >> bsize;
	cout << "csize = "; cin >> csize;
	double* A = new double[asize];
	double* B = new double[bsize];
	double* C = new double[csize];
	input(A, asize, "A");
	input(B, bsize, "B");
	input(C, csize, "C");


	int countA = count(A, asize);
	int countB = count(B, bsize);
	int countC = count(C, csize);

	if (countA > countB && countA > countC) cout << "A";
	else if (countB > countA && countB > countC) cout << "B";
	else cout << "C";
	cout << endl;

	system("pause");
}

/*
asize = 2
bsize = 2
csize = 2
A[0] = 0
A[1] = 1
B[0] = 0
B[1] = 0
C[0] = 1
C[1] = 2
B
*/
