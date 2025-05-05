#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N, C;
long long house[200020];

bool check(long long mid)
{
    long long index = house[0];
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (house[i] >= index + mid)
        {
            cnt++;
            index = house[i];
        }
    }
    if (cnt >= C)
        return  true;
    else
        return false;
}

long long solve(){
    long long left = 1, right = house[N - 1];
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (check(mid)) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}

int main()
{
    fast;
    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> house[i];
    sort(house, house + N);
    cout << solve() << "\n";
}
