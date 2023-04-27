#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

class Matrix {
    private:
        int** base, size_x, size_y;
        string name;
    public:
        Matrix(int a, int b, string c) {
            size_x = a;
            size_y = b;
            base = new int* [size_x];
            for (int i = 0; i < size_x; i++) {
                base[i] = new int[size_y];
            }
            name = c;
        }
        void input() {
            for (int i = 0; i < size_x; i++) {
                for (int j = 0; j < size_y; j++) {
                    cout << name << "[" << i << "][" << j << "] = "; cin >> base[i][j];
                }
            }
        }
        void print() {
            for (int i = 0; i < size_x; i++) {
                for (int j = 0; j < size_y; j++) {
                    cout << base[i][j] << " ";
                }
                cout << endl;
            }
        }
        friend void solve(Matrix&);
};

bool is_super(int* elems, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (value <= elems[i]) return false;
    }
    return true;
}

void solve(Matrix& m) {
    int* elems = new int[m.size_x * m.size_x];
    int real_size = 0;
    for (int i = 0; i < m.size_x; i++) {
        for (int j = 0; j < m.size_y; j++) {
            if (j < i) {
                elems[real_size++] = m.base[i][j];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < m.size_x; i++) {
        for (int j = 0; j < m.size_y; j++) {
            if (j >= i && is_super(elems, real_size, m.base[i][j])) {
                sum += m.base[i][j];
            }
        }
    }
    cout << "sum = " << sum << endl;
}

void main() {
    int N; cout << "N = "; cin >> N;
    Matrix X = Matrix(N, N, "X");
    X.input();
    cout << endl;
    X.print();
    solve(X);
}

/*
N = 3
X[0][0] = 1
X[0][1] = 2
X[0][2] = 4
X[1][0] = 10
X[1][1] = 40
X[1][2] = 31
X[2][0] = 15
X[2][1] = 30
X[2][2] = -1

1 2 4
10 40 31
15 30 -1
sum = 71
*/
