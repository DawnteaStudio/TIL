#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int total, price;
	cin >> total >> price;

	for (int i = 1; i < total; i++)
	{
		int tmp;
		cin >> tmp;
		price += tmp;
	}
	cout << price << "\n";
}