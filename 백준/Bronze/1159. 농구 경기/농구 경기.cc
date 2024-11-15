#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	cin >> n;
	bool flag = true;

	string input;
	vector<int> vec(26, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		vec[input[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (vec[i] >= 5)
		{
			cout << static_cast<char>(i + 'a');
			flag = false;
		}
	}
	if (flag)
		cout << "PREDAJA";
}
