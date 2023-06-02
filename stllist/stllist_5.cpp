#include <iostream>
#include <string>
#include <list>
using namespace std;

struct film {
	string title;
	string director;
	int price;
};

bool comparator(film first, film second) {
	return first.price < second.price;
}

int main() {
	int n; cout << "n = "; cin >> n;
	list<film> films;
	for (int i = 0; i < n; i++) {
		film temp;
		cout << "Film " << i << " title: "; cin >> temp.title;
		cout << "Film " << i << " director: "; cin >> temp.director;
		cout << "Film " << i << " price: "; cin >> temp.price;
		films.push_back(temp);
		cout << endl;
	}
	films.sort(comparator);
	for (list<film>::iterator it = films.begin(); it != films.end(); it++) {
		cout << "Film(title=" << it->title << ", director=" << it->director << ", price = " << it->price << ")" << endl;

	}
}

/*Film(title=b, director=bb, price = 650)
Film(title=a, director=aa, price = 800)
Film(title=c, director=cc, price = 1000)
*/