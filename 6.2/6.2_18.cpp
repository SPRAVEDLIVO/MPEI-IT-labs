#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string s, out = ""; getline(fin, s);
	string words[100];
	int st = 0, len = 0, word = 0; bool flag = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (flag) {
				words[word] = s.substr(st, len);
				cout << s.substr(st, len) << endl;
				word++;
				st = -1;
				flag = false;
			}
		}
		else {
			flag = true;
			if (st == -1) {
				st = i; len = 1;
			}
			else
				len++;
		}
	}
	if (st != -1) {
		words[word] = s.substr(st, len);
		word++;
	}
	for (int i = 0; i < word; i++)
		out += words[i] + ' ';
	fout << out;
	return 0;
}