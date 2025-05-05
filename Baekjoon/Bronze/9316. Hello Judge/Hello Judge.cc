#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
    fast;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << "Hello World, Judge " << i << "!\n";
}