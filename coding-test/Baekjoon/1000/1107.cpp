#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_btn_res(int target, bool keys[10], bool inc)
{
    int tmp = target;
    while (tmp >= 0 && tmp <= 1000000)
    {
        string str = to_string(tmp);
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (keys[str[i] - '0'] == false)
                break;
            if (i == len - 1)
                return (len + abs(target - tmp));
        }
        if (inc)
            tmp++;
        else
            tmp--;
    }
    return -1;
}

int main() {
    fast;
    int n = 100, target, move_res, btn_res;
    int up = -1, down = -1;
    cin >> target;
    if (target == 100)
    {
        cout << 0;
        return 0;
    }

    int cnt;
    cin >> cnt;
    int nwkey;
    bool keys[10];
    for (int i = 0; i < 10; i++)
        keys[i] = true;
    for (int i = 0; i < cnt; i++)
    {
        cin >> nwkey;
        keys[nwkey] = false;
    }
    if (target < 100)
        move_res = n - target;
    else
        move_res = target - n;
    if (cnt != 10)
    {
        down = get_btn_res(target, keys, false);
        up = get_btn_res(target, keys, true);
    }
    if (down > 0 && up > 0)
        btn_res = up > down ? down : up;
    else
        btn_res = up > down ? up : down;
    
    if (btn_res > 0)
        cout << (btn_res > move_res ? move_res : btn_res);
    else
        cout << move_res;
}
