#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	string str;
	int res;
	for (int i = 0; i < 3; i++)
	{
		cin >> str;
		if (str == "Fizz" || str == "Buzz" || str == "FizzBuzz")
			continue;
		else
		{
			res = stoi(str) + (3 - i);
			break;
		}
	}
	if (res % 3 == 0 && res % 5 == 0)
		cout << "FizzBuzz";
	else if (res % 3 == 0)
		cout << "Fizz";
	else if (res % 5 == 0)
		cout << "Buzz";
	else
		cout << res;
}
