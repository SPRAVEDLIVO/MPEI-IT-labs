#include <iostream> // не писать в тетрадь
#define rows 7
#define columns 3
using namespace std; // не писать в тетрадь
 
 
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
		if (A[i][2] > (A[i][0] + A[i][1])) {
			cout << i << endl;
			count++;
		}
	}
 
	cout << "count = " << count << endl;
	system("pause");
}
/* 
Результат: 
A[0][0] = 0
A[0][1] = 1
A[0][2] = 2.5
A[1][0] = -2
A[1][1] = -100
A[1][2] = -200
A[2][0] = -5
A[2][1] = -12.225
A[2][2] = 0
A[3][0] = 7
A[3][1] = 8
A[3][2] = 15
A[4][0] = 1
A[4][1] = 1
A[4][2] = 3
A[5][0] = 45
A[5][1] = 1000000
A[5][2] = 10
A[6][0] = 0.1
A[6][1] = 0.3
A[6][2] = 0.4
0
2
4
count = 3
*/
