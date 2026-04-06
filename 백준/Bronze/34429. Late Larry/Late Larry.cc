#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
string timeStr, meridiem;
    cin >> timeStr >> meridiem;

    int late;
    cin >> late;

    int colon = timeStr.find(':');
    int hour = stoi(timeStr.substr(0, colon));
    int minute = stoi(timeStr.substr(colon + 1));

    int total = 0;
    if (meridiem == "AM") {
        if (hour == 12) hour = 0;
        total = hour * 60 + minute;
    } else { // PM
        if (hour != 12) hour += 12;
        total = hour * 60 + minute;
    }

    total -= late;
    if (total < 0) total += 1440;

    int newHour24 = total / 60;
    int newMinute = total % 60;

    string resultMeridiem = (newHour24 < 12 ? "AM" : "PM");

    int newHour12 = newHour24 % 12;
    if (newHour12 == 0) newHour12 = 12;

    cout << newHour12 << ':';
    if (newMinute < 10) cout << '0';
    cout << newMinute << ' ' << resultMeridiem << '\n';

}
