#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void find_char(int num, int l, int mid)
{
    if (num <= 3)
    {
        if (num == 1)
            cout << "m";
        else
            cout << "o";
    }
    else
    {
        int part = (l - mid) / 2;
        if (num > part + mid)
        {
            num -= (part + mid);
            mid--;
            find_char(num, part, mid);
        }
        else
        {
            if (num > part)
            {
                num -= part;
                if (num == 1)
                    cout << 'm';
                else
                    cout << 'o';
            }
            else
                find_char(num, part , mid - 1);
        }
    }
}

int main()
{
    int num;
    cin >> num;
    int l = 3, mid = 3;

    while (l < num)
    {
        l = (l * 2) + (mid + 1);
        mid++;
    }
    find_char(num, l, mid);
}