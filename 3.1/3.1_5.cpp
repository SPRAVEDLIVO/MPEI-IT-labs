#include <iostream>
#include <math.h>
#define rows 6
#define columns 3
using namespace std;

int main()
{
	double A[rows][columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < rows; i++) {
		if (A[i][1] < ((A[i][0] + A[i][1] + A[i][2]) / 3.0)) {
			cout << i + 1 << endl;
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}

/*
	 Результат:
	 (вып. условие, строки 1-4)
	 1 
	 2
	 4
	 1
	 5
	 10
	 8
	 0.5
	 777
	 -20
	 -40
	 -20
	 (невып. условие, строки 5-6)
	 2
	 2
	 2
	 -20
	 -40
	 -100
	 (вывод)
	 1
	 2
	 3
	 4
	 4
*/