#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 0, max_revenue = 0;
    int revenue[1000001] = {0};
    int end = 0;
    cin >> n;

    int price, cost, sell;
    for (int i = 0; i < n; i++)
    {
        cin >> price >> cost;
        if (price <= cost)
            continue;
        if (end < price)
            end = price;
        for (int j = cost + 1; j <= price; j++)
        {
            sell = j - cost;
            revenue[j] += sell;
        }
    }
    for (int i = 1; i <= end; i++)
    {
        if (revenue[i] > max_revenue)
        {
            max_revenue = revenue[i];
            res = i;
        }
    }
    cout << res;
}
