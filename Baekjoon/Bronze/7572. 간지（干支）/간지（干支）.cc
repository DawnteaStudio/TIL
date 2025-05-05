#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;
	
	string res = "";

	string arr1 = "IJKLABCDEFGH";
	string arr2 = "6789012345";
	res += arr1[n % 12];
	res += arr2[n % 10];
	cout << res;
}
