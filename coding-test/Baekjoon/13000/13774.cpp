#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	string imp = "not possible";

	string tmp;
	while (true) {
		cin >> tmp;
		if (tmp == "#")
			break;

		int len = tmp.length();

		string chk;
		bool flag;
		for (int i = 0; i < len; i++) {
			chk = tmp.substr(0, i);
			flag = true;
			if (i != len - 1)
				chk += tmp.substr(i + 1);

			int start = 0, end = len - 2;
			while (start <= end) {
				if (chk[start] != chk[end]) {
					flag = false;
					break;
				}
				start++;
				end--;
			}
			if (flag) {
				cout << chk << '\n';
				break;
			}
		}
		if (flag == false)
			cout << imp << '\n';
	}
}
