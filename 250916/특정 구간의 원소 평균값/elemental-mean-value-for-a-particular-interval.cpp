#include <iostream>
using namespace std;

int arr[101];

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++)
            sum += arr[j];
        if (sum > res)
            res = sum;
    }
    cout << res;
    return 0;
}