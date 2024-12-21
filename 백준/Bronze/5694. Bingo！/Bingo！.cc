#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, b;

	while (true)
	{
		cin >> n >> b;
		if (n == 0)
			break;
		vector<int> vec(b);
		vector<bool> visited(n + 1, false);
		for (int i = 0; i < b; i++)
			cin >> vec[i];
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)
			{
				int tmp = vec[i] - vec[j];
				if (tmp < 0)
					visited[-tmp] = true;
				else
					visited[tmp] = true;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			if (visited[i] == false)
			{
				cout << "N\n";
				break;
			}
			if (i == n)
				cout << "Y\n";
		}
	}
}
