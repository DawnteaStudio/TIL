#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int T;
    cin >> T;

    int goodPower[6] = {1, 2, 3, 3, 4, 10};
    int evilPower[7] = {1, 2, 2, 2, 3, 5, 10};

    for (int tc = 1; tc <= T; tc++) {
        int goodSum = 0;
        int evilSum = 0;
        int x;

        for (int i = 0; i < 6; i++) {
            cin >> x;
            goodSum += x * goodPower[i];
        }

        for (int i = 0; i < 7; i++) {
            cin >> x;
            evilSum += x * evilPower[i];
        }

        cout << "Battle " << tc << ": ";

        if (goodSum > evilSum) {
            cout << "Good triumphs over Evil\n";
        } else if (goodSum < evilSum) {
            cout << "Evil eradicates all trace of Good\n";
        } else {
            cout << "No victor on this battle field\n";
        }
    }
}
