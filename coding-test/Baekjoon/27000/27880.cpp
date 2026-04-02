#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	int num, sum = 0;
	for (int i=1; i<=4; i++) {
		cin >> str >> num;
		if (str == "Es")
            sum += num * 21;
		else
            sum += num * 17;
	}
	cout << sum;
}