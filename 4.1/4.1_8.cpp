#include <string>
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

int count(double* A, int size) {
	int c = 0;
	for (int i = 0; i < size; i++) {
		if (A[i] < 0) break;
		c++;
	}
	return c;
}

double mean(double* A, int size) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += A[i];
	}
	return sum / size;

}


int main() {
	setlocale(LC_ALL, "Russian");
	int asize, bsize;
	cout << "asize = "; cin >> asize;
	cout << "bsize = "; cin >> bsize;
	double* A = new double[asize];
	double* B = new double[bsize];
	input(A, asize, "A");
	input(B, bsize, "B");

	int countA = count(A, asize);
	int countB = count(B, bsize);

	if (countA == countB) cout << "Массивы экивалентны";
	else if (countA < countB) cout << mean(A, asize);
	else cout << mean(B, bsize);

	cout << endl;
	system("pause");
}

/*
asize = 3
bsize = 3
A[0] = 1
A[1] = 2
A[2] = -2
B[0] = 1
B[1] = -4
B[2] = 3
0
*/
