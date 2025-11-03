#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, S;
    cin >> n >> S;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    int s = 0, e = n - 1;
    int total = 0;

    while (s < e) {
        while (vec[s] + vec[e] > S) {
            e--;
            if (s == e)
                break;
        }
        total += e - s;
        s++;
    }
    cout << total;
}
