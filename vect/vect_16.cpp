#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void swap_values(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

class vect {
private:
    int size; int* mas;
    string name;
public:
    vect(int a, string b) {
        size = a;
        mas = new int[a];
        name = b;
    }
    void input() {
        for (int i = 0; i < size; i++) {
            cout << name << "[" << i << "] = "; cin >> mas[i];
        }
    }

    void solve() {
        int i, j, min_idx;
        for (i = 0; i < size - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < size; j++)
            {
                if (mas[j] > mas[min_idx])
                    min_idx = j;
            }
            if (min_idx != i) swp(min_idx, i);
        }
        print();
    }
    void swp(int a, int b) {
        swap_values(&mas[a], &mas[b]);
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << name << "[" << i << "] = " << mas[i] << endl;
        }
    }
    int get_size() { return size; }
    int at_index(int i) {
        return mas[i];
    }
};


int main() {
    int N;
    cout << "N = "; cin >> N;
    /* первый вариант решения
    vect C = vect(N, "C");
    C.input();
    C.solve();*/
    // второй вариант решения
    vect C = vect(N, "C");
    C.input();
    int i, j, min_idx;
    for (i = 0; i < C.get_size() - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < C.get_size(); j++)
        {
            if (C.at_index(j) > C.at_index(min_idx))
                min_idx = j;
        }
        if (min_idx != i) C.swp(min_idx, i);
    }
    C.print();
    return 0;
}
/*
N = 5
C[0] = 99
C[1] = 5
C[2] = 4
C[3] = 80
C[4] = 6
C[0] = 99
C[1] = 80
C[2] = 6
C[3] = 5
C[4] = 4
*/