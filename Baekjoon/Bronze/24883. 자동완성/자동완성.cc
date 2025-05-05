#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	char n;

	cin >> n;
	if (n == 'N' || n == 'n') cout << "Naver D2";
	else cout << "Naver Whale";
	return (0);
}
