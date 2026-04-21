#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	string str;
	cin >> n >> str;
	int cnt = 0;
	for (int i=0; i<n/2; i++) {
		if (str[i] != str[n-i-1])
            cnt++;
	}
	cout << cnt;
}