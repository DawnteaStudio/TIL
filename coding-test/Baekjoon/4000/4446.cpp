#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char    arr1[6] = {'a', 'i', 'y', 'e', 'o', 'u'};
char    arr2[20] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

bool    isVowels(char ch)
{
    if (ch < 'a')
        ch += ('a' - 'A');
    
    if (ch == 'a' || ch == 'i' || ch == 'y' || ch == 'e' || ch == 'o' || ch == 'u')
        return true;
    else
        return false;
}

char    printVowel(char ch)
{
    bool    isChanged = false;
    char    res;
    int i = 0;

    if (ch < 'a')
    {
        ch += ('a' - 'A');
        isChanged = true;
    }
    for (; i < 6; i++)
        if (arr1[i] == ch) break;
    if (i < 3)
        i += 3;
    else
        i -= 3;
    res = arr1[i];
    if (isChanged)
        res -= ('a' - 'A');
    return res;
}

char    printConsonant(char ch)
{
    bool    isChanged = false;
    char    res;
    int i = 0;

    if (ch < 'a')
    {
        ch += ('a' - 'A');
        isChanged = true;
    }
    for (; i < 20; i++)
        if (arr2[i] == ch) break;
    if (i < 10)
        i += 10;
    else
        i -= 10;
    res = arr2[i];
    if (isChanged)
        res -= ('a' - 'A');
    return res;
}

int main()
{
    fast;
    string str;
    while(!cin.eof())
    {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                if (isVowels(str[i]))
                    cout << printVowel(str[i]);
                else
                    cout << printConsonant(str[i]);
            }
            else
                cout << str[i];
        }
        cout << '\n';
    }
}