#include <iostream>

using namespace std;

int abilities[6];
int sum;
int res = 6000000;

void solve(int i, int j, int k)
{
    int tmp = abilities[i] + abilities[j] + abilities[k];
    int diff = tmp - sum;
    if (diff < 0)
        diff *= -1;
    
    int r = tmp - diff;
    if (r < 0)
        r *= -1;
    if (res > r)
        res = r;
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
        sum += abilities[i];
    }
    // Please write your code here.
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 6; k++) {
                solve(i, j, k);
            }
        }
    }
    cout << res;
    return 0;
}