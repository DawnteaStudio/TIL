#include <iostream>

using namespace std;

int N, M;
int a[1000001];
int b[1000001];

int main() {
    cin >> N >> M;

    int v, t;
    int t_a = 1, t_b = 1;
    for (int i = 0; i < N; i++) {
        cin >> v >> t;

        while (t--) {
            a[t_a] = a[t_a - 1] + v;
            t_a++;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> v >> t;
        while (t--) {
            b[t_b] = b[t_b - 1] + v;
            t_b++;
        } 
    }

    // Please write your code here.

    int status = 0;
    int cnt = 0;
    for (int i = 1; i < t_a; i++) {
        if (status == 0) {
            if (a[i] > b[i]) {
                status = 1;
                cnt++;
            }
            else if (a[i] < b[i]) {
                status = 2;
                cnt++;
            }
        }
        else if (status == 1) {
            if (a[i] == b[i]) {
                status = 0;
                cnt++;
            }
            else if (a[i] < b[i]) {
                status = 2;
                cnt++;
            }
        }
        else {
            if (a[i] == b[i]) {
                status = 0;
                cnt++;
            }
            else if (a[i] > b[i]) {
                status = 1;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}