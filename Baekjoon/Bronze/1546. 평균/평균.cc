#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int cases;
	double score, max_score = 0, res = 0;
	vector<double> v;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> score;
		if (score > max_score)
			max_score = score;
		v.push_back(score);
	}
	for (int i = 0; i < cases; i++)
		res += v[i]/max_score * 100;
	cout << res/cases;
}
