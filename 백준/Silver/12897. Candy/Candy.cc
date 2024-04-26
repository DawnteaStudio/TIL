#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define MAX 1000000007

int main()
{
	fast;
	int n;
	cin >> n;
	long long feel_good = 1;

	for (int i = 0; i < n; i++)
	{
		feel_good *= 3;
		if (feel_good > MAX)
			feel_good %= MAX;
	}
	cout << feel_good - 1;
}