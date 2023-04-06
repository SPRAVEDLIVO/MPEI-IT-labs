#include <iostream>
#include <string>

using namespace std;

class matr {
	private:
		int size_x, size_y; int** base;
	public:
		matr(int a, int b) {
			size_x = a;
			size_y = b;
			base = new int*[size_x];
			for (int i = 0; i < size_x; i++) {
				base[i] = new int[size_y];
			}
		}

		void input(string name) {
			for (int i = 0; i < size_x; i++) {
				for (int j = 0; j < size_y; j++) {
					cout << name << "[" << i << "][" << j << "] = "; cin >> base[i][j];
				}
			}
		}
		void output() {
			for (int i = 0; i < size_x; i++) {
				for (int j = 0; j < size_y; j++) {
					cout << base[i][j] << " ";
				}
				cout << endl;
			}
		}
		friend void solve(matr&);
};

bool check(int value, int* lower, int size) {
	for (int i = 0; i < size; i++) {
		if (value <= lower[i]) {
			return false;
		}
	}
	return true;
}

void solve(matr& a) {
	int* lower = new int[a.size_x * a.size_y];
	int real_size = 0;

	for (int i = 0; i < a.size_x; i++) {
		for (int j = 0; j < a.size_y; j++) {
			if (j < i) {
				lower[real_size++] = a.base[i][j];
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < a.size_x; i++) {
		for (int j = 0; j < a.size_y; j++) {
			if (j >= i && check(a.base[i][j], lower, real_size)) {
				sum += a.base[i][j];
			}
		}
	}
	cout << "sum = " << sum << endl;

}

int main()
{

	matr x = matr(3, 3);
	x.input("X");
	x.output();
	
	solve(x);

	
}

/*
X[0][0] = 6
X[0][1] = 3
X[0][2] = 7
X[1][0] = 5
X[1][1] = 11
X[1][2] = 20
X[2][0] = 6
X[2][1] = 10
X[2][2] = 8
6 3 7
5 11 20
6 10 8
sum = 31
*/