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
	listelem* t, * m, * a, * b;

	for (bool go = true; go; ) {
		go = false;
		a = t = l.h;
		b = l.h->next;

		while (b != NULL) {
			if (a->price > b->price) {
				if (t == a)
					l.h = b;
				else
					t->next = b;

				a->next = b->next;
				b->next = a;

				m = a, a = b, b = m;
				go = true;
			}
			t = a;
			a = a->next;
			b = b->next;
		}
	}

	listelem* temp = l.h;
	while (temp != nullptr) {
		cout << "Film(title=" << temp->title << ", price=" << temp->price << ", director=" << temp->director << ")" << endl;
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
N = 2
Enter title for film 1: a
Enter price for film 1: 1000
Enter director for film 1: b
Enter title for film 2: c
Enter price for film 2: 100
Enter director for film 2: d
Film(title=c, price=100, director=d)
Film(title=a, price=1000, director=b)
*/