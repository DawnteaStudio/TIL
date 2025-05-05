#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int alpha[26];

    for (int i = 0; i < 26; i++)
        alpha[i] = -1;

    string str;
    cin >> str;
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (alpha[str[i] - 'a'] == -1)
            alpha[str[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++)
        cout << alpha[i] << ' ';
}
