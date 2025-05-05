#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    cmp(string a, string b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        return a < b;
    return false;
}

bool    cmp2(string a, string b)
{
    int num1 = stoi(a.substr(7));
    int num2 = stoi(b.substr(7));
    return num1 < num2;
}

int main()
{
    fast;
    int n;
    cin >> n;
    cin.ignore();
    vector<string> v;
    vector<string> b;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        if (tmp.length() > 4 && tmp[3] == '.')
            b.push_back(tmp);
        else
            v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    sort(b.begin(), b.end(), cmp2);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << '\n';
}
