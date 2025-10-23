#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	int len = vec.size();
	if (len % 2 == 0)
		cout << vec[0] * vec[len - 1];
	else
		cout << vec[len / 2] * vec[len / 2];
}
