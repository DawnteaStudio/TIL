#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll =long long;

ll res;
int n;

void	find_res(vector<pair<int, int>> v, int depth, ll sour, ll bitter)
{
	ll tmp = (sour > bitter ? sour - bitter : bitter - sour);

	if (tmp != 0 && (tmp < res))
		res = tmp;
	if (depth == n)
		return ;
	find_res(v, depth + 1, sour, bitter);
	if (sour != 0)
		sour *= v[depth].first;
	else
		sour = v[depth].first;
	bitter += v[depth].second;
	find_res(v, depth + 1, sour, bitter);
}

int main()
{
	fast;

	cin >> n;
	vector<pair<int, int>> v(n);
	ll sour, bitter;
	cin >> sour >> bitter;
	v[0] = {sour, bitter};
	res = sour > bitter ? sour - bitter : bitter - sour;

	for (int i = 1; i < n; i++)
	{
		cin >> sour >> bitter;
		v[i] = {sour, bitter};
	}
	find_res(v, 1, v[0].first, v[0].second);
	find_res(v, 1, 0, 0);
	cout << res;
}
