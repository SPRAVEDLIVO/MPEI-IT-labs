#include <iostream>

using namespace std;

int main()
{
    int size;
	cout << "size = ";cin >> size;
	double** A = new double* [size];
    double sum, P;
	for (int i = 0; i < size; i++)
	{
        A[i] = new double[size];
		for (int j = 0; j < size; j++)
		{
			cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
		}
	}
	int *X = new int[size];
	for (int j = 0; j < size; j++) {
        sum = 0;
        P = 1;
        for (int i = 0; i < size; i++) {
            sum += A[i][j];
            P *= A[i][j];
        }
        if (sum>P) X[j] = 1;
        else X[j] = 0;
    }

    for (int i = 0; i<size;i++) {
            cout << "X[" << i << "] = " << X[i]  << endl;
    }
}
