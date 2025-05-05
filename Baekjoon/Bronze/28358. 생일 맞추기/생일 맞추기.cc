#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void	fill(vector<bool> &days)
{
	for (int j = 1; j <= 31; j++)
		days[j] = true;
}

int main() {
	fast;
	int n, d;
	string str;
	cin >> n;

	vector<vector<bool> > days(13, vector<bool>(32, false));
	bool	remove_month[13];
	int		arr[10];
	int		len[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (int i = 0; i < n; i++)
	{
		d = 366;
		for (int j = 1; j <= 12; j++)
		{
			fill(days[j]);
			remove_month[j] = false;
		}
		for (int j = 0; j < 10; j++)
		{
			cin >> arr[j];
			if (arr[j] == 1)
			{
				if (j == 0)
					remove_month[10] = true;
				else if (j == 1)
				{
					remove_month[1] = true;
					remove_month[10] = true;
					remove_month[11] = true;
					remove_month[12] = true;
				}
				else if (j == 2)
				{
					remove_month[2] = true;
					remove_month[12] = true;
				}
					remove_month[j] = true;
			}
		}
		for (int j = 1; j <= 12; j++)
		{
			if (remove_month[j] == true)
				d -= len[j];
		}
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] == 1)
			{
				for (int k = 1; k <= 12; k++)
				{
					if (remove_month[k] == false)
					{
						for (int p = 1; p <= len[k]; p++)
						{
							if (days[k][p] == true)
							{
								str = to_string(p);
								for (int w = 0; w < str.length(); w++)
								{
									if ((int)str[w] == j + '0')
									{
										d--;
										days[k][p] = false;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
		cout << d << '\n';
	}
}
