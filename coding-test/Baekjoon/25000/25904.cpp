#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, x;
    cin >> n >> x;
	int t[n + 1];
	for (int i=1; i<=n; i++)
        cin >> t[i];
	int seq = 1;
	while (true) {
		if (x > t[seq]) {
			cout << seq;
			return 0;
		}
		x++;
		seq = seq + 1 > n ? 1 : seq + 1;
	}
}