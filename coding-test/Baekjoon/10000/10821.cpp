#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string num; cin >> num;
	string::size_type idx = 0;
	int cnt=0;
	while (true) {
		string::size_type pos = num.find(',', idx);
		cnt++;
		if (pos == string::npos) break ;
		idx = pos + 1;
	}
	cout << cnt;
	return (0);
}
