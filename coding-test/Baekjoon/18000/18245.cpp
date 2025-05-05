#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int next = 2;
    string input;
    while (true) {
        getline(cin, input);
        int i = 0;
        if (input == "Was it a cat I saw?")
            break;
        int len = input.length();
        while (i < len) {
            cout << input[i];
            i += next;
        }
        next++;
        cout << '\n';
    }
}