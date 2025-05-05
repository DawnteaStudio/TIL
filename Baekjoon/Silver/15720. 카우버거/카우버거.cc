#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool	cmp(int a, int b)
{
	return a > b;
}

void	init(vector<int> &vec, int cnt, int &total)
{
	for (int i = 0; i < cnt; i++)
	{
		cin >> vec[i];
		total += vec[i];
	}
	sort(vec.begin(), vec.end(), cmp);
}

int main() {
	fast;
	int total = 0, sale;
	int cnt;
	int burger, side, drink;

	cin >> burger;
	cnt = burger;
	cin >> side;
	if (cnt > side)
		cnt = side;
	cin >> drink;
	if (cnt > drink)
		cnt = drink;

	vector<int> b(burger);
	vector<int> s(side);
	vector<int> d(drink);

	init(b, burger, total);
	init(s, side, total);
	init(d, drink, total);

	sale = total;
	for (int i = 0; i < cnt; i++)
	{
		int tmp = b[i] + s[i] + d[i];
		sale -= (tmp / 10);
	}
	cout << total << '\n' << sale;
}
