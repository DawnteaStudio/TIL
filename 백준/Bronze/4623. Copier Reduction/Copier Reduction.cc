#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	double x, y, size_x, size_y;
	double percent_x, percent_y;
	int per;
	while (true)
	{
		cin >> x >> y >> size_x >> size_y;
		if (x == 0)
			break;
		if (x > y)
		{
			if (size_x > size_y)
			{
				percent_x = size_x / x;
				percent_y = size_y / y;
			}
			else
			{
				percent_x = size_y / x;
				percent_y = size_x / y;
			}
		}
		else
		{
			if (size_x > size_y)
			{
				percent_x = size_y / x;
				percent_y = size_x / y;
			}
			else
			{
				percent_x = size_x / x;
				percent_y = size_y / y;
			}
		}
		per = (percent_x < percent_y ? percent_x : percent_y) * 100;
		if (per > 100)
			cout << "100%\n";
		else
			cout << per << "%\n";
	}
}