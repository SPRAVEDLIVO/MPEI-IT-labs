#include <iostream>
#include <vector>
using namespace std;

int main() {
	int size;
	cout << "size = "; cin >> size;

	vector<int> a;
    vector<int>::iterator it;
	int i, j;
	a.reserve(size);

	int x;
	for (int i = 0; i < size; i++) {
		cout << "A[" << i << "] = ";
		cin >> x;
		a.push_back(x);
	}
	int min_idx;
    for (i = 0; i < a.size() - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }

    cout << endl;
    for (it = a.begin(); it != a.end(); it++) {
        cout << "A[" << i << "] = " << (*it) << endl;
    }

}

/*
size = 4
A[0] = 5
A[1] = 3
A[2] = 9
A[3] = 1

A[3] = 1
A[3] = 3
A[3] = 5
A[3] = 9
*/