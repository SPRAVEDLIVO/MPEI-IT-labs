#include <iostream>
#include <string>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

struct range {
    int start;
    int end;
    bool exceeds(int elem) {
        return (elem < start) || (elem > end);
    }
};

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

    void input(string name, range rng) {
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j++) {
                int temp;
                cout << name << "[" << i << "][" << j << "] = "; cin >> temp;
                if (rng.exceeds(temp)) {
                    throw name + string(": can't add element ") + to_string(temp) + " because it exceeds the range.";
                }
                elem(i, j) = temp;
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
    
    range rng;
    cout << "range_start = "; cin >> rng.start;
    cout << "range_end = "; cin >> rng.end;



    cout << "a_rows = "; cin >> a_rows;
    cout << "a_cols = "; cin >> a_cols;

    matr a(a_rows, a_cols, "A");
    try {
        a.input("A", rng);
    }
    catch (string message) {
        cout << message << endl;
        return 0;
    }
    cout << endl;
    a.print();
    cout << endl;

    cout << "Trying to access element: ";
    int i, j;
    cin >> i >> j;
    try {
        int result_a = a.elem(i, j);
        cout << "A[" << i << "][" << j << "] = " << result_a << endl;
    }
    catch (string message) {
        cout << message << endl;
    }

    

    return 0;
}

/*
Breaks range check:
range_start = 1
range_end = 5
a_rows = 1
a_cols = 1
A[0][0] = 6
A: can't add element 6 because it exceeds the range.

Breaks index check: 
range_start = 1
range_end = 5
a_rows = 1
a_cols = 2
A[0][0] = 1
A[0][1] = 2

1 2

Trying to access element: 0 2
A: Either column index or row index is invalid.

All good:
range_start = 1
range_end = 5
a_rows = 2
a_cols = 2
A[0][0] = 1
A[0][1] = 2
A[1][0] = 3
A[1][1] = 4

1 2
3 4

Trying to access element: 0 0
A[0][0] = 1
*/