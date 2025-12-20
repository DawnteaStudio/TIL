#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, w;
	cin >> n >> w;

	cout << (n * 5280) / w;
}
