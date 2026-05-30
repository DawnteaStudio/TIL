#include <iostream>

using namespace std;

int n;
int x1[10], y1[10];
int x2[10], y2[10];

int field[200][200];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i] += 100;
        y1[i] += 100;
        x2[i] += 100;
        y2[i] += 100;
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int y = y1[i]; y < y2[i]; y++) {
            for (int x = x1[i]; x < x2[i]; x++)
                field[y][x] = i % 2 + 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++)
            if (field[i][j] == 2)
                cnt++;
    }
    cout << cnt;
    return 0;
}