#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, x;
	bool flag = true;
	cin >> t >> x;

	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		bool tmp_flag = false;
		int a; cin >> a;
		for (int j = 0; j < a; j++)
		{
			int tmp; cin >> tmp;
			if (tmp_flag)
				continue;
			if (tmp == x)
				tmp_flag = true;
		}
		if (!tmp_flag)
			flag = false;
	}
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
