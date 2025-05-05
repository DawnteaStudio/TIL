#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    comp(string a, string b)
{
    int i = 0;

    if (a.length() > b.length())
        return (false);
    else if (a.length() < b.length())
        return (true);
    else
        return a < b;
}

int main()
{
    fast;
    int n;
    string str;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        arr[i] = str;
    }

    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            str = arr[i - 1];
            if (str != arr[i])
                cout << arr[i] << '\n';
        }
        else
            cout << arr[i] << '\n';
    }
}