#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, i;
	cin >> n >> i;
	cout << (i - 1) * n + 1;
}