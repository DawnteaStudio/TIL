#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void set_array(string str, int *arr) {
	for (int i=0; i<(int)str.size(); i++) {
		if (str[i] == 'L')
            arr[0]++;
		else if (str[i] == 'O')
            arr[1]++;
		else if (str[i] == 'V')
            arr[2]++;
		else if (str[i] == 'E')
            arr[3]++;
	}
}

int rate(int *y_arr, int *t_arr) {
	int arr[4], res=1;
	for (int i=0; i<4; i++)
        arr[i] = y_arr[i] + t_arr[i];
	for (int i=0; i<3; i++) {
		for (int j=i+1; j<4; j++)
            res *= (arr[i] + arr[j]);
	}
	return res % 100;
}

int main()
{
	fast;
	string name;
	int n;
	cin >> name >> n;
	int y_arr[4] = {0};
	set_array(name, y_arr);
	string team;
	int max_rate = -1, tmp;
	string answer;
	for (int i=0; i<n; i++) {
		cin >> team;
		int t_arr[4] = {0};
		set_array(team, t_arr);
		tmp = rate(y_arr, t_arr);
		if (tmp > max_rate || tmp == max_rate && team < answer) {
			max_rate = tmp;
			answer = team;
		}
	}
	cout << answer;
}