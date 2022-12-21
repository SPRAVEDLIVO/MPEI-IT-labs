#include <iostream>
#include <fstream>
#include <string>
using namespace std;


pair<string*, int> split(string text, char delim) {
	string* arr = new string[100];
	string curr = "";
	int idx = -1;
	for (char s : text) {
		if (s == delim) {
			arr[++idx] = curr;
			curr = "";
		}
		else {
			curr += s;
		}
	}
	if (curr != "") {
		arr[++idx] = curr;
	}
	return make_pair(arr, idx+1);
}

bool arrayHas(int* arr, int elem, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem) return true;
	}
	return false;
}

int main() {
	string text;
	getline(cin, text);
	pair<string*, int> p = split(text, ' ');
	int* notInclude = new int[p.second];
	int idx = -1;

	for (int i = 0; i < p.second; i++) {
		for (int j = 0; j < p.second; j++) {
			if (j > i && p.first[i] == p.first[j]) {
				notInclude[++idx] = j;
			}
		}
	}
	for (int i = 0; i < p.second; i++) {

		if (!arrayHas(notInclude, i, idx + 1)) {
			cout << p.first[i] << " ";
		}
	}
	cout << endl;
	system("pause");
}

/*
123 1234 123 1234 abc
123 1234 abc
*/