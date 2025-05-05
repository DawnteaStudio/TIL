#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    double w, h, bmi;

    cin >> w >> h;
    bmi = w / (h * h);
    if (bmi < 18.5) cout << "Underweight";
    else if (bmi < 25) cout << "Normal weight";
    else cout << "Overweight";
    return (0);
}