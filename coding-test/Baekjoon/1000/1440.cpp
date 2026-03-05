#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cnt = 0;

enum {
	HOUR=0, MIN, SEC
};

bool check(int* arr) {
	return (arr[0] && arr[1] && arr[2]);
}

void read_time(int* time, int seq, int* arr) {
	if (seq == 3) {
		if (check(arr))
            cnt++;
		return ;
	}
	if (arr[HOUR] == 0 && time[seq] >= 1 && time[seq] <= 12) {
		arr[HOUR] = 1;
		read_time(time, seq + 1, arr);
		arr[HOUR] = 0;
	}
	if (arr[MIN] == 0 && time[seq] >= 0 && time[seq] <= 59) {
		arr[MIN] = 1;
		read_time(time, seq + 1, arr);
		arr[MIN] = 0;
	}
	if (arr[SEC] == 0 && time[seq] >= 0 && time[seq] <= 59) {
		arr[SEC] = 1;
		read_time(time, seq + 1, arr);
		arr[SEC] = 0;
	}

}

int main()
{
	fast;
	string str;
    cin >> str;
	int time[3], idx = 0;
	for (int i=0; i<(int)str.size(); i+=3)
		time[idx++] = stoi(str.substr(i, 2));
	int arr[3] = {0};
	read_time(time, 0, arr);
	cout << cnt;
}