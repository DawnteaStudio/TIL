#include <iostream>
#include <vector>
#include <climits>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res = INT_MAX;

int main() {
	fast;
    
	int n;
	cin >> n;
	vector<int> room(n);
	for (int i = 0; i < n; i++)
		cin >> room[i];

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++)
			tmp += ((j - i + 5) % 5) * room[j];
		if (res > tmp)
			res = tmp;
	}
	cout << res;
}
