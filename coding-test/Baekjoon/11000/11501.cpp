#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    long long N, M, selling, res, num;
    vector<long long> v;
    cin >> N;

    for (long long i = 0; i < N; i++)
    {
        cin >> M;
        res = 0;
        selling = 0;
        for (long long j = 0; j < M; j++)
        {   
            cin >> num;
            v.push_back(num);
        }
        for (long long j = M - 1; j >= 0; j--)
        {
            if (v[j] > selling)
                selling = v[j];
            else
                res += (selling - v[j]);
        }
        cout << res << '\n';
        v.clear();
    }
}