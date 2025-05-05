#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;

    int arr[43] = {0};
    int num, res = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        if (arr[num % 42] == 0)
        {
            arr[num % 42]++;
            res++;
        }
    }
    cout << res;
}
