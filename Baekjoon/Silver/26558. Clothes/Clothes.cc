#include <iostream>
#include <stack>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n;

	stack<string> shirt;
	stack<string> pants;
	stack<string> socks;

	string input;
	string category;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin.ignore();
		for (int j = 0; j < n; j++) {
			getline(cin, input);
			int index = input.find('(');
			category = input.substr(index + 1, 5);
			input = input.substr(0, input.find('(') - 1);
			if (category == "pants")
				pants.push(input);
			else if (category == "shirt")
				shirt.push(input);
			else
				socks.push(input);
		}
		while (!socks.empty() && !pants.empty() && !shirt.empty()) {
			cout << shirt.top() << ", " << pants.top() << ", " << socks.top() << "\n";
			shirt.pop();
			pants.pop();
			socks.pop();
		}
		cout << '\n';
		while (!socks.empty() || !pants.empty() || !shirt.empty()) {
			if (!socks.empty())
				socks.pop();
			if (!shirt.empty())
				shirt.pop();
			if (!pants.empty())
				pants.pop();
		}
	}
}
