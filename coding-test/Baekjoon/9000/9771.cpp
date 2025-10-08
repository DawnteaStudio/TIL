#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string target; cin >> target;
	string str;
	int cnt = 0;
	while (getline(cin, str)) {
		size_t idx = 0;
		while (true) {
			idx = str.find(target, idx);
			if (idx == string::npos) break ;
			cnt++;
			idx++;
		}
	}
	cout << cnt;
	return (0);
}