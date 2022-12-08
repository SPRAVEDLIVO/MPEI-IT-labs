#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    vector<string> strings;
    string current, mark;
    string great = "GREAT";
    int i = 0;
    while(i != n) {
        string inp;
        getline(cin, inp);
        if (inp == "") continue;
        strings.push_back(inp);
        i++;
    }
    bool addmark;
    for (int i = 0; i < n; i++) {
        addmark = false;
        current = strings[i];
        mark = "";
        for (int j = 0; j < current.length(); j++) {
            char s = current[j];
            if (!addmark && s == ' ' && current[j-1] == '-') {
                addmark = true;
                continue;
            }
            if (addmark) mark += s;
        }
        if (mark == great) {
            cout << current << endl;
        }
    }
}

/*
n = 2
INVANOV - GREAT
SIDOROV - OK
INVANOV - GREAT
*/