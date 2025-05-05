#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, res = 0;
	int win_a = 0, win_b = 0;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			if (win_a)
			{
				win_a = 0;
				win_b = 1;
			}
			else
			{
				win_a = 1;
				win_b = 0;
			}
		}
		else if (a[i] < b[i])
		{
			if (a[i] == 1 && b[i] == 3)
			{
				win_a++;
				win_b = 0;
			}
			else
			{
				win_b++;
				win_a = 0;
			}
		}
		else
		{
			if (b[i] == 1 && a[i] == 3)
			{
				win_b++;
				win_a = 0;
			}
			else
			{
				win_a++;
				win_b = 0;
			}
		}
		if (res < win_a || res < win_b)
			res = win_a > win_b ? win_a : win_b;
	}
	cout << res;
}
