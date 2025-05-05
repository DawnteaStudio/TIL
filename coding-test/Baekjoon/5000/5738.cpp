#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, d;
    int attack, tmp;
    int defense[2];
    while (true)
    {
        cin >> a >> d;
        if (a == 0)
            break;
        attack = -1;
        defense[0] = -1;
        defense[1] = -1;
        
        for (int i = 0; i < a; i++)
        {
            cin >> tmp;
            if (attack == -1 || attack > tmp)
                attack = tmp;
        }

        for (int i = 0; i < d; i++)
        {
            cin >> tmp;
            if (defense[0] == -1)
                defense[0] = tmp;
            else if (defense[0] > tmp)
            {
                defense[1] = defense[0];
                defense[0] = tmp;
            }
            else if (defense[1] == -1 || defense[1] > tmp)
                defense[1] = tmp;
        }
        if (attack < defense[1])
            cout << "Y\n";
        else
            cout << "N\n";
    }
}
