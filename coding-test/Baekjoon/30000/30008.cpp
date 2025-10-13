#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int getGrade(int P) {
    if (P <= 4.0)  return 1;   // 0 ≤ P ≤ 4
    if (P <= 11.0) return 2;   // 4 < P ≤ 11
    if (P <= 23.0) return 3;   // 11 < P ≤ 23
    if (P <= 40.0) return 4;   // 23 < P ≤ 40
    if (P <= 60.0) return 5;   // 40 < P ≤ 60
    if (P <= 77.0) return 6;   // 60 < P ≤ 77
    if (P <= 89.0) return 7;   // 77 < P ≤ 89
    if (P <= 96.0) return 8;   // 89 < P ≤ 96
    return 9;                  // 96 < P ≤ 100
}

int main() {
	fast;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		cout << getGrade(tmp * 100. / n) << " ";
	}
}
