#include <iostream>
#include <list>
#include <string>
using namespace std;

struct film {
	string title;
	int price;
	string director;
};

int main() {
	list<film> films;
	int size;
	cout << "size = "; cin >> size;
	for (int i = 0; i < size; i++) {
		film x;
		cout << "Title of film " << i << ": "; cin >> x.title;
		cout << "Price of film " << i << ": "; cin >> x.price;
		cout << "Director of film " << i << ": "; cin >> x.director;
		films.push_back(x);
	}
	cout << endl << "Director: "; string director; cin >> director;
	for (list<film>::iterator it = films.begin(); it != films.end(); it++) {
		if (it->director == director) {
			cout << "Film(title=" << it->title << ", price=" << it->price << ")" << endl;
		}
	}
}