#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	getline(cin, text);
	int len = text.length();
	string concat = ", ";
	bool ignoring = false;
	string text2;
	for (int i = 0; i < len; i++) {
		if (text[i] == ',' && !ignoring) {
			ignoring = true;
		}
		else if (ignoring && text[i] != ' ' && text[i] != ',') {
			ignoring = false;
			text2 += concat + text[i];
		}
		else if (!ignoring) text2 += text[i];
	}
	cout << text2;
}
