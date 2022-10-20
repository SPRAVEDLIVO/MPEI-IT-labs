#include <iostream>
#define rows 3
#define columns 7
using namespace std;


int main()
{
	double A[rows][columns];
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int j = 0; j < columns; j++) {
		if (A[2][j] != (A[0][j] - A[1][j])) {
			cout << j + 1 << endl;
			count++;
		}
	}

	cout << "count = " << count << endl;
	system("pause");
}
/*
Результат:
A[0][0] = 30
A[0][1] = 29
A[0][2] = 28
A[0][3] = 27
A[0][4] = 26
A[0][5] = 25
A[0][6] = 24
A[1][0] = 10
A[1][1] = 9
A[1][2] = 8
A[1][3] = 7
A[1][4] = 6
A[1][5] = 5
A[1][6] = 4
A[2][0] = 3
A[2][1] = 21
A[2][2] = 21
A[2][3] = 21
A[2][4] = 20
A[2][5] = 74
A[2][6] = 21
1
2
3
4
6
7
count = 6
*/