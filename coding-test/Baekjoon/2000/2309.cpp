#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    vector<int> vec(9);
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> vec[i];
        sum += vec[i];
    }
    
    int i, j;
    sum = sum - 100;
    bool done = false;
    for (i = 0; i < 8; i++) {
        for (j = i + 1; j < 9; j++) {
            if (vec[i] + vec[j] == sum) {
                done = true;
                break;
            }
        }
        if (done)
            break;
    }
    vector<int> res;

    for (int k = 0; k < 9; k++) {
        if (k == i || k == j)
            continue;
        res.push_back(vec[k]);
    }
    sort(res.begin(), res.end());
    for (int k = 0; k < 7; k++)
        cout << res[k] << '\n';
} 
