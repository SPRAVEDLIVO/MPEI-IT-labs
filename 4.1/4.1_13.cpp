#include <string>
#include <iostream>
#include <math.h>
 
using namespace std;
 
void input(double* A, int size, string name) {
    for (int i = 0; i < size; i++) {
        cout << name << "[" << i << "] = "; cin >> A[i];
    }
}
 
void output(double* A, int size, string name) {
    for (int i = 0; i < size; i++) {
        cout << name << "[" << i << "] = " << A[i] << endl;
    }
}
 
double mean(double *A, int size, double T) {
    int count = 0;
    double sum = 0;
 
    for (int i = 0; i < size; i++) {
        if (pow(A[i], 2) > T) {
            count++;
            sum += A[i];
        }
    }
    return sum / count;
 
}
 
int main() {
    setlocale(LC_ALL, "Russian");
    int asize, bsize;
    cout << "asize = "; cin >> asize;
    cout << "bsize = "; cin >> bsize;
    double* A = new double[asize];
    double* B = new double[bsize];
    input(A, asize, "A");
    input(B, bsize, "B");
 
    double H, M;
    cout << "H = "; cin >> H;
    cout << "M = "; cin >> M;
 
    if (mean(A, asize, H) == mean(B, bsize, M)) {
        cout << "A и B эквивалентны" << endl;
    }
    else {
        int csize;
        cout << "csize = "; cin >> csize;
        double* C = new double[csize];
        double T;
        cout << "T = "; cin >> T;
        input(C, csize, "C");
        cout << mean(C, csize, T) << endl;
    }
    system("pause");
 
}
 
/*
asize = 3
bsize = 2
A[0] = 2
A[1] = 4
A[2] = 9
B[0] = 5
B[1] = 4
H = 3
M = 16
A и B эквивалентны
*/
