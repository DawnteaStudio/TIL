#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int N, L, D, time, ending;
    cin >> N >> L >> D;
    ending = (N * (L + 5));
    time = D;

    while (time < ending)
    {
        int check = (ending - time) % (L + 5);
        if (check > 0 && check <= 5)
        {
            cout << time;
            return (0);
        }
        time += D;
    }
    cout << time;
}
