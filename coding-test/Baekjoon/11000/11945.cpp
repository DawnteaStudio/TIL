#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int N, M;
    string str;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = M - 1; j >= 0; j--)
            cout << str[j];
        cout << '\n';
    }
}
