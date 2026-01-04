#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int x, y, z, u, v, w;
	cin >> x >> y >> z >> u >> v >> w;
	cout << x * (u / 100) + y * (v / 50) + z * (w / 20);
}