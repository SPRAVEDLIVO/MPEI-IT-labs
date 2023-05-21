#include <iostream>
#include <list>
#include <string>
using namespace std;

/* protected-protected */
/*class vect {
protected:
	int size;
	int* base;
public:
	vect(int size) {
		this->size = size;
		base = new int[size];
	}
};

class vect1 : protected vect {
public:
	vect1(int size) : vect(size) {}
	void print(string name) {
		for (int i = 0; i < size; i++) {
			cout << name << "[" << i << "] = " << base[i] << endl;
		}
	}
	void input(string name) {
		for (int i = 0; i < size; i++) {
			cout << name << "[" << i << "] = "; cin >> base[i];
		}
	}
	void solve(vect1& y, int r) {
		int px, py;
		int count = 0;
		double sum = 0.0;
		for (int i = 0; i < size; i++) {
			px = base[i];
			py = y.base[i];
			if ((px * px + py * py) < r * r) {
				count++;
				sum += sqrt(px * px + py * py);
			}
		}
		cout << "count = " << count << endl;
		cout << "sr = " << sum / count << endl;
	}
}; */


/*private-protected*/
class vect {
private:
	int size;
	int* base;
public:
	vect(int size) {
		this->size = size;
		base = new int[size];
	}
	int get_size() {
		return size;
	}
	int& elem(int i) {
		return base[i];
	}
};

class vect1 : protected vect {
public:
	vect1(int size) : vect(size) {}
	void print(string name) {
		for (int i = 0; i < get_size(); i++) {
			cout << name << "[" << i << "] = " << elem(i) << endl;
		}
	}
	void input(string name) {
		for (int i = 0; i < get_size(); i++) {
			cout << name << "[" << i << "] = "; cin >> elem(i);
		}
	}
	void solve(vect1& y, int r) {
		int px, py;
		int count = 0;
		double sum = 0.0;
		for (int i = 0; i < get_size(); i++) {
			px = elem(i);
			py = y.elem(i);
			if ((px * px + py * py) < r * r) {
				count++;
				sum += sqrt(px * px + py * py);
			}
		}
		cout << "count = " << count << endl;
		cout << "sr = " << sum / count << endl;
	}
};

int main() {
	int size; int R;
	cout << "N = "; cin >> size;
	cout << "R = "; cin >> R;
	vect1 x(size);
	vect1 y(size);
	x.input("X");
	y.input("Y");
	x.solve(y, R);
}
/*
N = 2
R = 5
X[0] = 1
X[1] = 10
Y[0] = 1
Y[1] = 0
count = 1
sr = 1.41421
*/