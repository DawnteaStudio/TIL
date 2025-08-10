#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	cin.ignore();
	string str;
	getline(cin, str);

	int arr[26] = {0,};
	for (int i=0; i<n; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') arr[str[i] - 'a']++;
	}

	int max_cnt = 0;
	for (int i=0; i<26; i++)
		max_cnt = max(max_cnt, arr[i]);
	cout << max_cnt;
	return (0);
}