#include <iostream>
#include <string>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    string k, b;
    cin >> k >> b;
    int n;
    cin >> n;

    pair<int, int> k_pos = {k[0] - 'A' + 1, k[1] - '0'};
    pair<int, int> b_pos = {b[0] - 'A' + 1, b[1] - '0'};

    string m;
    for (int i = 0; i < n; i++) {
        int dx = 0, dy = 0;
        cin >> m;
        int len = m.length();
        for (int j = 0; j < len; j++) {
            switch (m[j]) {
                case 'R':
                    dx++;
                    break;
                case 'L':
                    dx--;
                    break;
                case 'B':
                    dy--;
                    break;
                case 'T':
                    dy++;
                    break;
            }
        }
        int new_x = k_pos.first + dx;
        int new_y = k_pos.second + dy;

        if (new_x < 1 || new_y < 1 || new_x > 8 || new_y > 8)
            continue;
        if (new_x == b_pos.first && new_y == b_pos.second) {
            int new_bx = b_pos.first + dx;
            int new_by = b_pos.second + dy;
            if (new_bx < 1 || new_by < 1 || new_bx > 8 || new_by > 8)
                continue;
            b_pos.first = new_bx;
            b_pos.second = new_by;
        }
        k_pos.first = new_x;
        k_pos.second = new_y;
    }
    cout << (char)(k_pos.first + 'A' - 1) << k_pos.second << '\n';
    cout << (char)(b_pos.first + 'A' - 1) << b_pos.second << '\n';
}