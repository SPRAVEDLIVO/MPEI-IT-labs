#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Info {
    string surname;
    string name;
    string middle_name;

    Info(string line) {
        int idx = 0;
        bool inside = false;
        string l;
        for (char s : line) {
            
            if (idx == 2) {
                if (s != ' ') l += s;
                else { surname = l; l = ""; }
            }
            else if (idx == 5) {
                if (s != ' ') l += s;
                else { name = l; l = ""; }
            }
            else if (idx == 8) {
                if (s != ' ') l += s;
                else { middle_name = l; l = ""; }
            }
            if (s == ' ') idx++;
        }
        if (idx == 8 && !l.empty()) middle_name = l;
    }
};

int main()
{
    vector<Info> v;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) break;
        v.push_back(Info(line));
    }

    for (Info s : v) {
        cout << s.surname << " " << s.name << " " << s.middle_name << endl;
    }
}

/*
ФАМИЛИЯ - ИВАНОВ ИМЯ - ИВАН ОТЧЕСТВО - ИВАНОВИЧ
ФАМИЛИЯ - ГОСЛИНГ ИМЯ - РАЙАН ОТЧЕСТВО - ИВАНОВИЧ

ИВАНОВ ИВАН ИВАНОВИЧ
ГОСЛИНГ РАЙАН ИВАНОВИЧ
*/