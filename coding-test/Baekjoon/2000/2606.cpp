#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res;

void spread_virus(int cpu, int num, int **arr, bool *visited)
{
    visited[cpu] = true;
    for (int i = 1; i < num + 1; i++)
    {
        if (i != cpu)
            if (arr[cpu][i] == 1 && visited[i] == false)
            {
                res++;
                spread_virus(i, num, arr, visited);
            }
    }
}

int main()
{
    fast;
    int num, cases;
    int fir, sec;

    cin >> num >> cases;
    int **arr = new int*[num + 1];
    bool visited[num + 1];
    for (int i = 1; i < num + 1; i++)
        visited[i] = false;
    for (int i = 1; i < num + 1; i++)
        arr[i] = new int[num  + 1];
    for (int i = 0; i < cases; i++)
    {
        cin >> fir >> sec;
        arr[fir][sec] = 1;
        arr[sec][fir] = 1;
    }
    spread_virus(1, num, arr, visited);
    for (int i = 0; i < num + 1; i++)
        delete[] arr[i];
    delete[] arr;
    cout << res;
}
