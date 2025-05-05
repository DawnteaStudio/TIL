#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;

    int n, cnt = 0;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
            cnt++;
    }
    cout << cnt;
}
