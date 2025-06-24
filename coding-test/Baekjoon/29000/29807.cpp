#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
	fast;
    long long N, i, arr[6] = { 0 }, ans = 0;

    cin >> N;
    for (i = 1; i <= N; i++) cin >> arr[i];

    if (arr[1] > arr[3]) ans += (arr[1] - arr[3]) * 508;
    else ans += (arr[3] - arr[1]) * 108;
    if (arr[2] > arr[4]) ans += (arr[2] - arr[4]) * 212;
    else ans += (arr[4] - arr[2]) * 305;
    ans += arr[5] * 707;

    cout << ans * 4763;
}