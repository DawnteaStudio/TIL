#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int scolville(string &str)
{
    if (str == "Poblano")
        return 1500;
    if (str == "Mirasol")
        return 6000;
    if (str == "Serrano")
        return 15500;
    if (str == "Cayenne")
        return 40000;
    if (str == "Habanero")
        return 125000;
    if (str == "Thai")
        return 75000;
    return 0;
}

int main()
{
    fast;
    int res = 0, n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        res += scolville(str);
    }
    cout << res;
}