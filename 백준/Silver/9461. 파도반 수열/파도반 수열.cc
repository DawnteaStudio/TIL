#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long arr[101];

int main()
{
    int T, N;
    cin >> T;

    for (int i = 1; i < 4; i++)
        arr[i] = 1;
    for (int i = 4; i <= 100; i++)
        arr[i] = arr[i - 2] + arr[i - 3];
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << arr[N] << '\n';
    }
}
