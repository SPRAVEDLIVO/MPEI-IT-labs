#include <iostream>
#include <string>
using namespace std;

struct listelem {
	string title;
	int price;
	string director;
	listelem* next = 0;
};

class list {
	private:
		listelem* h;
		int size;
	public:
		list() {
			size = 0;
			h = 0;
		}

		void prepend(listelem* item) {
			listelem* temp = h;
			item->next = temp;
			h = item;
			size++;
		}

		~list() {
			release();
		}
		void release() {
			while (h != nullptr) {
				del();
			}
		}
		void del() {
			listelem* temp = h;
			h = temp->next;
			delete temp;
		}
		friend void solve(list& l);
};

void solve(list& l) {
	listelem* temp = l.h;
	int max_price = temp->price;
	int min_price = temp->price;
	while (temp != nullptr) {
		if (temp->price < min_price) {
			min_price = temp->price;
		}
		else if (temp->price > max_price) {
			max_price = temp->price;
		}
		temp = temp->next;
	}
	double sr = (max_price + min_price) / 2.0;
	temp = l.h;
	while (temp != nullptr) {
		if (temp->price > sr) {
			cout << "Film(title=" << temp->title << ", price=" << temp->price << ", director=" << temp->director << ")" << endl;
		}
		temp = temp->next;
	}
}

void main() {
	list a = list();
	int n; cout << "N = "; cin >> n;
	for (int i = 0; i < n; i++) {
		listelem* temp = new listelem;
		cout << "Enter title for film " << i + 1 << ": "; cin >> temp->title;
		cout << "Enter price for film " << i + 1 << ": "; cin >> temp->price;
		cout << "Enter director for film " << i + 1 << ": "; cin >> temp->director;
		a.prepend(temp);
	}
	solve(a);
}

/*
N = 3
Enter title for film 1: Moonshine
Enter price for film 1: 200
Enter director for film 1: Kubrik
Enter title for film 2: Terminator
Enter price for film 2: 500
Enter director for film 2: Cameron
Enter title for film 3: Matrix
Enter price for film 3: 360
Enter director for film 3: Vachovski
Film(title=Matrix, price=360, director=Vachovski)
Film(title=Terminator, price=500, director=Cameron)
*/