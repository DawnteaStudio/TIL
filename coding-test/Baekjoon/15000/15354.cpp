#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int res = 1;
    int n;
    cin >> n;
    char tmp = 0, input;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input != tmp)
            res++;
        tmp = input;
    }
    cout << res;
}
