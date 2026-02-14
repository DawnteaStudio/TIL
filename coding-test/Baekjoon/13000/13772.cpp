#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
    cin >> n;
	cin.clear();
	cin.ignore();
	string str;
	int hole[] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i=0; i<n; i++) {
		getline(cin, str);
		int sum = 0;
		for (int j=0; j<(int)str.size(); j++) {
			if (str[j] != ' ')
                sum += hole[str[j] - 'A'];
		}
		cout << sum << '\n';
	}
}