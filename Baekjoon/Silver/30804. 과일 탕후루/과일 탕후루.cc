#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, res = 1;
	bool flag;
	cin >> n;

	if (n <= 2)
		cout << n;
	else
	{
		int i;
		vector<int> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		int a, b;
		int start = 0, end = n - 1;
		a = vec[0];
		for (i = 1; i < n; i++)
		{
			if (vec[i] != a)
			{
				b = vec[i];
				end = i++;
				break;
			}
		}
		if (end - start + 1> res)
			res = end - start + 1;
		for (;i < n; i++)
		{
			end++;
			if (vec[i] != a && vec[i] != b)
			{
				flag = false;
				int tmp = start;
				for (int j = tmp; j < i; j++)
				{
					if (vec[i - 1] != vec[j])
						flag = true;
					else
					{
						if (flag)
						{
							start = j;
							flag = false;
						}
					}
				}
				a = vec[i - 1];
				b = vec[i];
			}
			if (end - start + 1 > res)
				res = end - start + 1;
		}
		cout << res;
	}
}