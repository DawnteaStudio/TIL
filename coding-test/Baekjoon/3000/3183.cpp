#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool isLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

bool isValidDate(int d, int m, int y)
{
    if (d == 0 || m == 0 || y == 0) return false;
    if (d >= 32 || m > 12) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31) return false;
    if ((isLeapYear(y) && m == 2) && d >= 30) return false;
    if ((!isLeapYear(y) && m == 2) && d >= 29) return false;
    return true;
}

int main()
{
    fast;
    int d, m, y;

    while (true) {
        cin >> d >> m >> y;
        if (d == 0 && m == 0 && y == 0) break ;
        if (isValidDate(d, m, y)) cout << "Valid\n";
        else cout << "Invalid\n";
    }
    return (0);
}