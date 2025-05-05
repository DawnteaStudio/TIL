#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	cin >> str;
	string s_year = "", s_month = "", s_date = "";
	for (int i = 0; i < 10; i++)
	{
		if (i < 4)
			s_year += str[i];
		else if (i > 4 && i < 7)
			s_month += str[i];
		else if (i > 7)
			s_date += str[i];
	}
	int year, month, date;
	year = stoi(s_year);
	month = stoi(s_month);
	date = stoi(s_date);

	if (year > 2023)
		cout << "TOO LATE";
	else if (year == 2023)
	{
		if (month > 9)
			cout << "TOO LATE";
		else if (month == 9)
		{
			if (date > 16)
				cout << "TOO LATE";
			else
				cout << "GOOD";
		}
		else
			cout << "GOOD";
	}
	else
		cout << "GOOD";
}
