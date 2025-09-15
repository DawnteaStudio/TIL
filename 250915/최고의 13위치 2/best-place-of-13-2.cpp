#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N, res;
int arr[20][20];

int main() {
	fast;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    int tmp1, tmp2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            tmp1 = 0;
            for (int k = 0; k < 3; k++) {
                if (arr[i][j + k] == 1)
                    tmp1++;
            }

            for (int ii = i; ii < N; ii++) {
                for (int jj = 0; jj < N - 2; jj++) {
                    if (jj >= j - 2 && jj <= j + 2 && ii == i)
                        continue;
                    tmp2 = 0;
                    for (int k = 0; k < 3; k++) {
                        if (arr[ii][jj + k] == 1)
                            tmp2++;
                    }
                    if (res < tmp1 + tmp2)
                        res = tmp1 + tmp2;
                }
            }
        }
    }

    cout << res;
}
