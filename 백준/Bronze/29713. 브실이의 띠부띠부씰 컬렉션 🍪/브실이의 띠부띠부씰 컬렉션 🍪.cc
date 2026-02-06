#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_max_cnt(int n, int *arr) {
	string target = "BRONZESILVER";
	int size = (int)target.size(), cnt = 0;
	while (true) {
		for (int i=0; i<size; i++) {
			bool flag = false;
			for (int j=0; j<26; j++) {
				if (arr[target[i] - 'A'] != 0)
				{
					arr[target[i] - 'A']--;
					flag = true;
					break ;
				}
			}
			if (!flag)
                return cnt;
		}
		cnt++;
	}
}

int main()
{
	fast;
	int n;
    cin >> n;
	string str;
    cin >> str;
	int arr[26] = {0};
	for (int i=0; i<n; i++)
        arr[str[i] - 'A']++;
	cout << find_max_cnt(n, arr);
	return (0);
}