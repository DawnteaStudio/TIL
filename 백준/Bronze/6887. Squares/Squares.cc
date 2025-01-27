#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;

	int res = 1;
	while (res * res < n)
		res++;
	if (res * res > n)
		res--;
	cout << "The largest square has side length " << res << ".";
}