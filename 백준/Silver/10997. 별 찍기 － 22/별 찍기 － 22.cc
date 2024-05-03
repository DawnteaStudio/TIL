#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define LEFT 0
#define RIGHT 1
#define UP 3
#define DOWN 4

int main()
{
	fast;
	int	n, x, y, max_x, max_y, cnt = 0;
	int goal_x, goal_y;
	int	dir = LEFT;
	cin >> n;
	if (n == 1)
	{
		cout << "*";
		return (0);
	}
	int width = 4 * n - 3;
	int height = 4 * n - 1;

	int	arr[height][width];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			arr[i][j] = 0;
	}

	max_y = height;
	max_x = width;
	y = 0;
	x = width - 1;
	goal_y = height / 2 + 1;
	goal_x = width / 2;
	arr[goal_y][goal_x] = 1;
	while (x != goal_x || y != goal_y)
	{
		arr[y][x] = 1;
		if (dir == LEFT)
		{
			x--;
			cnt++;
			if (cnt == max_x)
			{
				cnt = 0;
				x++;
				dir = DOWN;
				if (y != 0)
					max_x -= 2;
			}
		}
		else if (dir == RIGHT)
		{
			x++;
			cnt++;
			if (cnt == max_x)
			{
				cnt = 0;
				x--;
				max_x -= 2;
				dir = UP;
			}
		}
		else if (dir == DOWN)
		{
			y++;
			cnt++;
			if (cnt == max_y)
			{
				cnt = 0;
				y--;
				max_y -= 2;
				dir = RIGHT;
			}
		}
		else
		{
			y--;
			cnt++;
			if (cnt == max_y)
			{
				cnt = 0;
				y++;
				max_y -= 2;
				dir = LEFT;
			}
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = width - 1; j >= 0; j--)
		{
			if (arr[i][j] == 0)
				arr[i][j] = -1;
			else
				break;
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (arr[i][j] == 1)
				cout << "*";
			else if (arr[i][j] == 0)
				cout << " ";
			else
				break;
		}
		cout << '\n';
	}
}
