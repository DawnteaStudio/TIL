#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int N, M, head, tail, cutline, res;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> M;
        res = 1;
        vector<int> v(M + 1);
        for (int j = 0; j < M; j++)
        {
            cin >> head >> tail;
            v[head] = tail;
        }
        cutline = v[1];
        for (int j = 1; j <= M; j++)
        {
            if (cutline > v[j])
            {
                res++;
                cutline = v[j];
            }
        }
        v.clear();
        cout << res << '\n';
    }
}