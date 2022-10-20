#include <iostream>
using namespace std;
#define rows 10
#define columns 3

int main() {
	double A[rows][columns], el;
	bool flag;
	int count = 0;
	double R1, R2, x, y, z, point;
	cout << "R1 = "; cin >> R1;
	cout << "R2 = "; cin >> R2;
	R1 *= R1;
	R2 *= R2;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		x = A[i][0];
		y = A[i][1];
		z = A[i][2];
		point = x * x + y * y + z * z;
		
		if (point > R1 && point < R2) {
			count++;
			cout << i + 1 << endl;
		}
	}
	cout << "count = " << count << endl;
}

/* 
R1 = 11
R2 = 44
A[0][0] = 48.4548
A[0][1] = 3.3792
A[0][2] = 10.5534
A[1][0] = 45.3364
A[1][1] = 63.1087
A[1][2] = 72.9551
A[2][0] = 66.8365
A[2][1] = 61.4143
A[2][2] = 69.1899
A[3][0] = 24.3558
A[3][1] = 14.2052
A[3][2] = 70.7553
A[4][0] = 72.3914
A[4][1] = 38.4296
A[4][2] = 30.5753
A[5][0] = 45.8799
A[5][1] = 20.8753
A[5][2] = 70.049
A[6][0] = 28.8245
A[6][1] = 7.5816
A[6][2] = 67.9432
A[7][0] = 35.9551
A[7][1] = 16.8708
A[7][2] = 40.7112
A[8][0] = 28.0704
A[8][1] = 28.314
A[8][2] = 9.3193
A[9][0] = 69.588
A[9][1] = 44.4733
A[9][2] = 60.8769
9
count = 1
*/