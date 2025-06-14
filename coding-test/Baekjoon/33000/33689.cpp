#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    string str;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str[0] == 'C')
            cnt++;
    }
    cout << cnt;
    return (0);
}