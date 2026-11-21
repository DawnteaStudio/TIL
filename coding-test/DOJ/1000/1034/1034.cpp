#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[5] = {5, 4, 3, 2, 1};

    int idx = 4;
    for (int i = 1; i < n; i++) {
        arr[idx]++;
        idx--;

        if (idx < 0)
            idx = 4;
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}