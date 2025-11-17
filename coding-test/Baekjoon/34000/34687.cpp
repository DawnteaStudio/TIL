#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
	cin >> n >> m;

	if (n * 81 <= m * 100)
		cout << "yaho";
	else
		cout << "no";
}
