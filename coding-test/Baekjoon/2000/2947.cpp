#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	string res;
	for (int i = 0; i < 5; i++) {
		char tmp;
		cin >> tmp;
		res += tmp;
	}
	
	int idx = 0;
	while (res != "12345") {
		if (idx == 4)
			idx = 0;
		
		if (res[idx] > res[idx + 1]) {
			char tmp = res[idx];
			res[idx] = res[idx + 1];
			res[idx + 1] = tmp;
			for (int i = 0; i < 5; i++)
				cout << res[i] << " ";;
			cout << '\n';
		}
		idx++;
	}
}
