#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int kcal, fat, car, pro;
	int max_total, min_total;

	while (true)
	{
		cin >> kcal >> fat >> car >> pro;
		if (kcal == 0 && fat == 0 && car == 0 && pro == 0)
			break;
		max_total = fat * 9 + car * 4 + pro * 4 + 8;
		min_total = fat * 9 + car * 4 + pro * 4;
		if (fat != 0)
			min_total -= 4;
		if (car != 0)
			min_total -= 2;
		if (pro != 0)
			min_total -= 2;
		if (min_total <=  kcal && kcal <= max_total)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
