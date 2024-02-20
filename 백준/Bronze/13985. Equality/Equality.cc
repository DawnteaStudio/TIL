#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int a, b, c, res;
    char cal, equal;
    cin >> a >> cal >> b >> equal >> c;
    if (cal == '+')
        res = a + b;
    else if (cal == '-')
        res = a - b;
    else if (cal == '*')
        res = a * b;
    else if (cal == '/')
        res = a / b;
    else if (cal == '%')
        res = a % b;
    if (res == c)
        cout << "YES";
    else
        cout << "NO";
}
