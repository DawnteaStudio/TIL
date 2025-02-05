#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int s, m, l;
	cin >> s >> m >> l;
	int res = s + 2 * m + 3 * l;
	if (res >= 10)
		cout << "happy";
	else
		cout << "sad";
}