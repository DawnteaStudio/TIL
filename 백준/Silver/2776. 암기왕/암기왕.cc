#include <iostream>
#include <map>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int N, M, input;
		map<int, int> m;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			m.insert({input, 1});
		}
		cin >> M;
		for (int k = 0; k < M; k++)
		{
			cin >> input;
			if (m.find(input) != m.end())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}
