#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, len, cnt;

	string str, word, res;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		word = "";
		res = "";
		cnt = 0;
		len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (str[i] == ' ')
			{
				if (cnt == 4)
					res += "****";
				else
					res += word;
				res += " ";
				cnt = 0;
				word = "";
			}
			else
			{
				word += str[i];
				cnt++;
			}
		}
		if (word != "")
		{
			if (word.length() == 4)
				res += "****";
			else
				res += word;
		}
		cout << res << '\n';
		cout << '\n';
	}
}
