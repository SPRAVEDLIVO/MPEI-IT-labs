#include <iostream>
#include <math.h>
using namespace std;
 
int main() {
    int columns, rows, count, countAll = 0;
    bool flag = true;
    double** A;
    int* C;
 
    cout << "columns = "; cin >> columns;
    cout << "rows = "; cin >> rows;
    
 
    A = new double* [rows];
    C = new int [rows];
 
    for (int i = 0; i < rows; i++) {
        A[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
        }
    }
 
    for (int i = 0; i < rows; i++) {
        count = 0;
        for (int j = 0; j < columns-1; j++) {
            if (A[i][j] > A[i][j + 1]) {
                count++;
            }
        }
        C[i] = count > 2 ? 1 : 0;
        countAll += count;
    }
 
    for (int i = 0; i < rows; i++) {
        cout << "C[" << i << "] = " << C[i] << endl;
    }
 
    cout << "countAll = " << countAll << endl;
 
    system("pause");
    return 0;
 
}
 
/*
Результат:
columns = 4
rows = 5
A[0][0] = 8
A[0][1] = 7.5
A[0][2] = 6
A[0][3] = 5
A[1][0] = 6
A[1][1] = 5
A[1][2] = 4
A[1][3] = 100
A[2][0] = 0.5
A[2][1] = 0.3
A[2][2] = 0.1
A[2][3] = 0
A[3][0] = 5
A[3][1] = 5
A[3][2] = 5
A[3][3] = 5
A[4][0] = 109
A[4][1] = 100
A[4][2] = 105
A[4][3] = 9999
C[0] = 1
C[1] = 0
C[2] = 1
C[3] = 0
C[4] = 0
countAll = 9
*/
