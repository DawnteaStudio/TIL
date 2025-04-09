#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;

	string s;
	int day, month, year;

	int min_year = 9999, max_year = 0;
	int min_month = 13, max_month = 0;
	int min_day = 32, max_day = 0;

	string min_name, max_name;
	for (int i = 0; i < n; i++) {
		cin >> s >> day >> month >> year;
		if (year < min_year) {
			min_year = year;
			min_month = month;
			min_day = day;
			min_name = s;
		}
		else if (year == min_year) {
			if (month < min_month) {
				min_month = month;
				min_day = day;
				min_name = s;
			}
			else if (month == min_month) {
				if (day < min_day) {
					min_day = day;
					min_name = s;
				}
			}
		}
		if (year > max_year) {
			max_year = year;
			max_month = month;
			max_day = day;
			max_name = s;
		}
		else if (year == max_year) {
			if (month > max_month) {
				max_month = month;
				max_day = day;
				max_name = s;
			}
			else if (month == max_month) {
				if (day > max_day) {
					max_day = day;
					max_name = s;
				}
			}
		}
	}
	cout << max_name << '\n' << min_name << '\n';
}
