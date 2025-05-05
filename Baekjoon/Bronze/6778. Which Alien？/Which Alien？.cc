#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, e;

	cin >> a >> e;
	if (a >= 3 && e <= 4) cout << "TroyMartian\n";
	if (a <= 6 && e >= 2) cout << "VladSaturnian\n";
	if (a <= 2 && e <= 3) cout << "GraemeMercurian\n";
	return (0);
}