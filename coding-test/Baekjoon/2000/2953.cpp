#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int winner, score = 0, tmp, input;
    for (int i = 1; i <= 5; i++)
    {
        tmp = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> input;
            tmp += input;
        }
        if (tmp > score)
        {
            winner = i;
            score = tmp;
        }
    }
    cout << winner << " " << score;
}
