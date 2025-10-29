#include <iostream>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct Bridge {
    int total_w;
    queue<pair<int, int> > q;
};

int main()
{
    fast;
    int n, w, l, tmp;
    cin >> n >> w >> l;

    queue<int> truck;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        truck.push(tmp);
    }

    int t = 0;
    
    Bridge bridge;
    bridge.total_w = 0;

    while (!bridge.q.empty() || !truck.empty()) {
		t++;
        if (!bridge.q.empty() && bridge.q.front().second + w == t) {
            bridge.total_w -= bridge.q.front().first;
            bridge.q.pop();
        }

        if (!truck.empty() && bridge.total_w + truck.front() <= l) {
            if (bridge.q.size() < w) {
                bridge.q.push({truck.front(), t});
                bridge.total_w += truck.front();
                truck.pop();
            }
        }
    }
    cout << t;
}
