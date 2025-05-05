#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, tmp, res;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		res = 0;
		for (int j = 0; j < 5; j++)
		{
			cin >> tmp;
			if (res < tmp)
				res = tmp;
		}
		cout << "Case #" << i << ": " << res << '\n';
	}
}
