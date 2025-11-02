#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	int max_money = 0;
	for (int i=0; i<n; i++) {
		int result=0, dice, num[6] = {0}, max_dice=0;
		for (int j=0; j<4; j++) {
			cin >> dice;
			max_dice = max(max_dice, dice);
			num[dice - 1]++;
		}

		int tmp = 0;
		for (int j=0; j<6; j++) {
			if (num[j] == 4) result = 50000 + (j + 1) * 5000;
			else if (num[j] == 3) result = 10000 + (j + 1) * 1000;
			else {
				if (num[j] == 2) {
					if (tmp == 0) tmp = j + 1;
					else result = 2000 + tmp * 500 + (j + 1) * 500;
				}
				continue ;
			}
			break ;
		}
		if (result == 0) {
			if (tmp != 0) result = 1000 + tmp * 100;
			else result = max_dice * 100;
		}
		max_money = max(max_money, result);
	}
	cout << max_money;
	return (0);
}