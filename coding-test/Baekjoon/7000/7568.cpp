#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct human
{
    int cm;
    int kg;
    int rank;
};

int main() {
    fast;
    int n, cm, kg, rank;
    cin >> n;

    vector<human> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cm >> kg;
        vec[i].cm = cm;
        vec[i].kg = kg;
    }
    for (int i = 0; i < n; i++)
    {
        rank = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (vec[i].cm < vec[j].cm && vec[i].kg < vec[j].kg)
                rank++;
        }
        vec[i].rank = rank;
    }
    for (int i = 0; i < n; i++)
        cout << vec[i].rank << " ";
}
