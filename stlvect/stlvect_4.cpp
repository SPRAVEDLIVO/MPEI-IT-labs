#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	vector<int> X, C;
	int n; cout << "n = "; cin >> n;
	X.reserve(n);
	C.reserve(n);
	for (int i = 0; i < n; i++) {
		int temp;
		cout << "X[" << i << "] = "; cin >> temp; X.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cout << "C[" << i << "] = "; cin >> temp; C.push_back(temp);
	}
	
	bool flag = true;
	for (int i = 0; i < X.size(); i++) {
		if (X[i] <= C[i]) { flag = false; break; }
	}
	if (flag == false) {
		cout << "-1" << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < X.size(); i++) {
		sum += pow(X[i], 2) - pow(C[i], 2);
	}
	cout << sum << endl;
	return 0;
}

/*
n = 2
X[0] = 3
X[1] = 4
C[0] = 1
C[1] = 2
20
*/