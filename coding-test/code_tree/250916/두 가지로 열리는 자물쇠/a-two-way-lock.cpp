#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;

int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    int res = 0;

    // Please write your code here.

    for (int i = 1; i <= N; i++) {
        bool one = true, two = true;
        if (abs(i - a1) > 2 && N - abs(i - a1) > 2)
            one = false;
        if (abs(i - a2) > 2 && N - abs(i - a2) > 2)
            two = false;
        if (one == false && two == false)
            continue;
        for (int j = 1; j <= N; j++) {
            bool j_one = one;
            bool j_two = two;
            if (abs(j - b1) > 2 && N - abs(j - b1) > 2)
                j_one = false;
            if (abs(j - b2) > 2 && N - abs(j - b2) > 2)
                j_two = false;
            if (j_one == false && j_two == false)
                continue;
            for (int k = 1; k <= N; k++) {
                bool k_one = j_one;
                bool k_two = j_two;
                if (abs(k - c1) > 2 && N - abs(k - c1) > 2)
                    k_one = false;
                if (abs(k - c2) > 2 && N - abs(k - c2) > 2)
                    k_two = false;
                if (k_one == false && k_two == false)
                    continue;
                res++;
            }
        }
    }
    cout << res;
    return 0;
}