#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    vector<int> vec;
    vector<pair<int, int> > ans;
    int input, res = 0;
    while (cin >> input) {
        vec.push_back(input);
    }

    int size = vec.size() - 1;
    int target = vec[size];

    sort(vec.begin(), vec.end() - 1);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (vec[i] + vec[j] == target) {
                if (find(ans.begin(), ans.end(), make_pair(vec[i], vec[j])) == ans.end()) {
                    ans.push_back(make_pair(vec[i], vec[j]));
                    res++;
                }
            }
        }
    }
    int cnt = ans.size();
    for (int i = 0; i < cnt; i++)
        cout << ans[i].first << " " << ans[i].second << '\n';
    cout << res;
}