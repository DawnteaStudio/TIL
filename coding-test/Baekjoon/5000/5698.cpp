#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;



int main()
{
    fast;
    bool    correct;
    string  str;
    char    cri;
    while (true)
    {
        correct = true;
        getline(cin, str);
        if (str[0] == '*')
            break;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && str[i] < 'a')
                str[i] += 'a' - 'A';
        }
        cri = str[0];
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                if (i + 1 < str.length() && str[i + 1] != cri)
                {
                    cout << "N\n";
                    correct = false;
                    break;
                }
            }
        }
        if (correct)
            cout << "Y\n";
    }
}