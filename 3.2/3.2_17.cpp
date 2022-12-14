#include <iostream>
using namespace std;
#define rows 10
#define columns 3

int main() {

	setlocale(LC_ALL, "Russian");
	double A[rows][columns];
	bool flag = true;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		if (!(A[i][0] < A[i][1] && A[i][1] < A[i][2])) {
			flag = false;
			cout << "Упорядоченность нарушена" << endl;
			break;
		}
	}

	if (flag) cout << "Все строки упорядочены" << endl;

	system("pause");
}

/* 
Тест 1
A[0][0] = 1
A[0][1] = 2
A[0][2] = 3
A[1][0] = 4
A[1][1] = 5
A[1][2] = 6
A[2][0] = 7
A[2][1] = 8
A[2][2] = 9
A[3][0] = 10
A[3][1] = 11
A[3][2] = 12
A[4][0] = 13
A[4][1] = 14
A[4][2] = 15
A[5][0] = 16
A[5][1] = 17
A[5][2] = 18
A[6][0] = 19
A[6][1] = 20
A[6][2] = 21
A[7][0] = 22
A[7][1] = 23
A[7][2] = 24
A[8][0] = 25
A[8][1] = 27
A[8][2] = 28
A[9][0] = 30
A[9][1] = 32
A[9][2] = 35
Все строки упорядочены
Тест 2
A[0][0] = 1
A[0][1] = 2
A[0][2] = 3
A[1][0] = 4
A[1][1] = 5
A[1][2] = 6
A[2][0] = 7
A[2][1] = 8
A[2][2] = 9
A[3][0] = 10
A[3][1] = 11
A[3][2] = 12
A[4][0] = 13
A[4][1] = 14
A[4][2] = 15
A[5][0] = 16
A[5][1] = 17
A[5][2] = 18
A[6][0] = 19
A[6][1] = 20
A[6][2] = 21
A[7][0] = 22
A[7][1] = 23
A[7][2] = 24
A[8][0] = 25
A[8][1] = 27
A[8][2] = 28
A[9][0] = 30
A[9][1] = 32
A[9][2] = 30
Упорядоченность нарушена
Тест 3
A[0][0] = 100
A[0][1] = 2
A[0][2] = 3
A[1][0] = 4
A[1][1] = 5
A[1][2] = 6
A[2][0] = 7
A[2][1] = 8
A[2][2] = 9
A[3][0] = 10
A[3][1] = 11
A[3][2] = 12
A[4][0] = 13
A[4][1] = 14
A[4][2] = 15
A[5][0] = 16
A[5][1] = 17
A[5][2] = 18
A[6][0] = 19
A[6][1] = 20
A[6][2] = 21
A[7][0] = 22
A[7][1] = 23
A[7][2] = 24
A[8][0] = 25
A[8][1] = 27
A[8][2] = 28
A[9][0] = 30
A[9][1] = 32
A[9][2] = 35
Упорядоченность нарушена
*/
