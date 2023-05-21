#include <iostream>
#include <list>
#include <string>
using namespace std;

struct participant {
	string surname;
	int fencing_place;
	int swimming_place;
	int running_place;
	int sum_place(int size) {
		return (size - fencing_place) + (size - swimming_place) + (size - running_place);
	}
};

int main() {
	list<participant> a;
	list<participant>::iterator it;
	participant x;

	int size;
	cout << "size = "; cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Surname of participant " << i << ": "; cin >> x.surname;
		cout << "Fencing place of participant " << i << ": "; cin >> x.fencing_place;
		cout << "Swimming place of participant " << i << ": "; cin >> x.swimming_place;
		cout << "Running place of participant " << i << ": "; cin >> x.running_place;
		a.push_back(x);
	}
	int max_place = 0, sum_place;
	participant max;

	for (it = a.begin(); it != a.end(); it++) {
		sum_place = (*it).sum_place(size);
		if (sum_place > max_place) {
			max_place = sum_place;
			max = (*it);
		}
	}

	cout << max.surname << endl;
}

/*
size = 3
Surname of participant 0: abc
Fencing place of participant 0: 1
Swimming place of participant 0: 1
Running place of participant 0: 1
Surname of participant 1: abcd
Fencing place of participant 1: 2
Swimming place of participant 1: 2
Running place of participant 1: 2
Surname of participant 2: abcde
Fencing place of participant 2: 3
Swimming place of participant 2: 3
Running place of participant 2: 3
abc
*/