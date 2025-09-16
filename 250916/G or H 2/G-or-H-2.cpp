#include <iostream>

using namespace std;

int N;
int pos[101];

int main() {
    cin >> N;
    int p, res = 0;
    int max_ = 0;
    char c;

    for (int i = 0; i < N; i++) {
        cin >> p >> c;
        if (c == 'G')
            pos[p] = 1;
        else
            pos[p] = 2;
        if (p > max_)
            max_ = p;
    }

    // Please write your code here.
    for (int size = max_; size >= 0; size--) {
        for (int i = 0; i <= 100 - size; i++) {
            int g = 0, h = 0;
            if (pos[i] == 0 || pos[i + size] == 0)
                continue;
            for (int j = i; j <= i + size; j++) {
                if (pos[j] == 1)
                    g++;
                else if (pos[j] == 2)
                    h++;
            }
            if (g == 0 || h == 0) {
                res = size;
                break;
            }
            else if (g == h) {
                res = size;
                break;
            }
        }
        if (res != 0)
            break;
    }
    cout << res;
    return 0;
}