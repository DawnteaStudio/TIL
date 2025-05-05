#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = 0;
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = (arr[i - 1] + (2 * arr[i - 2])) % 10007;
    cout << arr[n];
}