// 특정 대문자를 소문자로 바꾸기
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int arr[26] = {0};
	for (int i=0; i<(int)b.size(); i+=2)
		arr[b[i] - 'A'] = 1;
	for (int i=0; i<(int)a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z' && arr[a[i] - 'A'] == 1)
			a[i] += 'a' - 'A';
	}
	cout << a;
	return (0);
}