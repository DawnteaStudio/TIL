#include <iostream>
using namespace std;

int arr[101];

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int res = n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            int sum = 0;
            for (int k = 0; k <= j; k++) {
                sum += arr[i + k];
            }
            int avg = sum / (j + 1);
            if (sum % (j + 1) == 0) {
                for (int t = i; t <= i + j; t++) {
                    if (arr[t] == avg) {
                        res++;
                        break;
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}