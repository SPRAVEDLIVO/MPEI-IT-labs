#include <iostream>
#include <string>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

class vect {
private:
    int size;
    int* base;
    string name;
public:
    vect(int size, string name) {
        this->size = size;
        this->name = name;
        base = new int[size];
    }
    int& elem(int a) {
        if (a > size - 1 || a < 0) {
            throw name + string(": Element index is invalid.");
        }
        return base[a];
    }

    vect variable_operator(vect& right, int (*adder)(int, int)) {
        if (right.size != size) {
            throw string("Vectors are of different size.");
        }
        vect allocated(size, "result");

        for (int i = 0; i < size; i++) {
            allocated.base[i] = adder(base[i], right.base[i]);
        }
        return allocated;
    }

    vect operator+(vect& right) {
        return variable_operator(right, add);
    }
    vect operator-(vect& right) {
        return variable_operator(right, substract);
    }
    void input(string name) {
        for (int i = 0; i < size; i++) {
            cout << name << "[" << i << "] = "; cin >> elem(i);
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << name << "[" << i << "] = " << elem(i) << endl;
        }
    }
    void set_name(string name) {
        this->name = name;
    }
};

int main() {
    int a_size, b_size;
    cout << "a_size = "; cin >> a_size;
    cout << "b_size = "; cin >> b_size;

    vect a(a_size, "A");
    vect b(b_size, "B");
    a.input("A");
    b.input("B");
    cout << endl;
    a.print();
    cout << endl;
    b.print();
    cout << endl;

    cout << "Trying to access element: ";
    int i;
    cin >> i;
    try {
        int result_a = a.elem(i), result_b = b.elem(i);
        cout << "A[" << i << "] = " << result_a << endl;
        cout << "B[" << i << "] = " << result_b << endl;
    }
    catch (string message) {
        cout << message << endl;
    }

    try {
        vect add = a + b;
        cout << endl;
        add.set_name("add");
        add.print();
        vect sub = a - b;
        sub.set_name("sub");
        cout << endl;
        sub.print();
    }
    catch (string message) {
        cout << message << endl;
    }

    return 0;
}

/*
a_size = 2
b_size = 2
A[0] = 1
A[1] = 2
B[0] = 3
B[1] = 4

A[0] = 1
A[1] = 2

B[0] = 3
B[1] = 4

Trying to access element: 0
A[0] = 1
B[0] = 3

add[0] = 4
add[1] = 6

sub[0] = -2
sub[1] = -2
*/