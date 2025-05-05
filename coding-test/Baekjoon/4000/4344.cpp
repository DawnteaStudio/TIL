#include <iostream>
#include <cmath>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    int n;
    cin >> n;

    int stu, sum, score;
    for (int i = 0; i < n; i++) {
        sum = 0;
        cin >> stu;
        vector<int> scores(stu);
        for (int j = 0; j < stu; j++) {
            cin >> scores[j];
            sum += scores[j];
        }
        double avg = static_cast<double>(sum) / stu;
        int count = 0;
        for (int j = 0; j < stu; j++) {
            if (scores[j] > avg)
                count++;
        }
        double percentage = static_cast<double>(count) / stu * 100;
        cout << fixed;
        cout.precision(3);
        cout << percentage << "%\n";
    }
}
