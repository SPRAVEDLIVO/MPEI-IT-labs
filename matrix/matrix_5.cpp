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
        void swap_values(int x1, int y1, int x2, int y2) {
            swap(base[x1][y1], base[x2][y2]);
        }
        int get_size_x() { return size_x; }
        int get_size_y() { return size_y; }
        int& elem(int x, int y) { return base[x][y]; }
        /* решение в методе */
        void solve() {
            int max = base[1][0], sum = 0, current;
            for (int i = 0; i < size_x; i++) {
                for (int j = 0; j < size_y; j++) {
                    current = base[i][j];
                    if (j < i && current > max) {
                        max = current;
                    }
                    if (current < 0) {
                        sum += current;
                    }
                }
            }
            cout << "max = " << max << endl << "sum = " << sum << endl;
            for (int i = 0; i < size_x; i++) {
                swap_values(i, 0, i, size_x-1);
            }
            cout << endl;
            print();
        }
};

void main() {
    int M; cout << "M = "; cin >> M;
    Matrix b = Matrix(M, M, "B");
    b.input();
    cout << endl;
    b.print();
    cout << endl;
    /* решение в методе */
    //b.solve();
    /* решение в main */
    int max = b.elem(1, 0), sum = 0, current;
    for (int i = 0; i < b.get_size_x(); i++) {
        for (int j = 0; j < b.get_size_y(); j++) {
            current = b.elem(i, j);
            if (j < i && current > max) {
                max = current;
            }
            if (current < 0) {
                sum += current;
            }
        }
    }
    cout << "max = " << max << endl << "sum = " << sum << endl;
    for (int i = 0; i < b.get_size_x(); i++) {
        b.swap_values(i, 0, i, b.get_size_x() - 1);
    }
    cout << endl;
    b.print();
}

/*
M = 3
B[0][0] = -1
B[0][1] = 8
B[0][2] = -6
B[1][0] = 4
B[1][1] = -10
B[1][2] = -20
B[2][0] = -3
B[2][1] = 5
B[2][2] = 52

-1 8 -6
4 -10 -20
-3 5 52

max = 5
sum = -40

-6 8 -1
-20 -10 4
52 5 -3
*/
