#include <iostream>
#include <sstream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool	getLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
			return true;
	}
	return false;
}

void	seperate(int &year, int &month, int &day, bool &leapyear, string &str)
{
	string token;
	stringstream ss;
	ss.str(str);
	int i = 0;

	while (getline(ss, token, '-'))
	{
		switch (i)
		{
			case 0:
				year = stoi(token);
				leapyear = getLeapYear(year);
				break;
			case 1:
				month = stoi(token);
				break;
			case 2:
				day = stoi(token);
				break;
			default:
				break;
		}
		i++;
	}
}

int	getMaxday(bool leapyear, int month)
{
	if (month == 2)
	{
		if (leapyear)
			return 29;
		else
			return 28;
	}
	if (month < 8)
	{
		if (month % 2 != 0)
			return 31;
		return 30;
	}
	else
	{
		if (month % 2 == 0)
			return 31;
		return 30;
	}
}

int main() {
	fast;
	int n, year, month, day, dday= 1;
	int maxDay;
	bool leapyear = false;
	string str;
	cin >> str >> n;

	seperate(year, month, day, leapyear, str);
	maxDay = getMaxday(leapyear, month);
	while (dday < n)
	{
		day++;
		if (day > maxDay)
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
				leapyear = getLeapYear(year);
			}
			maxDay = getMaxday(leapyear, month);
		}
		dday++;
	}
	cout << year << "-";
	if (month < 10)
		cout << "0";
	cout << month << "-";
	if (day < 10)
		cout << "0";
	cout << day;
}
