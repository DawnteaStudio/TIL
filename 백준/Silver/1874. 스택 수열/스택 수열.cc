#include <iostream>
#include <stack>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, tmp;
	cin >> n;

	stack<int> s;
	string str = "";
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (idx < tmp) {
			for (int j = idx + 1; j <= tmp; j++) {
				str += "+\n";
				s.push(j);
			}
			idx = tmp;
			s.pop();
			str += "-\n";
		}
		else {
			if (tmp != s.top()) {
				str = "NO";
				break;
			}
			str += "-\n";
			s.pop();
		}
	}
	cout << str;
}
