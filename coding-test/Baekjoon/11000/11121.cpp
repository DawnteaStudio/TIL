#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
    fast;
    int t;
    cin >> t;
    string input, output;
    for (int i = 0; i < t; i++)
    {
        cin >> input >> output;
        if (input == output)
            cout << "OK\n";
        else
            cout << "ERROR\n";
    }
}
