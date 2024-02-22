#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
//못품 냅색 알고리즘 공부하고 다시 풀것
int main()
{
    fast;
    int N; cin >> N;

    int dp[N+1];
    for (int i=0; i<=N; i++)
        dp[i] = i;

    int i, j, k;
    i = j = k = 1;
    while (k <= N)
	{
        for (int n=1; n<=N; n++)
		{
            if (n >= k)
                dp[n] = min(dp[n], dp[n-k]+1);
        }
        i += 1;
        j += i;
        k += j;
    }
    cout << dp[N] << endl;
}
