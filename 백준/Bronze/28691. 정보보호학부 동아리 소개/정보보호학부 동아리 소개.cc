#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	char c;

	cin >> c;
	if (c == 'M') cout << "MatKor";
	else if (c == 'W') cout << "WiCys";
	else if (c == 'C') cout << "CyKor";
	else if (c == 'A') cout << "AlKor";
	else if (c == '$') cout << "$clear";
	return (0);
}