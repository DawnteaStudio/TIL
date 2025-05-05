#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, q, tmp;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (i == 0)
            arr[i] = tmp;
        else
            arr[i] = arr[i - 1] + tmp;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            if (tmp < arr[j])
            {
                cout << j + 1 << '\n';
                break;
            }
        }
    }
}
