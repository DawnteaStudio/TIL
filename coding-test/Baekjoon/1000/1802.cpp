#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int T;

bool check1(string str)
{
    int size = str.size();
    int mid = str.size()/2;

    if (size == 1 || (size == 3 && str[0] != str[2]))
        return true;
    if (str[0] == str[size-1])
        return false;
    else
    {
        if(check1(str.substr(0, mid)) && check1(str.substr(mid+1, mid)))
            return true;
        else
            return false;
    }
        
}

bool check2(string str)
{
    int size = str.size();
    if (size == 1)
        return true;
    if (str[0] != str[size-1])
        return (check2(str.substr(1, size-2)));
    else
        return false;
}

int main()
{
    fast;
    cin >> T;
    string str;

    for (int i = 0; i < T; i++)
    {
        cin >> str;
        if (check1(str) && check2(str))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}