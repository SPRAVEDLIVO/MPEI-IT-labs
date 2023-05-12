// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define mmax 10
#define nmax 10


using namespace std;

class complex {
    private:
        double re, im;
    public:
        complex(int a = 0, int b = 0) {
            set(a, b);
        }
        void set(int a, int b) {
            re = a;
            im = b;
        }
        friend ostream& operator<< (ostream & out, complex & c);
        friend istream& operator>> (istream& in, complex& c);
        double module() {
            return sqrt(pow(re, 2) + pow(im, 2));
        }
        bool operator==(double cmp) {
            return module() == cmp;
        }
};

ostream& operator<< (ostream& out, complex& c) {
    out << c.re << (c.im >= 0 ? "+" : "") << c.im << "i";
    return out;
}

istream& operator>> (istream& in, complex& c) {
    cout << "Enter complex: " << endl;
    cout << "re = "; in >> c.re;
    cout << "im = "; in >> c.im;
    return in;
}

template <class T>
void solve(T a, int rows, int cols) {
    int* B = new int[rows];
    for (int i = 0; i < rows; i++) {
        bool flag = false;
        for (int j = 0; j < cols; j++) {
            flag = flag || a[i][j] == 0;
        }
        B[i] = flag;
    }
    for (int i = 0; i < rows; i++) {
        cout << "B[" << i << "] = " << B[i] << endl;
    }
}


int main()
{
    int A[mmax][nmax];
    double B[mmax][nmax];
    complex C[mmax][nmax];

    int rows, cols;

    cout << "m = "; cin >> rows;
    cout << "n = "; cin >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "A[" << i << "][" << j << "] = "; cin >> A[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "B[" << i << "][" << j << "] = "; cin >> B[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "C[" << i << "][" << j << "] = "; cin >> C[i][j];
        }
    }
    
    cout << endl << "Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Matrix B:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Matrix C:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    solve(A, rows, cols);
    cout << endl;
    solve(B, rows, cols);
    cout << endl;
    solve(C, rows, cols);
}

/*
m = 2
n = 2
A[0][0] = 0
A[0][1] = 1
A[1][0] = 0
A[1][1] = 0
B[0][0] = 0.0
B[0][1] = 0.0
B[1][0] = 5.5
B[1][1] = 3.2
C[0][0] = Enter complex:
re = 1
im = 2
C[0][1] = Enter complex:
re = 3
im = 4
C[1][0] = Enter complex:
re = 0
im = 0
C[1][1] = Enter complex:
re = 0
im = 0

Matrix A:
0 1
0 0

Matrix B:
0 0
5.5 3.2

Matrix C:
1+2i 3+4i
0+0i 0+0i
B[0] = 1
B[1] = 1

B[0] = 1
B[1] = 0

B[0] = 0
B[1] = 1
*/