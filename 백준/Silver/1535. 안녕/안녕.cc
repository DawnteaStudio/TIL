#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int max_val;
int n;

void	find_all_case(int i, vector<int> hp, vector<int> pls, int life, int res)
{
	if (res > max_val)
		max_val = res;
	if (i == n)
		return;
	find_all_case(i + 1, hp, pls, life, res);
	life -= hp[i];
	if (life <= 0)
		return;
	res += pls[i];
	find_all_case(i + 1, hp, pls, life, res);
}

int main()
{
	fast;
	cin >> n;

	vector<int> hp(n);
	vector<int> pls(n);

	for (int i = 0; i < n; i++)
		cin >> hp[i];
	for (int i = 0; i < n; i++)
		cin >> pls[i];
	find_all_case(0, hp, pls, 100, 0);
	cout << max_val;
}
