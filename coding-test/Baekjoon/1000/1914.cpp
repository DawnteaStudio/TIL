#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    hanoi(int start, int goal, int sup, int plates)
{
    if (plates == 1)
        cout << start << " " << goal << '\n';
    else
    {
        hanoi(start, sup, goal, plates - 1);
        cout << start << " " << goal << '\n';
        hanoi(sup, goal, start, plates - 1);
    }
}

int main() {
    fast;
    int n;
    cin >> n;
    double tmp = pow(2., (double)n);
    string res = to_string(tmp);
    int pos = res.find('.');
    res = res.substr(0, pos);
    res[res.length() - 1] -= 1;
    cout << res << '\n';

    if (n <= 20)
        hanoi(1, 3, 2, n);
}
