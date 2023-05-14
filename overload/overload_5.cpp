#include <iostream>
#include <string>
using namespace std;

class complex {
	double re, im;
	public:
		complex(int a = 0, int b = 0) {
			re = a;
			im = b;
		}
		friend ostream& operator<<(ostream& out, complex& c);
		friend istream& operator >> (istream& in, complex& a);
		bool operator<(complex& other) {
			return re < other.re;
		}
};

ostream& operator << (ostream& out, complex& a) {
	if (a.im > 0) {
		cout << a.re << "+" << a.im << "i ";
	}
	else if (a.im < 0) {
		cout << a.re << a.im << "i ";
	}
	return (out);
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
			complex min = base[0];
			complex current;
			int idx = 0;
			for (int i = 1; i < size; i++) {
				current = base[i];
				if (current < min) {
					min = current;
					idx = i;
				}
			}
			cout << endl << idx << endl;
			cout << *this;
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

void main() {
	int N;
	cout << "N = "; cin >> N;

	vect mas = vect(N);

	cin >> mas;

	mas.solve();
	
}

/*
N = 3
mas[0] = 10 2
mas[1] = 9.5 100
mas[2] = 11 58

1
mas[0] = 10+2i
mas[1] = 9.5+100i
mas[2] = 11+58i
*/