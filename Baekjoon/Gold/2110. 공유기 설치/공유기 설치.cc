#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long solve(long long left, long long right, long long pos[], long long N, long long M)
{
    long long mid, now, cnt = 2;
    long long start = pos[0];
    if (cnt == M)
        return (right);
    while (left <= right)
    {
        cnt = 1;
        now = start;
        mid = (left + right) / 2;

        for (int i = 1; i < N; i++)
        {
            if (now + mid <= pos[i])
            {
                now += (pos[i] - now);
                cnt++;
            }
        }
        if (cnt >= M)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (right);
}

int main()
{
    fast;
    long long N, M;
    cin >> N >> M;

    long long *pos = new long long[N];
    for (int i = 0; i < N; i++)
        cin >> pos[i];
    sort(pos, pos + N);
    cout << solve(1, pos[N - 1] - pos[0], pos, N, M);
    delete[] pos;
}
