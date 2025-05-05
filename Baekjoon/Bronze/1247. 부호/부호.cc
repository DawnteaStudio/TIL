#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;

	for (int i = 0; i < 3; i++)
	{
		queue<long long> plus;
		queue<long long> minus;
		cin >> n;
		long long input;
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			if (input == 0)
				continue;
			if (input > 0)
				plus.push(input);
			else
				minus.push(input);
		}
		while (!plus.empty() && !minus.empty())
		{
			long long p = plus.front();
			plus.pop();
			long long m = minus.front();
			minus.pop();
			if (p + m > 0)
				plus.push(p + m);
			else if (p + m < 0)
				minus.push(p + m);
		}
		if (!plus.empty())
			cout << "+\n";
		else if (!minus.empty())
			cout << "-\n";
		else
			cout << "0\n";
	}
}
