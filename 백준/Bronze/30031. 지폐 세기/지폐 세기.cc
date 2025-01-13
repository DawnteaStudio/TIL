#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, res = 0;
	cin >> n;
	
	int p, t;
	for (int i = 0; i < n; i++)
	{
	    cin >> p >> t;
	    if (p == 136)
	        res += 1000;
	    else if (p == 142)
	        res += 5000;
	    else if (p == 148)
	        res += 10000;
	    else if (p == 154)
	        res += 50000;
	}
	cout << res;
}