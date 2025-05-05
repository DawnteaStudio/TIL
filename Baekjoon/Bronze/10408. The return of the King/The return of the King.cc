#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int cnt = 0, sum = 0, tmp = 0;
	double res;

	string input;
	cin >> input;
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (input[i] == '0')
		{
			sum += tmp * 10;
			tmp = 0;
		}
		else
		{
			if (tmp > 0)
				sum += tmp;
			tmp = input[i] - '0';
			if (i == input.length() - 1)
				sum += tmp;
			cnt++;
		}
	}
	cout.precision(2);
	cout << fixed;
	res = static_cast<double>(sum) / cnt;
	cout << res;
}
