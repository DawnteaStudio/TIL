#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    find_pos(long long &pos_x, long long &pos_y, int pos, int depth)
{
    long long scale = pow(2, depth);
    switch (pos)
    {
        case 1:
            break;
        case 2:
            pos_x += scale / 2;
            break;
        case 3:
            pos_x += scale / 2;
            pos_y += scale / 2;
            break;
        case 4:
            pos_y += scale / 2;
            break;
        default:
            break;
    }
}

void    solve(string &res, long long &pos_x, long long &pos_y, int &depth)
{
    long long scale = pow(2, depth);
    if (pos_x < 0 || pos_y < 0 || pos_x >= scale || pos_y >= scale)
        depth = -1;
    else
    {
        if (pos_x < scale / 2)
        {
            if (pos_y < scale / 2)
                res += "1";
            else
            {
                res += "4";
                pos_y -= scale / 2;
            }
        }
        else
        {
            if (pos_y < scale / 2)
            {
                res += "2";
                pos_x -= scale / 2;
            }
            else
            {
                res += "3";
                pos_y -= scale / 2;
                pos_x -= scale / 2;
            }
        }
        depth--;
    }
}

int main() {
    fast;
    int n;
    long long move_x, move_y;
    long long pos_x = 0, pos_y = 0;
    string name, res;
    cin >> n >> name;

    cin >> move_x >> move_y;
    move_x *= -1;
    move_y *= -1;

    int len = name.length();
    for(int i = 0; i < len; i++)
        find_pos(pos_x, pos_y, name[i] - '0', len - i);
    pos_x += move_x;
    pos_y += move_y;
    while (len > 0)
        solve(res, pos_x, pos_y, len);
    if (len != -1)
        cout << res;
    else
        cout << len;
}