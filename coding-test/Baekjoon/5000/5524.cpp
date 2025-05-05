#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < (int)str.length(); j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z')
                cout << (char)(str[j] - 'A' + 'a');
            else
                cout << str[j];
        }
        cout << '\n';
    }
}
