#include <algorithm>
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void) {
    fast;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> vec(20);
        for (int j = 0; j < 20; j++)
			cin >> vec[j];

        for (int j = 19; j >= 1; j--) {
            vec[j - 1] += vec[j] / 2;
            vec[j] = vec[j] % 2;
        }
        for (int j = 0; j < 20; j++)
			cout << vec[j] << " ";
		cout << '\n';
    }
}