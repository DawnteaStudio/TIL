#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n;
	cin >> n;
	bool ez = false, hard = false;

	int tmp, res;
	cin >> res;
	for (int i = 0; i < n - 1; i++) {
		cin >> tmp;
		if (tmp > res)
			ez = true;
		else if (tmp < res)
			hard = true;
	}
	if (ez && hard)
		cout << "?";
	else if (ez)
		cout << "ez";
	else
		cout << "hard";
}
