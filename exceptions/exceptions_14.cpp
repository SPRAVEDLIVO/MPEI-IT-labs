#include <iostream>
#include <string>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

class matr {
private:
    int size_x, size_y;
    int** base;
    string name;
public:
    matr(int size_x, int size_y, string name) {
        this->size_x = size_x;
        this->size_y = size_y;
        this->name = name;
        base = new int* [size_x];
        for (int i = 0; i < size_y; i++) {
            base[i] = new int[size_y];
        }
    }
    int& elem(int a, int b) {
        if (a > size_x - 1 || a < 0 || b > size_y - 1 || b < 0) {
            throw name + string(": Either column index or row index is invalid.");
        }
        return base[a][b];
    }

    matr variable_operator(matr& right, int (*adder)(int, int)) {
        // assuming that this->size_x == right.size_x && this->size_y == right.size_y
        matr allocated(size_x, size_y, "result");
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j++) {
                if (elem(i, j) < 0 || right.elem(i, j) < 0) {
                    throw string("One of the matrices contains negative elements.");
                }
                allocated.base[i][j] = adder(base[i][j], right.base[i][j]);
            }
        }
        return allocated;
    }

    matr operator+(matr& right) {
        return variable_operator(right, add);
    }
    matr operator-(matr& right) {
        return variable_operator(right, substract);
    }
    void input(string name) {
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j++) {
                cout << name << "[" << i << "][" << j << "] = "; cin >> elem(i, j);
            }
        }
    }
    void print() {
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j++) {
                cout << elem(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int a_rows, a_cols;
    int b_rows, b_cols;
    cout << "a_rows = "; cin >> a_rows;
    cout << "a_cols = "; cin >> a_cols;
    cout << "b_rows = "; cin >> b_rows;
    cout << "b_cols = "; cin >> b_cols;

    matr a(a_rows, a_cols, "A");
    matr b(b_rows, b_cols, "B");
    a.input("A");
    b.input("B");
    cout << endl;
    a.print();
    cout << endl;
    b.print();
    cout << endl;

    cout << "Trying to access element: ";
    int i, j;
    cin >> i >> j;
    try {
        int result_a = a.elem(i, j), result_b = b.elem(i, j);
        cout << "A[" << i << "][" << j << "] = " << result_a << endl;
        cout << "B[" << i << "][" << j << "] = " << result_b << endl;
    }
    catch (string message) {
        cout << message << endl;
    }

    try {
        matr add = a + b;
        cout << "add:" << endl;
        add.print();
        matr sub = a - b;
        cout << "sub:" << endl;
        sub.print();
    }
    catch (string message) {
        cout << message << endl;
    }

    return 0;
}