#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    long long n, cnt = 0;
    cin >> n;

    long long start = 1, end = 2000000000;
    long long mid;

    while (true)
    {
        mid = (start + end) / 2;
        cnt = (mid / 3) + (mid / 5) - (mid / 15);
        if (cnt + n < mid)
            end = mid - 1;
        else if (cnt + n > mid)
            start = mid + 1;
        else
        {
            while (mid % 3 == 0 || mid % 5 == 0)
                mid--;
            break;
        }
    }
    cout << mid;
}
