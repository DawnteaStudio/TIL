#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int mid[5];
    int avr, sum = 0, tmp = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        mid[i] = tmp;
        sum += tmp;
    }
    avr = sum / 5;
    sort(mid, mid + 5);
    cout << avr << '\n' << mid[2];
}
