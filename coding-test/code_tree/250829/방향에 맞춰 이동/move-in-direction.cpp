#include <iostream>

using namespace std;

int n;
int x, y;

int main() {
    cin >> n;

    char c;
    int d;
    for (int i = 0; i < n; i++) {
        cin >> c >> d;
        if (c == 'N')
            y += d;
        else if (c == 'S')
            y -= d;
        else if (c == 'E')
            x += d;
        else
            x -= d;
    }

    // Please write your code here.
    cout << x << " " << y;
    return 0;
}