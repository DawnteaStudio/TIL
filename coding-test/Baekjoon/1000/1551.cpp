#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void make_arr(int n, vector<int>& arr) {
	vector<int> res;
	for (int i=0; i<n-1; i++)
		res.push_back(arr[i + 1] - arr[i]);
	arr = res;
}

int main()
{
	fast;
	int n, k;
    cin >> n >> k;
	string str;
    cin >> str;
	vector<int> arr;
	int idx = 0, pos;
	while (true) {
		pos = str.find(',', idx);
		if (pos != string::npos) {
			arr.push_back(stoi(str.substr(idx, pos - idx)));
			idx = pos + 1;
		}
		else {
			arr.push_back(stoi(str.substr(idx)));
			break ;
		}
	}

	for (int i=0; i<k; i++)
		make_arr(n - i, arr);
	for (int i=0; i<n-k; i++)
	{
		cout << arr[i];
		if (i < n-k-1) cout << ',';
	}
}