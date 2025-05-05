#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, k, save = 0, now = 0;
    string cmd;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "ammo")
            now += k;
        else if (cmd == "save")
            save = now;
        else if (cmd == "shoot")
            now -= 1;
        else if (cmd == "load")
            now = save;
        cout << now << '\n';
    }
}