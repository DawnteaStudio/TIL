#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int arr[3];
    int tmp[3];
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        res += arr[i];
        tmp[i] = arr[i];
    }
    if (res >= 100)
    {
        cout << "OK";
        return 0;
    }
    else
        sort(arr, arr + 3);
    for (int i = 0; i < 3; i++)
    {
        if (arr[0] == tmp[i])
        {
            if (i == 0)
                cout << "Soongsil";
            else if (i == 1)
                cout << "Korea";
            else
                cout << "Hanyang";
        }
    }
}
