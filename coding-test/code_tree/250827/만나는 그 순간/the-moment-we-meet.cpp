#include <iostream>

using namespace std;

int n, m;
char d[1000];
int t[1000];
char d2[1000];
int t2[1000];

int a[1000001];
int b[1000001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> d[i] >> t[i];

    for (int i = 0; i < m; i++) cin >> d2[i] >> t2[i];

    // Please write your code here.
    int time1 = 1;
    for (int i = 0; i < n; i++) {
        int dir = 1;
        if (d[i] == 'L')
            dir *= -1;
        for (int j = 0; j < t[i]; j++) {
            a[time1] = a[time1 - 1] + dir;
            time1++;
        }
    }
    int time2 = 1;
    for (int i = 0; i < m; i++) {
        int dir = 1;
        if (d2[i] == 'L')
            dir *= -1;
        for (int j = 0; j < t2[i]; j++) {
            b[time2] = b[time2 - 1] + dir;
            time2++;
        }
    }

    int total = time1 < time2 ? time1 : time2;

    int res = -1;
    for (int i = 1; i < total; i++) {
        if (a[i] == b[i]) {
            res = i;
            break;
        }
    }
    cout << res;
    return 0;
}