#include <iostream>
#include <string>
using namespace std;

class vect {
	private:
		int size;
		int* base;
	public:
		vect(int n) {
			size = n;
			base = new int[n];
		}
		~vect() {
			delete[] base;
			size = 0;
		}
		int get_size() { return size; }
		int& elem(int idx) { return base[idx]; }
		/* решение в методе */
		void solve() {
			int sum = 0;
			for (int i = 0; i < size; i++) {
				if (base[i] > 0) {
					sum += i;
				}
			}
			if (sum % 2 != 0) {
				cout << "Condition wasn't satisfied." << endl;
				return;
			}
			for (int i = 0; i < size; i += 2) {
				if (i != size - 1) {
					swap(base[i], base[i + 1]);
				}
			}
			print();
		}
		void print() {
			for (int i = 0; i < size; i++) {
				cout << "X[" << i << "] = " << base[i] << endl;
			}
		}
};

void main() {
	int N; cout << "N = "; cin >> N;
	vect X = vect(N);
	for (int i = 0; i < N; i++) {
		cout << "X[" << i << "] = "; cin >> X.elem(i);
	}
	cout << endl;
	/* решение в методе */
	X.solve();
	/* решение в main */
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (X.elem(i) > 0) {
			sum += i;
		}
	}
	if (sum % 2 != 0) {
		cout << "Condition wasn't satisfied." << endl;
		return;
	}
	for (int i = 0; i < N; i += 2) {
		if (i != N - 1) {
			swap(X.elem(i), X.elem(i + 1));
		}
	}
	X.print();

}

/*
N = 6
X[0] = 15
X[1] = -10
X[2] = 1
X[3] = 5
X[4] = 0
X[5] = 80

X[0] = -10
X[1] = 15
X[2] = 5
X[3] = 1
X[4] = 80
X[5] = 0
*/
