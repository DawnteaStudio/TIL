#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int m; cin >> m;
	if (m >= 8) cout << "satisfactory";
	else cout << "unsatisfactory";
	return (0);
}