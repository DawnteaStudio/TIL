#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
	cin >> n;

	int opp = -n;
	unsigned int opp2 = (unsigned int)opp;

	int res = 0;
	for (int i = 0; i < 32; i++) {
		if (opp2 % 2 != n % 2)
			res++;
		opp2 >>= 1;
		n >>= 1;
	}
	cout << res;
}
