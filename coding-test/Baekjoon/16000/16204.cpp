#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, M, K;
    cin >> N >> M >> K;
    int res = 0;
    res += (K > M ? M : K);
    res += (N-M > N-K ? N-K : N-M);
    cout << res;
}