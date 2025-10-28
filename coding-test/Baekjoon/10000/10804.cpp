#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void cmd(vector<int> &vec, int s, int e)
{
    vector<int> tmp(e - s + 1);
    for (int i = s; i <= e; i++)
        tmp[e - i] = vec[i];
    for (int i = 0; i < e - s + 1; i++)
        vec[s + i] = tmp[i];
}

int main()
{
    fast;
    vector<int> vec(21);
    for (int i = 1; i <= 20; i++)
        vec[i] = i;
    int s, e;
    for (int i = 0; i < 10; i++) {
        cin >> s >> e;
        cmd(vec, s, e);
    }

    for (int i = 1; i <= 20; i++)
        cout << vec[i] << " ";
}
