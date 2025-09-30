#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string ans[9] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
int n;

int main() {
	fast;
    
    cin >> n;
    int res = 0;
    int idx = 0;
    
    int input;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            if (input > res) {
                idx = i;
                res = input;;
            }
        }

    }
    cout << ans[idx];
}
