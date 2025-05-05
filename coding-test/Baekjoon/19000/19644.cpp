#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    bool flag = true;
    int l, ml, mk, c, hp, no_shot;
    queue<int> use_c;
    cin >> l >> ml >> mk >> c;

    for (int i = 1; i <= l; i++)
    {
        cin >> hp;
        if (hp == 0)
            continue;
        if (!use_c.empty())
        {
            if (i >= ml + use_c.front())
                use_c.pop();
        }
        no_shot = use_c.size();
        if (i < ml)
        {
            if (hp > i * mk - no_shot * mk)
            {
                if (c > 0)
                {
                    c--;
                    use_c.push(i);
                }
                else
                {
                    cout << "NO";
                    flag = false;
                    break;
                }
            }
        }
        else
        {
            if (hp > ml * mk - no_shot * mk)
            {
                if (c > 0)
                {
                    c--;
                    use_c.push(i);
                }
                else
                {
                    cout << "NO";
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag)
        cout << "YES";
}
