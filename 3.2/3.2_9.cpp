#include <iostream>
#include <math.h>
#define rows 2
#define columns 2
using namespace std;

int main()
{
	double A[rows][columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 1; i < rows; i++) {
		if (A[i][1] > A[i - 1][0]) {
			break;
		}
		cout << A[i][1] << endl;
		if (i == rows - 1) {
			cout << "Сonsidered the entire two - dimensional array" << endl;
			system("pause");
		}
	}

	return 0;
}

/* TESTS
чтобы показать, что просто прога воркает преподу измените rows на 2 и введите значения 4 3 2 1

Тест первый.
A[0][0] = 20
A[0][1] = 19
A[1][0] = 18
A[1][1] = 17
A[2][0] = 16
A[2][1] = 15
A[3][0] = 14
A[3][1] = 13
A[4][0] = 12
A[4][1] = 11
A[5][0] = 10
A[5][1] = 9
A[6][0] = 8
A[6][1] = 7
A[7][0] = 6
A[7][1] = 5
A[8][0] = 4
A[8][1] = 3
A[9][0] = 2
A[9][1] = 1
17
15
13
11
9
7
5
3
1
Сonsidered the entire two - dimensional array

Тест 2.
A[0][0] = 20
A[0][1] = 19
A[1][0] = 18
A[1][1] = 17
A[2][0] = 16
A[2][1] = 15
A[3][0] = 14
A[3][1] = 13
A[4][0] = 12
A[4][1] = 11
A[5][0] = 10
A[5][1] = 9
A[6][0] = 8
A[6][1] = 7
A[7][0] = 6
A[7][1] = 5
A[8][0] = 4
A[8][1] = 3
A[9][0] = 2
A[9][1] = 5
17
15
13
11
9
7
5
3

Тест 3.
A[0][0] = 20
A[0][1] = 19
A[1][0] = 18
A[1][1] = 17
A[2][0] = 16
A[2][1] = 19
A[3][0] = 14
A[3][1] = 13
A[4][0] = 12
A[4][1] = 11
A[5][0] = 10
A[5][1] = 9
A[6][0] = 8
A[6][1] = 7
A[7][0] = 6
A[7][1] = 5
A[8][0] = 4
A[8][1] = 3
A[9][0] = 2
A[9][1] = 1
17
*/