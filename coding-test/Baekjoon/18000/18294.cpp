#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    int res = 0;
    string name;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (m.find(str) == m.end())
            m[str] = 1;
        else
            m[str]++;
        if (m[str] > res) {
            res = m[str];
            name = str;
        }
    }
    if (m[name] > n - m[name])
        cout << name;
    else
        cout << "NONE";
}
