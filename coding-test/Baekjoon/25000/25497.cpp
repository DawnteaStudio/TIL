#include <iostream>
#include <string>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 0;
    cin >> n;
    string  skill;
    cin >> skill;
    queue<char> l;
    queue<char> s;

    for (int i = 0; i < n; i++)
    {
        if (skill[i] >= '1' && skill[i] <= '9')
            res++;
        else if (skill[i] == 'L')
            l.push('L');
        else if (skill[i] == 'S')
            s.push('S');
        else if (skill[i] == 'R')
        {
            if (l.empty())
                break;
            l.pop();
            res++;
        }
        else if (skill[i] == 'K')
        {
            if (s.empty())
                break;
            s.pop();
            res++;
        }
    }
    cout << res;
}