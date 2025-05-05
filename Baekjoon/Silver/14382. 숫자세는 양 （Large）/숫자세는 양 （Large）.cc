#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long goto_sleep(long long tmp)
{
	bool	nums[10] = {false};
	long long num = tmp;
	int	done = 0;

	while (done != 10)
	{
		string str = to_string(num);
		for (int i = 0; i < str.length(); i++)
		{
			if (nums[str[i] - '0'] == false)
			{
				nums[str[i] - '0'] = true;
				done++;
			}
		}
		if (done != 10)
			num += tmp;
		else break;
	}
	return num;
}

int main()
{
	fast;
	int n;
	long long tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == 0)
			cout << "Case #" << i + 1 << ": INSOMNIA\n";
		else
			cout << "Case #" << i + 1 << ": " << goto_sleep(tmp) << '\n';
	}
}