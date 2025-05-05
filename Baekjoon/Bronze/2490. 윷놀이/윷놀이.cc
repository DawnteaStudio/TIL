#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, cnt;

	for (int i = 0; i < 3; i++)
	{
		cnt = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> n;
			if (n == 0)
				cnt++;
		}
		if (cnt == 1)
			cout << "A\n";
		else if (cnt == 2)
			cout << "B\n";
		else if (cnt == 3)
			cout << "C\n";
		else if (cnt == 4)
			cout << "D\n";
		else
			cout << "E\n";
	}
	return (0);
}
