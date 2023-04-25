#include <iostream>
using namespace std;

class vect {
	private:
		int* base;
		int size;
	public:
		vect(int n) {
			size = n;
			base = new int[n];
		}
		virtual void input() {
			for (int i = 0; i < get_size(); i++) {
				cout << "X[" << i << "] = "; cin >> elem(i);
			}
		}
		void print() {
			for (int i = 0; i < get_size(); i++) {
				cout << "X[" << i << "] = " << elem(i) << endl;
			}
		}
		int& elem(int idx) { return base[idx]; }
		int get_size() { return size; }
};

class vect1 : protected vect {
	public:
		vect1(int a) : vect(a) {}
		void input() {
			vect::input();
		}
		void print() {
			vect::print();
		}
		
		void solve();
};

void vect1::solve() {
	int sum = 0, count = 0, current;
	for (int i = 0; i < get_size(); i += 2) {
		current = elem(i);
		if (current > 0 && current < 100) {
			sum += current;
			count++;
		}
	}
	cout << "sum = " << sum << endl;
	cout << "count = " << count << endl;
}

void main() {
	int n;
	cout << "N = "; cin >> n;
	vect1 x = vect1(n);
	x.input();
	cout << endl;
	x.solve();
}

/*
N = 7
X[0] = -1
X[1] = 15
X[2] = 99
X[3] = 33
X[4] = 101
X[5] = -8
X[6] = 1

sum = 100
count = 2
*/