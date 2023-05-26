#include <iostream>
#include <string>
#include <math.h>
#define last_place 3
using namespace std;

struct listelem {
    string surname{};

    int shooting_place = 0;
    int fencing_place = 0;
    int cross_place = 0;

    listelem* next = 0;
};

class list {

private:
    listelem* h;
    int size;
public:
    list() {
        h = 0;
        size = 0;
    }
    ~list() {
        release();
    }

    void release() {
        while (h != 0) {
            del();
        }
    }

    void del() {
        listelem* temp = h;
        h = h->next;
        delete temp;
    }

    void prepend(listelem* data) {
        data->next = h;
        h = data;
    }
    friend void solve(list&);
};

void solve(list& a) {
    listelem* temp = a.h;
    int highest_sum = -1, sum;
    listelem* highest = a.h;
    while (temp != nullptr) {
        sum = (last_place - temp->cross_place) + (last_place - temp->fencing_place) + (last_place - temp->shooting_place);

        if (sum > highest_sum) {
            highest_sum = sum;
            highest = temp;
        }
        temp = temp->next;
    }

    cout << highest->surname << endl;
}


int main() {
    list info;
    int N;
    cout << "N = "; cin >> N;


    for (int i = 0; i < N; i++) {
        cout << endl;
        listelem* temp = new listelem;
        cout << "surname: "; cin >> temp->surname;
        cout << "shooting place: "; cin >> temp->shooting_place;
        cout << "fencing place: "; cin >> temp->fencing_place;
        cout << "cross place: "; cin >> temp->cross_place;


        info.prepend(temp);
    }

    solve(info);

    return 0;
}

/*
N = 3

surname: a
shooting place: 1
fencing place: 1
cross place: 1

surname: b
shooting place: 2
fencing place: 2
cross place: 2

surname: c
shooting place: 3
fencing place: 3
cross place: 3
a*/