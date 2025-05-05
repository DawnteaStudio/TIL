#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int alpha_value(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
    return 0;
}

int main()
{
    fast;
    string str;

    while (true) {
        getline(cin, str);
        if (str == "#") break ;

        int sum = 0;
        for (int i=1; i<=(int)str.size(); i++)
            sum += i * alpha_value(str[i - 1]);
        cout << sum << '\n';
    }
    return (0);
}