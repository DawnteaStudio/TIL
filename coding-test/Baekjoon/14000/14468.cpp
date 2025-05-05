#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string input;
    cin >> input;

    int cnt = 0, len = input.length();
    map<char, int> m;
    for (int i = 0; i < len; i++) {
        if (m.find(input[i]) == m.end())
            m[input[i]] = i;
        else {
            int index = m[input[i]];
            for (map<char, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
                if (index < iter->second)
                    cnt++;
            }
            m.erase(input[i]);
        }
    }
    cout << cnt;
}
