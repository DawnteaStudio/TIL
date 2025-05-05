#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(string &s1, string &s2)
{
	string s1_name[2], s2_name[2];

	size_t tmp = s1.find(' ');
	s1_name[0] = s1.substr(0, tmp);
	s1_name[1] = s1.substr(tmp + 1);

	tmp = s2.find(' ');
	s2_name[0] = s2.substr(0, tmp);
	s2_name[1] = s2.substr(tmp + 1);

	if (s1_name[1] != s2_name[1]) return s1_name[1] < s2_name[1];
	return s1_name[0] < s2_name[0];
}

int main()
{
	fast;
	int n; cin >> n;
	cin.ignore();

	string arr[n];
	for (int i=0; i<n; i++) getline(cin, arr[i]);
	sort(arr, arr+n, cmp);
	for (int i=0; i<n; i++) cout << arr[i] << '\n';
	return (0);
}