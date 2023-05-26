#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class complex {
	double re, im;
public:
	complex(double a = 0, double b = 0) {
		re = a;
		im = b;
	}
	friend ostream& operator<<(ostream& out, complex& c);
	friend istream& operator >> (istream& in, complex& a);
	bool operator>(double cmp) {
		return im > cmp;
	}
	double module() {
		return sqrt(pow(re, 2) + pow(im, 2));
	}
	double operator + (double sum) {
		return module() + sum;
	}
};

ostream& operator << (ostream& out, complex& a) {
	if (a.im > 0) {
		cout << a.re << "+" << a.im << "i ";
	}
	else if (a.im < 0) {
		cout << a.re << a.im << "i ";
	}
	return out;
}

istream& operator >> (istream& in, complex& a) {
	in >> a.re >> a.im;
	return (in);
}

class vect {
	complex* base;
	int size;
public:
	vect(int n) {
		size = n;
		base = new complex[size];
	}
	friend ostream& operator << (ostream& out, vect a);
	friend istream& operator >> (istream& in, vect& a);
	complex& operator[](int i) {
		return base[i];
	}
	void solve() {
		double sr = 0;
		complex current;
		int count = 0;
		double sum = 0;
		for (int i = 0; i < size; i++) {
			current = base[i];
			if (current > 0) {
				sum = current + sum;
				count++;
				cout << "mas[" << i << "] = " << base[i] << endl;
			}
		}
		cout << "sr = " << sum / count << endl;
	}
};

istream& operator >> (istream& in, vect& a) {
	for (int i = 0; i < a.size; i++) {
		cout << "mas[" << i << "] = "; cin >> a[i];
	}
	return in;
}

ostream& operator << (ostream& out, vect a) {
	for (int i = 0; i < a.size; i++) {
		out << "mas[" << i << "] = " << a.base[i] << endl;
	}
	return out;
}

int main() {
	int N;
	cout << "N = "; cin >> N;

	vect mas = vect(N);

	cin >> mas;
	cout << endl;

	mas.solve();
	return 0;
}

/*
N = 4
mas[0] = 1 1
mas[1] = 1 -1
mas[2] = -1 8
mas[3] = 2 4

mas[0] = 1+1i
mas[2] = -1+8i
mas[3] = 2+4i
sr = 4.64954
*/