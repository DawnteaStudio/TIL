#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long c;
    cin >> n >> c;

    int total_area = 0;
    int bedroom_area = 0;
    int balcony_area = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        string t;
        cin >> a >> t;

        total_area += a;

        if (t == "bedroom") {
            bedroom_area += a;
        } else if (t == "balcony") {
            balcony_area += a;
        }
    }

    double reduced_area = total_area - (balcony_area * 0.5);
    double cost = reduced_area * c;

    cout << total_area << "\n";
    cout << bedroom_area << "\n";
    cout << fixed << setprecision(6) << cost << "\n";

    return 0;
}