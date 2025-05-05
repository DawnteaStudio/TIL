#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, tmp;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	tmp = vec[0];
	cout << tmp << " ";
	for (int i = 1; i < n; i++)
	{
		if (tmp == vec[i])
			continue;
		tmp = vec[i];
		cout << tmp << " ";
	}
}
