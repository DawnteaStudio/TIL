#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string hello;
    cin >> hello;

    int key;
    key = hello[0] ^ 'C';
    for (int i = 0; i < hello.length(); i++)
        cout << (char)(hello[i] ^ key);
}
