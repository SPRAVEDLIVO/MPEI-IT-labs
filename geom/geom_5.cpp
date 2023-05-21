#include <iostream>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14
#endif // !M_PI

using namespace std;

class geom {
	protected:
		int x;
	public:
		geom(int x) {
			this->x = x;
		}
		virtual double volume() = 0;
};

class sphere : public geom {
public:
	sphere(int x) : geom(x) {}
	double volume() {
		return (4.0 / 3.0) * M_PI * pow(x, 3);
	}
};

class prism: public geom {
private:
	int h;
public:
	prism(int x, int y) : geom(x), h(y) {}
	double volume() {
		return (sqrt(3.0) / 4.0) * pow(x, 2) * h;
	}
};

int main() {
	int r;
	cout << "enter sphere radius: "; cin >> r;

	int a, h;
	cout << "enter prism base: "; cin >> a;
	cout << "enter prism height: "; cin >> h;
	sphere sp(r);
	prism pr(a, h);

	geom* x[2] = {&sp, &pr};

	double total_volume = 0;
	for (int i = 0; i < 2; i++) {
		total_volume += x[i]->volume();
	}
	cout << "total_volume = " << total_volume << endl;

	return 0;
}

/*
enter sphere radius: 1
enter prism base: 2
enter prism height: 3
total_volume = 9.38282
*/