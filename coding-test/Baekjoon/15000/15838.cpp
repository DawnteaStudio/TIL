#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, chicken, beef, lamb, nasi;
    int index = 1;
    double profit_c, profit_b, profit_l, profit_n, profit;

    cout << fixed;
    cout.precision(2);
    profit_c = 0.8 - (15.5 / 85.0);
    profit_b = 1.0 - (32.0 / 85.0);
    profit_l = 1.2 - (40.0 / 85.0);
    profit_n = 0.6;
    while (true)
    {
        cin >> n;
        profit = 0;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> chicken >> beef >> lamb >> nasi;
            profit += chicken * profit_c + beef * profit_b + lamb * profit_l + nasi * profit_n;         
        }
        cout << "Case #" << index <<": RM" << profit << '\n';
        index++;
    }
}
