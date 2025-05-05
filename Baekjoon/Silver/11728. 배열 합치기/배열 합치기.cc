#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	vector<int> v(n + m);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int index_a = 0, index_b = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (index_a == n)
		{
			v[i] = b[index_b];
			index_b++;
		}
		else if (index_b == m)
		{
			v[i] = a[index_a];
			index_a++;
		}
		else
		{
			if (a[index_a] > b[index_b])
			{
				v[i] = b[index_b];
				index_b++;
			}
			else
			{
				v[i] = a[index_a];
				index_a++;
			}
		}
	}
	for (int i = 0; i < n + m; i++)
		cout << v[i] << ' ';
}