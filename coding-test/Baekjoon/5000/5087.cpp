// Card Cutting
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int c, t;
	while (true) {
		c = 0, t = 0;
		string card;
		bool end = false;
		int num;
		while (true) {
			cin >> card;
			if (card == "#" || card == "*") {
				if (card == "#") end = true;
				break ;
			}
			if (card == "A") num = 1;
			else num = stoi(card);
			if (num % 2 == 0) t++;
			else c++;
		}
		if (end) break ;
		if (c > t) cout << "Cheryl\n";
		else if (c < t) cout << "Tania\n";
		else cout << "Draw\n";
	}
	return (0);
}