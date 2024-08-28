#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int wc, hc, ws, hs;

	cin >> wc >> hc >> ws >> hs;
	if (wc >= ws + 2 && hc >= hs + 2)
		cout << 1;
	else
		cout << 0;
}
