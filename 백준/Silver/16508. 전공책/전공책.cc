#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int price;
string target;
vector<int> alpha(26);

bool	solve(vector<pair<int, string> > &vec, vector<int> &comb)
{
	vector<int> cp_alpha = alpha;
	int len = 0;

	for (int j = 0; j < comb.size(); j++)
	{
		string str = vec[comb[j]].second;
		for (int k = 0; k < str.length(); k++)
		{
			if (cp_alpha[str[k] - 'A'] != 0)
			{
				cp_alpha[str[k] - 'A']--;
				len++;
			}
		}
	}
	return (len == (int)target.length());
}

void	back_track(vector<pair<int, string> > &vec, vector<int> comb, vector<bool> &used, int cnt, int depth, int total)
{
	if (price != 0 && total > price)
		return;
	if (cnt == depth)
	{
		if (solve(vec, comb))
		{
			if (price == 0 || price > total)
				price = total;
		}
		return;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (used[i] == false)
		{
			if (comb.empty() || comb[0] < i)
			{
				used[i] = true;
				comb.push_back(i);
				back_track(vec, comb, used, cnt, depth + 1, total + vec[i].first);
				comb.pop_back();
				used[i] = false;
			}
		}
	}
}

int main()
{
	fast;
	int n, need;

	cin >> target >> n;
	vector<pair<int, string> > vec(n);
	vector<bool> used(n, false); 
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	need = target.length();
	for (int i = 0; i < need; i++)
		alpha[target[i] - 'A']++;
	vector<int> comb;
	for (int i = 1; i <= n; i++)
		back_track(vec, comb, used, i, 0, 0);

	if (price == 0)
		cout << -1;
	else
		cout << price;
}
