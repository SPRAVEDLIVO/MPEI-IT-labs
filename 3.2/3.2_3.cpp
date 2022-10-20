#include <iostream>
#define rows 10
#define columns 2
using namespace std;

int main() {
	double A[rows][columns];
	double T; cout << "T = "; cin >> T;
	bool flag = true;
	double sum = 0, diff = 0;
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		sum += A[i][0] + A[i][1];
		diff += A[i][0] - A[i][1];
		if (sum > T) {
			flag = false;
			break;
		}
		cout << "sum = " << sum << "; diff = " << diff << endl;
	}
	if (flag) cout << "Рассмотрен весь двумерный массив" << endl;

	return 0;
}
/*
Тест 1
T = 100
A[0][0] = 1.5
A[0][1] = -1
A[1][0] = 2.5
A[1][1] = -2
A[2][0] = 7
A[2][1] = 8
A[3][0] = -15.123
A[3][1] = 9
A[4][0] = 15
A[4][1] = 14
A[5][0] = -30
A[5][1] = -999
A[6][0] = 1000
A[6][1] = 5
A[7][0] = 4
A[7][1] = 3
A[8][0] = 2
A[8][1] = -10
A[9][0] = 9
A[9][1] = 2
sum = 0.5; diff = 2.5
sum = 1; diff = 7
sum = 16; diff = 6
sum = 9.877; diff = -18.123
sum = 38.877; diff = -17.123
sum = -990.123; diff = 951.877
sum = 14.877; diff = 1946.88
sum = 21.877; diff = 1947.88
sum = 13.877; diff = 1959.88
sum = 24.877; diff = 1966.88
Рассмотрен весь двумерный массив

Тест 2
T = 100
A[0][0] = 1.5
A[0][1] = -1
A[1][0] = 2.5
A[1][1] = -2
A[2][0] = 7
A[2][1] = 8
A[3][0] = -15.123
A[3][1] = 9
A[4][0] = 15
A[4][1] = 14
A[5][0] = -30
A[5][1] = -999
A[6][0] = 1000
A[6][1] = 5
A[7][0] = 4
A[7][1] = 3
A[8][0] = 2
A[8][1] = -10
A[9][0] = 9
A[9][1] = 101
sum = 0.5; diff = 2.5
sum = 1; diff = 7
sum = 16; diff = 6
sum = 9.877; diff = -18.123
sum = 38.877; diff = -17.123
sum = -990.123; diff = 951.877
sum = 14.877; diff = 1946.88
sum = 21.877; diff = 1947.88
sum = 13.877; diff = 1959.88

Тест 3
T = 15
A[0][0] = 1.5
A[0][1] = -1
A[1][0] = 2.5
A[1][1] = -2
A[2][0] = 7
A[2][1] = 8
A[3][0] = -15.123
A[3][1] = 9
A[4][0] = 15
A[4][1] = 14
A[5][0] = -30
A[5][1] = -999
A[6][0] = 1000
A[6][1] = 5
A[7][0] = 4
A[7][1] = 3
A[8][0] = 2
A[8][1] = -10
A[9][0] = 9
A[9][1] = 2
sum = 0.5; diff = 2.5
sum = 1; diff = 7
*/
