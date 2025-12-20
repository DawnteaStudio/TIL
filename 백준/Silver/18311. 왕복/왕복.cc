#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long n, k, len = 0;
	cin >> n >> k;
	vector<long long> vec(n + 1, 0);
	for (int i = 1; i <= n; i++) {
	    int tmp;
	    cin >> tmp;
	    len += tmp;
	    vec[i] = tmp + vec[i - 1];
	}
	
	k %= (2 * len);
	if (k <= len) {
	    for (int i = 1; i <= n; i++) {
	        if (vec[i] > k) {
	            cout << i;
	            break;
	        }
	    }
	}
	else {
	    for (int i = 1; i <= n; i++) {
	        if (vec[i] > (2 * len) - k) {
	            cout << i;
	            break;
	        }
	    }	    
	}
}