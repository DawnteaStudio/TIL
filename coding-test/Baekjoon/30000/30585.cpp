#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    string tmp;
    cin >> n >> m;
    int red = 0, blue = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            if (tmp[j] == '0')
                red++;
            else
                blue++;
        }
    }
    cout << (red < blue ? red  : blue);
}