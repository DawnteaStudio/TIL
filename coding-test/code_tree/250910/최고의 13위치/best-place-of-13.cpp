#include <iostream>

using namespace std;

int N;
int res;
int grid[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> grid[i][j];

    // Please write your code here.

    for (int i = 0; i < N; i++) {
        int tmp;
        for (int j = 0; j < N - 2; j++) {
            tmp = 0;
            for (int k = j; k <= j + 2; k++)
                if (grid[i][k])
                    tmp++;
            if (tmp > res)
                res = tmp;
        }
    }
    cout << res;
    return 0;
}