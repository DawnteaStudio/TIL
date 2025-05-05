#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, m, l, input;
    cin >> n >> m >> l;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    int begin = 1;
    int end = l - 1;
    int cnt, pos_m, pos_vec;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        cnt = 0;
        pos_m = 0;
        pos_vec = 0;
        while (pos_m < l)
        {
            if (pos_vec < n)
            {
                if (pos_m + mid < vec[pos_vec])
                {
                    pos_m += mid;
                    if (pos_m >= l)
                        break;
                    cnt++;
                }
                else
                {
                    pos_m = vec[pos_vec];
                    pos_vec++;
                }
            }
            else
            {
                pos_m += mid;
                if (pos_m >= l)
                    break;
                cnt++;
            }
        }
        if (cnt <= m)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    cout << begin;
}
