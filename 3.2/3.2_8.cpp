#include <iostream>
#define rows 10
#define columns 2
using namespace std;


int main()
{
	double A[rows][columns], sumX = 0, sumY = 0, x, y;
	bool flag = true;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		x = A[i][0];
		y = A[i][1];
		if (x < 0 || y < 0) {
			flag = false;
			break;
		}
		sumX += x;
		sumY += y;
		cout << "sumX = " << sumX << "; sumY = " << sumY << endl;
	}
	if (flag) cout << "Considered the entire two dimensional array" << endl;
	system("pause");
}
/*
Результат:
Test 1
A[0][0] = 0.1
A[0][1] = 1
A[1][0] = 0.3
A[1][1] = 0.9
A[2][0] = 0.6
A[2][1] = 0.1
A[3][0] = 2
A[3][1] = 3
A[4][0] = 4
A[4][1] = 5
A[5][0] = 6
A[5][1] = 7
A[6][0] = 8
A[6][1] = 9
A[7][0] = 10
A[7][1] = 11
A[8][0] = 12
A[8][1] = 13
A[9][0] = 14
A[9][1] = 15
sumX = 0.1; sumY = 1
sumX = 0.4; sumY = 1.9
sumX = 1; sumY = 2
sumX = 3; sumY = 5
sumX = 7; sumY = 10
sumX = 13; sumY = 17
sumX = 21; sumY = 26
sumX = 31; sumY = 37
sumX = 43; sumY = 50
sumX = 57; sumY = 65
Considered the entire two dimensional array

Test 2
A[0][0] = 0.1
A[0][1] = 1
A[1][0] = 0.3
A[1][1] = 0.9
A[2][0] = 0.6
A[2][1] = 0.1
A[3][0] = 2
A[3][1] = 3
A[4][0] = 4
A[4][1] = 5
A[5][0] = 6
A[5][1] = 7
A[6][0] = 8
A[6][1] = 9
A[7][0] = 10
A[7][1] = 11
A[8][0] = 12
A[8][1] = 13
A[9][0] = 14
A[9][1] = -1
sumX = 0.1; sumY = 1
sumX = 0.4; sumY = 1.9
sumX = 1; sumY = 2
sumX = 3; sumY = 5
sumX = 7; sumY = 10
sumX = 13; sumY = 17
sumX = 21; sumY = 26
sumX = 31; sumY = 37
sumX = 43; sumY = 50

Test 3
A[0][0] = 0.1
A[0][1] = 1
A[1][0] = 0.3
A[1][1] = 0.9
A[2][0] = -7
A[2][1] = 0.1
A[3][0] = 2
A[3][1] = 3
A[4][0] = 4
A[4][1] = 5
A[5][0] = 6
A[5][1] = 7
A[6][0] = 8
A[6][1] = 9
A[7][0] = 10
A[7][1] = 11
A[8][0] = 12
A[8][1] = 13
A[9][0] = 14
A[9][1] = 15
sumX = 0.1; sumY = 1
sumX = 0.4; sumY = 1.9
*/
