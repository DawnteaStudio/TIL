#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str;
    cin >> str;
    int n;
    cin >> n;
    int start = 0;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        start += a;
    }
    str = str.substr(start, b);
    cout << str;
}