#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int s, t, d;
    cin >> s >> t >> d;

    cout << t * (d / (s * 2));
}
