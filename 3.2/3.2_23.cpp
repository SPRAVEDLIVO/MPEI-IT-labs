#include <iostream>
using namespace std;
#define rows 3
#define columns 7

int main() {
	double A[rows][columns], max, min, element, T, diff;
	bool flag = true;
	cout << "T = "; cin >> T;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	for (int j = 0; j < columns; j++) {
		min = A[0][j];
		max = A[0][j];
		for (int i = 0; i < rows; i++) {
			element = A[i][j];
			if (element > max) {
				max = element;
			}
			else if (element < min) {
				min = element;
			}
		}
		diff = max - min;
		if (diff > T) {
			flag = false;
			break;
		}
		cout << diff << endl;
	}
	if (flag) cout << "Considered the entire two dimensional array." << endl;
}

/* 
Тест 1
T = 8
A[0][0] = 2
A[0][1] = 3
A[0][2] = 4
A[0][3] = 0.5
A[0][4] = 0.7
A[0][5] = 0.331
A[0][6] = 8
A[1][0] = 5
A[1][1] = 1.25
A[1][2] = 5.25
A[1][3] = 7.122
A[1][4] = 1
A[1][5] = 5.5551
A[1][6] = 4.0000001
A[2][0] = 9
A[2][1] = 8
A[2][2] = 4.55
A[2][3] = 8
A[2][4] = 7.3
A[2][5] = 2
A[2][6] = 0
7
6.75
1.25
7.5
6.6
5.2241
8
Considered the entire two dimensional array.

Тест 2
T = 7
A[0][0] = 2
A[0][1] = 3
A[0][2] = 4
A[0][3] = 0.5
A[0][4] = 0.7
A[0][5] = 0.331
A[0][6] = 8
A[1][0] = 5
A[1][1] = 1.25
A[1][2] = 5.25
A[1][3] = 7.122
A[1][4] = 1
A[1][5] = 5.5551
A[1][6] = 4.0000001
A[2][0] = 9
A[2][1] = 8
A[2][2] = 4.55
A[2][3] = 8
A[2][4] = 7.3
A[2][5] = 2
A[2][6] = 0
7
6.75
1.25
7.5
6.6
5.2241

Тест 3
T = 7.01
A[0][0] = 2
A[0][1] = 3
A[0][2] = 4
A[0][3] = 0.5
A[0][4] = 0.7
A[0][5] = 0.331
A[0][6] = 8
A[1][0] = 5
A[1][1] = 1.25
A[1][2] = 5.25
A[1][3] = 7.122
A[1][4] = 1
A[1][5] = 5.5551
A[1][6] = 4.0000001
A[2][0] = 9
A[2][1] = 8
A[2][2] = 4.55
A[2][3] = 8
A[2][4] = 7.3
A[2][5] = 2
A[2][6] = 0
7
6.75
1.25
*/