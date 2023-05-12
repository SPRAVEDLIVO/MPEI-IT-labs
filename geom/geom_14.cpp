#include <iostream>
#include <string>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14
#endif // !M_PI

using namespace std;

class geom {
	protected:
		double x;
	public: 
		virtual double volume() = 0;
		geom(double a = 0) {
			  x = a;
		}
};

class parallelepiped : public geom {
private:
	double width;
	double length;
public:
	parallelepiped(double a, double b, double c) : geom(a), width(b), length(c) {};
	double volume() {
		return x * width * length;
	}
};

class cylinder : public geom {
private:
	double generatrix;
public:

	cylinder(double a, double b) : geom(a), generatrix(b) {}
	double volume() {
		return M_PI * pow(x, 2) * generatrix;
	}
};

void main() {
	int a, b, c;
	cout << "enter the height of parallelepiped: "; cin >> a;
	cout << "enter the width of parallelepiped: "; cin >> b;
	cout << "enter the length of parallelepiped: "; cin >> c;
	parallelepiped p = parallelepiped(a, b, c);

	int d, e;
	cout << "enter the radius of the base of cylinder: "; cin >> d;
	cout << "enter the width of cylinder: "; cin >> e;
	cylinder cyl = cylinder(d, e);

	geom* mas[2] = {&p, &cyl};
	
	double total_volume = 0;
	for (int i = 0; i < 2; i++) {
		total_volume += mas[i]->volume();
	}

	cout << "total_volume = " << total_volume << endl;


}
