#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
    fast;
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        bool seen[10] = {false};
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            if (seen[str[i] - '0'] == false)
            {
                seen[str[i] - '0'] = true;
                tmp++;
            }
        }
        cout << tmp << '\n';
    }
}