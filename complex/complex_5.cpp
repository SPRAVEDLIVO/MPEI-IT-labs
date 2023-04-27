#include <iostream>
#include <string>
using namespace std;

class Complex {
	private:
		double re, im;
	public:
		Complex(int a = 0, int b = 0) {
			set(a, b);
		}
		void set(int a, int b) {
			re = a;
			im = b;
		}
		double get_re() {
			return re;
		}
		double get_im() {
			return im;
		}
		void print() {
			cout << "Compl(" << re << (im >= 0 ? "+" : "") << im << "i)" << endl;
		}
		/* решение в методе */
		void solve(Complex* mas, int size) {
			int min_idx = 0;
			int min_re = mas[0].re;
			Complex current;
			for (int i = 1; i < size; i++) {
				current = mas[i];
				if (current.re < min_re) {
					min_re = current.re;
					min_idx = i;
				}
			}
			cout << "min_idx = " << min_idx << endl;
			for (int i = 0; i < size; i++) {
				mas[i].print();
			}
		}
};

void main() {
	int N; cout << "N = "; cin >> N;
	Complex* mas = new Complex[N];
	for (int i = 0; i < N; i++) {
		double temp_re, temp_im;
		cout << "mas[0][re] = "; cin >> temp_re;
		cout << "mas[0][im] = "; cin >> temp_im;
		mas[i].set(temp_re, temp_im);
	}
	/* решение в методе */
	mas[0].solve(mas, N);

	/* решение в main */
	int min_idx = 0;
	int min_re = mas[0].get_re();
	Complex current;
	for (int i = 1; i < N; i++) {
		current = mas[i];
		if (current.get_re() < min_re) {
			min_re = current.get_re();
			min_idx = i;
		}
	}
	cout << "min_idx = " << min_idx << endl;
	for (int i = 0; i < N; i++) {
		mas[i].print();
	}

}

/*
N = 3
mas[0][re] =  1
mas[0][im] =  2
mas[0][re] =  -10
mas[0][im] =  50
mas[0][re] =  100
mas[0][im] =  -5
min_idx = 1
Compl(1+2i)
Compl(-10+50i)
Compl(100-5i)
*/
