#include <iostream>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string digits;
	cin >> digits;

	if (digits.length() != 7 || !all_of(digits.begin(), digits.end(), ::isdigit))
	{
		cout << "Invalid input\n";
		return 1;
	}

	int weights[7] = {2, 7, 6, 5, 4, 3, 2};
	char map[11] = {'J', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'Z'};

	int sum = 0;
	for (int i = 0; i < 7; ++i)
	{
		sum += (digits[i] - '0') * weights[i];
	}

	int remainder = sum % 11;
	cout << map[remainder] << '\n';
}