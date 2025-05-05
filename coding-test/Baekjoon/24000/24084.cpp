#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    string str;
    cin >> n >> str;
    for (int i = 1; i < (int)str.length(); i++)
    {
        if (str[i] == 'J')
            cout << str[i - 1] << '\n';
    }
}
