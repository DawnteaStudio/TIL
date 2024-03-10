#include <iostream>
#include <utility>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	pair<int, int> x[2] = {{0, 0}}, y[2] = {{0, 0}};
	int tmpX, tmpY, resX, resY;

	for (int i = 0; i < 3; i++)
	{
		cin >> tmpX >> tmpY;
		if (tmpX != x[0].first && tmpX != x[1].first)
		{
			if (x[0].first == 0)
			{
				x[0].first = tmpX;
				x[0].second++;
			}
			else
			{
				x[1].first = tmpX;
				x[1].second++;
			}
		}
		else
		{
			if (tmpX == x[0].first)
				x[0].second++;
			else if (tmpX == x[1].first)
				x[1].second++;
			else
			{
				x[1].first = tmpX;
				x[1].second++;
			}
		}
		if (tmpY != y[0].first && tmpY != y[1].first)
		{
			if (y[0].first == 0)
			{
				y[0].first = tmpY;
				y[0].second++;
			}
			else
			{
				y[1].first = tmpY;
				y[1].second++;
			}
		}
		else
		{
			if (tmpY == y[0].first)
				y[0].second++;
			else if (tmpY == y[1].first)
				y[1].second++;
			else
			{
				y[1].first = tmpY;
				y[1].second++;
			}
		}	
	}
	for (int i = 0; i < 2; i++)
	{
		if (x[i].second == 1)
			resX = x[i].first;
		if (y[i].second == 1)
			resY = y[i].first;
	}
	cout << resX << ' ' << resY;
}
