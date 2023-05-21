#include <iostream>

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
    bool operator<(complex& other) {
        return module() < other.module();
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
    int minIdx1 = 0, minIdx2 = 0;
    for (int i = 0; i < cols; i++) {
        if (a[1][i] < a[1][minIdx1]) {
            minIdx1 = i;
        }
        if (a[2][i] < a[2][minIdx2]) {
            minIdx2 = i;
        }
    }
    swap(a[1][minIdx1], a[2][minIdx2]);

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
}

/*
m = 3
n = 2
A[0][0] = 10
A[0][1] = 5
A[1][0] = 1
A[1][1] = 20
A[2][0] = 8
A[2][1] = 9
B[0][0] = 1.5
B[0][1] = 2.5
B[1][0] = 3.5
B[1][1] = 4
B[2][0] = 5
B[2][1] = 15
C[0][0] = 1 2
C[0][1] = 1 2
C[1][0] = 3 4
C[1][1] = 8 0
C[2][0] = 8 0
C[2][1] = 1 -1
Matrix A:
10 5
1 20
8 9

Matrix B:
1.5 2.5
3.5 4
5 15

Matrix C:
1+2i 1+2i
3+4i 8+0i
8+0i 1-1i


Matrix A:
10 5
8 20
1 9

Matrix B:
1.5 2.5
5 4
3.5 15

Matrix C:
1+2i 1+2i
1-1i 8+0i
8+0i 3+4i
*/