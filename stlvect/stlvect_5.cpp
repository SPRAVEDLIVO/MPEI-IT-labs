#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> x;
	cout << "n = "; cin >> n;
	x.reserve(n);
	for (int i = 0; i < n; i++) {
		int temp;
		cout << "x[" << i << "] = ";
		cin >> temp;
		x.push_back(temp);
	}
	int sum = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] > 0) {
			sum += i;
		}
	}
	if (sum % 2 == 0) {
		for (int i = 0; i < x.size(); i+=2) {
			if (i + 1 > x.size() - 1) break;
			swap(x[i], x[i + 1]);
		}
		cout << endl;
		int index = 0;
		for (vector<int>::iterator it = x.begin(); it != x.end(); it++) {
			cout << "X[" << index << "] = " << *it << endl;
			index++;
		}
		return 0;
	}
	cout << "Condition isn't satisfied." << endl;
	return 0;
}

/*
* n = 5
x[0] = 50
x[1] = 20
x[2] = -1
x[3] = 1
x[4] = 0

X[0] = 20
X[1] = 50
X[2] = 1
X[3] = -1
X[4] = 0
*/