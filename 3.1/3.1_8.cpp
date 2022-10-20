#include <iostream>
#define rows 10
#define columns 2
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

	for (int i = 0; i < rows; i++) {
		if (A[i][0] == A[i][1]) {
			cout << i+1 << endl;
			count++;
		}
	}

	cout << "count = " << count << endl;
	system("pause");
}
/*
Результат:
A[0][0] = 1
A[0][1] = 1
A[1][0] = 0.5
A[1][1] = 0.5
A[2][0] = 2
A[2][1] = 3
A[3][0] = 4
A[3][1] = 5
A[4][0] = 6
A[4][1] = 6
A[5][0] = 7
A[5][1] = 8
A[6][0] = 9
A[6][1] = 10
A[7][0] = 11
A[7][1] = 11
A[8][0] = 12.0052
A[8][1] = 12.0052
A[9][0] = 0
A[9][1] = 0
1
2
5
8
9
10
count = 6
*/
