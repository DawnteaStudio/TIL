#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int budget;
    cin >> budget;
    int tmp = budget;
    vector<int> prices(14);
    for (int i = 0; i < 14; i++)
        cin >> prices[i];
    
    int bnp = 0, timing = budget;
    for (int i = 0; i < 14; i++) {
        if (tmp >= prices[i]) {
            while (tmp >= prices[i]) {
                tmp -= prices[i];
                bnp++;
            }
        }
    }
    bnp = tmp + bnp * prices[13];

    int upcnt = 0, downcnt = 0, cnt = 0;
    for (int i = 1; i < 14; i++) {
        if (prices[i] > prices[i - 1]) {
            upcnt++;
            downcnt = 0;
            if (upcnt == 3) {
                timing += prices[i] * cnt;
                cnt = 0;
            }

        }
        else if (prices[i] < prices[i - 1]) {
            downcnt++;
            upcnt = 0;
            if (downcnt == 3) {
                while (timing >= prices[i]) {
                    timing -= prices[i];
                    cnt++;
                }
            }
        }
    }
    timing += prices[13] * cnt;
    if (timing < bnp)
        cout << "BNP\n";
    else if (timing > bnp)
        cout << "TIMING\n";
    else
        cout << "SAMESAME\n";
}
