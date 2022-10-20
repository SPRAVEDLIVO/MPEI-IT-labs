#include <iostream>
using namespace std;
#define rows 2
#define columns 9

int main() {
	double A[rows][columns], T;
	int count = 0;
	cout << "T = "; cin >> T;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	for (int j = 0; j < columns; j++) {
		if (fabs(A[0][j]) < T && fabs(A[1][j]) < T) {
			cout << (A[0][j] + A[1][j]) / 2.0 << endl;
			count++;
		}
	}
	cout << "count = " << count << endl;
	system("pause");
}

/* 
T = 20
8.25
13
13
13.0125
13
count = 5
*/
