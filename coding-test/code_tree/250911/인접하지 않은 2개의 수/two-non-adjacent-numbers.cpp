#include <iostream>

using namespace std;

int n, res;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Please write your code here.

    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            int tmp = numbers[i] + numbers[j];
            if (tmp > res)
                res = tmp;
        }
    }
    cout << res;

    return 0;
}