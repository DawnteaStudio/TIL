#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int area;
	bool solve = false;

	cin >> area;

	int x = 0, y, tmpX, tmpY;
	double centerX, centerY;

	while (x <= area)
	{
		for (y = 0; y <= area; y++)
		{
			if (x * x + y * y == 2 * area)
			{
				solve = true;
				break;
			}
		}
		if (solve)
		{
			centerX = x / 2.;
			centerY = y / 2.;
			break;
		}
		x++;
	}
	if (solve)
	{
		tmpX = x;
		tmpY = y;
		cout << x << " " << y << '\n';
		x = -(tmpY - centerY) + centerX; 
		y = (tmpX - centerX) + centerY;
		tmpX = x;
		tmpY = y;
		cout << x << " " << y << '\n';
		x = -(tmpY - centerY) + centerX;
		y = (tmpX - centerX) + centerY;
		tmpX = x;
		tmpY = y;
		cout << x << " " << y << '\n';
		x = -(tmpY - centerY) + centerX;
		y = (tmpX - centerX) + centerY;
		cout << x << " " << y << '\n';
	}
	else
		cout << "Impossible";
}
