#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int cu, du, cd, dd, cp, dp, hp;
    cin >> cu >> du >> cd >> dd >> cp >> dp >> hp;

    int sec = 0;
    hp -= (du + dd + dp);
    while (hp > 0)
    {
        sec++;
        if (sec % cu == 0)
            hp -= du;
        if (sec % cd == 0)
            hp -= dd;
        if (sec % cp == 0)
            hp -= dp;
    }
    cout << sec;
}