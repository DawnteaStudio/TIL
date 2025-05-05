#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	int g, b;
	cin >> n;
	string str;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		g = 0;
		b = 0;
		getline(cin, str);
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'g' || str[j] == 'G')
				g++;
			else if (str[j] == 'b' || str[j] == 'B')
				b++;
		}
		cout << str << " is ";
		if (g > b)
			cout << "GOOD\n";
		else if (b > g)
			cout << "A BADDY\n";
		else
			cout << "NEUTRAL\n";
	}
}
