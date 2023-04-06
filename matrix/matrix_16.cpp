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
        int elem(int x, int y) { return base[x][y]; }
        void assign(int x, int y, int value) { base[x][y] = value; }
        
        void solve() {
            int current, sum{}, count{};
            for (int i = 0; i < size_x; i++) {
                for (int j = 0; j < size_y; j++) {
                    current = base[i][j];
                    if (j < i && current < 0) {
                        sum += current;
                        count++;
                    }
                }
            }
            cout << "sr = " << sum / count << endl;
            int last = size_x - 1;
            for (int i = 0; i < size_x; i++) {
                swap_values(i, 0, i, last);
            }
            for (int j = 0; j < size_y-1; j++) {
                for (int k = 0; k < size_y - j - 1; j++) {
                    if (base[k][0] < base[k + 1][0]) {
                        swap_values(k, 0, k + 1, 0);
                    }
                }
            }
            print();
        }
};


int main() {
    /* первый вариант решения 
    int M; cout << "M = "; cin >> M;
    Matrix b = Matrix(M, M, "B");
    b.input();
    b.print();
    cout << endl;
    b.solve();
    */
    /* второй вариант решения */
    int M; cout << "M = "; cin >> M;
    Matrix b = Matrix(M, M, "B");
    b.input();
    b.print();
    cout << endl;
    int current, sum{}, count{};
    for (int i = 0; i < b.get_size_x(); i++) {
        for (int j = 0; j < b.get_size_y(); j++) {
            current = b.elem(i, j);
            if (j < i && current < 0) {
                sum += current;
                count++;
            }
        }
    }
    cout << "sr = " << sum / count << endl;
    int last = b.get_size_x() - 1;
    for (int i = 0; i < b.get_size_x(); i++) {
        b.swap_values(i, 0, i, last);
    }
    for (int j = 0; j < b.get_size_y() - 1; j++) {
        for (int k = 0; k < b.get_size_y() - j - 1; j++) {
            if (b.elem(k, 0) < b.elem(k + 1, 0)) {
                b.swap_values(k, 0, k + 1, 0);
            }
        }
    }
    b.print();
}

/*
M = 3
B[0][0] = 100
B[0][1] = 0
B[0][2] = 6
B[1][0] = -5
B[1][1] = 2
B[1][2] = 10
B[2][0] = -1
B[2][1] = -3
B[2][2] = 2
100 0 6
-5 2 10
-1 -3 2

sr = -3
10 0 100
6 2 -5
2 -3 -1
*/