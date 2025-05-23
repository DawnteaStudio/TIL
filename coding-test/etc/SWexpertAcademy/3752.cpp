#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int arr[101];
int g_size;

int main()
{
    fast;
    int n, sum;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g_size;
        sum = 0;
        for (int j = 0; j < g_size; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        vector<bool> visited(sum + 1, false);
        vector<int> res;
        visited[0] = true;
        res.push_back(0);

        for (int j = 0; j < g_size; j++) {
            int res_cnt = res.size();
            for (int k = 0; k < res_cnt; k++) {
                if (visited[arr[j] + res[k]])
                    continue;
                res.push_back(arr[j] + res[k]);
                visited[arr[j] + res[k]] = true;
            }
        }
        cout << "#" << i << " " << res.size() << '\n';
    }

}
