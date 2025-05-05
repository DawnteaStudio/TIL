#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long  game, win;

long long solve(long long win_rate)
{
    long long left = 1;
    long long right = game;
    long long mid, tmp;

    while(left <= right)
    {
        mid = (left + right) / 2;
        tmp = ((win + mid) * 100) / (game + mid);

        if (win_rate < tmp)
            right = mid - 1;
        else
            left = mid + 1;
    }

    tmp = ((win + left) * 100) / (game + left);
    if (tmp == win_rate)
        return -1;

    return (left);
}

int main()
{
    fast;
    cin >> game >> win;

    long long win_rate = (win * 100) / game;
    cout << solve(win_rate);
}