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
    friend ostream& operator<< (ostream& out, complex& c);
    friend istream& operator>> (istream& in, complex& c);
    double module() {
        return sqrt(pow(re, 2) + pow(im, 2));
    }
    double operator+(double add) {
        return module() + add;
    }
};

ostream& operator<< (ostream& out, complex& c) {
    out << c.re << (c.im >= 0 ? "+" : "") << c.im << "i";
    return out;
}

istream& operator>> (istream& in, complex& c) {
    in >> c.re >> c.im;
    return in;
}

template <class T>
void solve(T a, int rows, int cols) {
    double max_mean = 0;
    int max_row = 0;
    for (int i = 0; i < rows; i++) {
        double mean = 0;
        for (int j = 0; j < cols; j++) {
            mean = a[i][j] + mean;
        }
        if (mean > max_mean) {
            max_mean = mean;
            max_row = i;
        }
    }
    cout << "max_row = " << max_row << endl;
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
A[0][0] = 4
A[0][1] = 4
A[1][0] = 3
A[1][1] = 1
B[0][0] = 5
B[0][1] = 1
B[1][0] = 7
B[1][1] = 1
C[0][0] = 1 2
C[0][1] = 0 -1
C[1][0] = 1 3
C[1][1] = 1 0

Matrix A:
4 4
3 1

Matrix B:
5 1
7 1

Matrix C:
1+2i 0-1i
1+3i 1+0i
max_row = 0

max_row = 1

max_row = 1
*/