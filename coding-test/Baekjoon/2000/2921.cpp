#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
    cin >> n;
	int ans = 0;
	for (int i=0; i<=n; i++) {
		for (int j=i; j<=n; j++)
            ans += i + j;
	}
	cout << ans;
}