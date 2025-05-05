#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int move;
    int dir = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> move;
        dir += move;
    }

    dir %= 4;
    if (dir == 0)
        cout << "N";
    else if (dir == 1)
        cout << "E";
    else if (dir == 2)
        cout  << "S";
    else
        cout << "W";
}

