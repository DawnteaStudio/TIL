#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, P, T;
int handshake[101];
int virus[101];

int main() {
    cin >> N >> K >> P >> T;
    vector<pair<int, pair<int, int> > > vec(T);

    for (int i = 0; i < T; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        vec[i] = {t, {a, b}};
    }
    sort(vec.begin(), vec.end());
    virus[P] = 1;

    for (int i = 0; i < T; i++) {
        int left = vec[i].second.first;
        int right = vec[i].second.second;

        int left_is_virus = 0;
        int right_is_virus = 0;
        if (virus[left] == 1) {
            if (handshake[left] < K) {
                left_is_virus = 1;
                handshake[left]++;
            }
        }
        if (virus[right] == 1) {
            if (handshake[right] < K) {
                right_is_virus = 1;
                handshake[right]++;
            }
        }
        if (left_is_virus)
            virus[right] = 1;
        if (right_is_virus)
            virus[left] = 1;
    }
    // Please write your code here.
    for (int i = 1; i <= N; i++)
        cout << virus[i];

    return 0;
}