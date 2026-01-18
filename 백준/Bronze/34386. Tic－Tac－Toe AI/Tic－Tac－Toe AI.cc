#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool win(const vector<string>& b, char p) {
    for (int r = 0; r < 3; r++) {
        if (b[r][0] == p && b[r][1] == p && b[r][2] == p)
			return true;
    }
    for (int c = 0; c < 3; c++) {
        if (b[0][c] == p && b[1][c] == p && b[2][c] == p)
			return true;
    }
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p)
		return true;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p)
		return true;
    return false;
}

int main() {
    fast;

    char p;
    cin >> p;

    vector<string> b(3);
    for (int i = 0; i < 3; i++) cin >> b[i];

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (b[r][c] != 'E')
				continue;

            b[r][c] = p;
            if (win(b, p)) {
                cout << (r + 1) << ' ' << (c + 1) << '\n';
                return 0;
            }
            b[r][c] = 'E';
        }
    }
}
