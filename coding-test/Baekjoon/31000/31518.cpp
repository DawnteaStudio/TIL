#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    bool slot, res = true;
    int n, is_seven;
    cin >> n;   
    for (int i = 0; i < 3; i++)
    {
        slot = false;
        for (int j = 0; j < n; j++)
        {
            cin >> is_seven;
            if (is_seven == 7)
                slot = true;
        }
        if (slot == false)
            res = false;
    }
    cout << (res == true ? 777 : 0);
}
