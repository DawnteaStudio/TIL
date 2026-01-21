#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int Arr[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
int arr[26] = {1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
    fast;

    string str;
	getline(cin, str);

	int len = str.length();
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			res += Arr[str[i] - 'A'];
		else if (str[i] >= 'a' && str[i] <= 'z')
			res += arr[str[i] - 'a'];
		else if (str[i] == '@')
			res++;
	}
	cout << res;
}
