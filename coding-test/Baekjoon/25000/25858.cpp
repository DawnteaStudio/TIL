#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, q, total = 0, input;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> input;
        total += input;
        arr[i] = input;
    }
    int prize = q / total;
    for (int i = 0; i < n; i++) {
        cout << arr[i] * prize << "\n";
    }
}