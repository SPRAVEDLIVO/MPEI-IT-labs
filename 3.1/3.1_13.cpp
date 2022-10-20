#include <iostream>
#include <math.h>
#define PI 3.14
#define rows 6
#define columns 4
using namespace std;

int main() {
	double A[rows][columns], mean, T;
	int count = 0;
	cout << "T = "; cin >> T;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	for (int i = 0; i < rows; i++) {
		mean = (A[i][0] + A[i][1] + A[i][2] + A[i][3]) / 4.0;
		if (mean > T) {
			cout << i + 1 << endl;
			count++;
		}
	}
	cout << "count = " << count << endl;
}

/*
Если надо показать, что прога просто работает измените #define rows 6 на #define rows 1 и введите следующие данные:
T = 2.5
A[0][0] = 4
A[0][1] = 5
A[0][2] = 4
A[0][3] = 5
Получите результат:
1
count = 1

Результат:
T = 3.5
A[0][0] = 4
A[0][1] = 5
A[0][2] = 4
A[0][3] = 5
A[1][0] = 2
A[1][1] = 3
A[1][2] = 5
A[1][3] = 5
A[2][0] = 3
A[2][1] = 3
A[2][2] = 4
A[2][3] = 5
A[3][0] = 3
A[3][1] = 3
A[3][2] = 4
A[3][3] = 4
A[4][0] = 3
A[4][1] = 4
A[4][2] = 3
A[4][3] = 3
A[5][0] = 2
A[5][1] = 2
A[5][2] = 5
A[5][3] = 5
1
2
3
count = 3
*/