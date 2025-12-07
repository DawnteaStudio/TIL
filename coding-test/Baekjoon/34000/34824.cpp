#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "yonsei") {
			cout << "Yonsei Won!";
			break;
		}
		if (str == "korea") {
			cout << "Yonsei Lost...";
			break;
		}
	}	
}
