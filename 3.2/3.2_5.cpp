#include <iostream>
#define rows 2
#define columns 10
#define PI 3.141
#define PI_OVER_4 PI/4.0
using namespace std;

int main()
{
	double A[rows][columns], dIns, dOut;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	for (int j = 0; j < columns; j++) {
		dIns = A[0][j];
		dOut = A[1][j];
		if (dOut >= dIns) {
			cout << PI_OVER_4 * (dOut * dOut - dIns * dIns) << endl;

		}
		else {
			break;
		}
		if (j == columns - 1) {
			cout << "Considered the entire two-dimensional array" << endl;
		}
	}
	system("pause");
	return 0;
}

/*
Тест 1.
A[0][0] = 6
A[0][1] = 7
A[0][2] = 8
A[0][3] = 9
A[0][4] = 10
A[0][5] = 11
A[0][6] = 12
A[0][7] = 13
A[0][8] = 14
A[0][9] = 15
A[1][0] = 16
A[1][1] = 17
A[1][2] = 18
A[1][3] = 19
A[1][4] = 20
A[1][5] = 21
A[1][6] = 22
A[1][7] = 23
A[1][8] = 24
A[1][9] = 25
172.755
188.46
204.165
219.87
235.575
251.28
266.985
282.69
298.395
314.1
Considered the entire two-dimensional array
Тест 2.
A[0][0] = 6
A[0][1] = 7
A[0][2] = 8
A[0][3] = 9
A[0][4] = 10
A[0][5] = 11
A[0][6] = 12
A[0][7] = 13
A[0][8] = 14
A[0][9] = 15
A[1][0] = 16
A[1][1] = 17
A[1][2] = 18
A[1][3] = 19
A[1][4] = 20
A[1][5] = 21
A[1][6] = 22
A[1][7] = 23
A[1][8] = 24
A[1][9] = 1
172.755
188.46
204.165
219.87
235.575
251.28
266.985
282.69
298.395
Тест 3.
A[0][0] = 6
A[0][1] = 7
A[0][2] = 8
A[0][3] = 9
A[0][4] = 10
A[0][5] = 11
A[0][6] = 12
A[0][7] = 13
A[0][8] = 14
A[0][9] = 15
A[1][0] = 16
A[1][1] = 17
A[1][2] = 18
A[1][3] = 19
A[1][4] = 0.5
A[1][5] = 21
A[1][6] = 22
A[1][7] = 23
A[1][8] = 24
A[1][9] = 25
172.755
188.46
204.165
*/