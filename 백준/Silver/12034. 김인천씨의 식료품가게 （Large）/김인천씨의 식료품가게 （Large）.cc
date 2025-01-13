#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, t, tmp;
	queue<int> q;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		cout << "Case #" << i << ": ";
		for (int j = 0;j < t * 2; j++)
		{
			cin >> tmp;
			if (q.empty() || q.front() != tmp)
			{
				cout << tmp << " ";
				q.push((tmp / 3) * 4);
			}
			else
				q.pop();
		}
		cout << '\n';
	}
}
