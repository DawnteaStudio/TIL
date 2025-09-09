#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int n, res = INT_MAX;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++)
            tmp += A[j] * abs(i - j);
        if (res > tmp)
            res = tmp;
    }

    cout << res;
    return 0;
}