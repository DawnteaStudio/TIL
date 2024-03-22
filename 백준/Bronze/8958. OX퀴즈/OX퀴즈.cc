#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int n, res, score;
	string quiz;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		res = 0;
		score = 0;
		cin >> quiz;
		for (int j = 0; j < (int)quiz.length(); j++)
		{
			if (quiz[j] == 'O')
				res += ++score;
			else
				score = 0;
		}
		cout << res << '\n';
	}
}
