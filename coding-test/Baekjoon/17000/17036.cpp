#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, idx = 0;
    int max_cluster = 1;
    bool empty = false;
    cin >> n;
    vector<int> vec(n);
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for (int i = 1; i < n; i++)
        diff[i] = vec[i] - vec[i - 1] - 1;

    for (int i = 0; i < n; i++) {
        if (idx >= n)
            break;
        for (;idx < n; idx++) {
            if (i == idx)
                continue;
            if (vec[idx] - vec[i] >= n)
                break;
        }
        if (idx - i > max_cluster) {
            max_cluster = idx - i;
            if (vec[idx - 1] - vec[i] + 1 != max_cluster)
                empty = true;
            else
                empty = false;
        }
        else if (idx - i == max_cluster) {
            if (!empty) {
                if (vec[idx - 1] - vec[i] + 1 != max_cluster)
                    empty = true;
            }
        }
    }
    int min_value = n - max_cluster;
    if (!empty && min_value == 1)
        min_value++;
    int max_value = 0;
    for (int i = 1; i < n; i++)
        max_value += diff[i];
    if (max_value != 0) {
        max_value -= (diff[1] > diff[n - 1] ? diff[n - 1] : diff[1]);
    }
    cout << min_value << "\n" << max_value;
}