#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	int num, use;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> use;
		if (use > 1000)
			cout << use << " " << 1000 * n + (use - 1000) * m << '\n';
		else
			cout << use << " " << use * n << '\n';
	}
}
