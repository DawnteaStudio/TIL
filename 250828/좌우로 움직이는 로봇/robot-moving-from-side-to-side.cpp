#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;
int a[1000001];
int b[1000001];

int main() {
	fast;
    cin >> n >> m;

    int t;
    char d;
    int a_idx = 0, b_idx = 0;
    int a_time = 1, b_time = 1;
    for (int i = 0; i < n; i++) {
        cin >> t >> d;
        while (t--) {
            if (d == 'R')
                a[a_time++] = ++a_idx;
            else
                a[a_time++] = --a_idx;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> t >> d;
        while (t--) {
            if (d == 'R')
                b[b_time++] = ++b_idx;
            else
                b[b_time++] = --b_idx;
        }
    }

    // Please write your code here.
    int cnt = 0;
    int time = a_time > b_time ? a_time : b_time;
    int a_i, b_i;
    for (int i = 1; i <= time; i++) {
        if (a_time < i)
            a_i = a_time;
        else
            a_i = i;
        if (b_time < i)
            b_i = b_time;
        else
            b_i = i;
        if (a[a_i] == b[b_i]) {
            if (a[a_i - 1] != b[b_i - 1])
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}