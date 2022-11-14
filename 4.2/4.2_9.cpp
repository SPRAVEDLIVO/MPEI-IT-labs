

#include <iostream>
#include <math.h>
#define rows 3
#define colums 3
using namespace std;
int f(double* A) {
    int k = 0;
    double B[rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++)
            if (A[i] == 0) {
                k++;
                B[i] = k;
            }
        return k;
    }
    for (int i = 0; i < rows; i++) {
        cout << B[i];
    }
}


int main()
{
    double A[rows][colums];
    double B[rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            cout << "A [" << i << "] [" << j << "] = ";
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "Result " << f(*A);
}