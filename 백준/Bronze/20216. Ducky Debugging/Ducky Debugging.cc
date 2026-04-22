#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        if (line == "I quacked the code!")
            return 0;

        char last = line.back();

        if (last == '?')
            cout << "Quack!" << endl; 
        else if (last == '.')
            cout << "*Nod*" << endl;  
    }

}