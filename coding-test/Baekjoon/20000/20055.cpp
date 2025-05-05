/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, k, cnt = 0, step = 0, size;
    bool flag;
    cin >> n >> k;

    vector<int> vec(2 * n);
    deque<int> robot;
    for (int i = 0; i < 2 * n; i++)
        cin >> vec[i];

    int up = 0, down = n - 1;
    while (cnt < k)
    {
        flag = false;
        up--;
        if (up < 0)
            up = 2 * n - 1;
        down--;
        if (down < 0)
            down = 2 * n - 1;
        size = robot.size();
        if (size && robot.front() == down)
        {
            robot.pop_front();
            size--;
        }
        for (int i = 0; i < size; i++)
        {
            int pos = (robot[i] + 1) % (2 * n);
            if (vec[pos] > 0)
            {
                if (i != 0)
                {
                    if (robot[i - 1] == pos)
                        continue;
                }
                vec[pos]--;
                if (vec[pos] == 0)
                    cnt++;
                robot[i] = pos;
                if (robot[i] == down)
                    flag = true;
            }
        }
        if (flag)
            robot.pop_front();
        if (vec[up] > 0)
        {
            vec[up]--;
            if (vec[up] == 0)
                cnt++;
            robot.push_back(up);
        }
        step++;
    }
    cout << step;
}