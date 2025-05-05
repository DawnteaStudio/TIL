#include <iostream>
#include <algorithm>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int v, k;
    vector<int> vec;
    cin >> v >> k;

    for (int i = v; i >= 1;)
    {
        for (int j = 0; j < k && i > 0; j++, i--)
            vec.push_back(i);
        for (int j = 0; j < k && i > 0; j++, i--);
    }
    // if (vec[vec.size() - 1] != 1 && vec[vec.size() - 1] != v)
    // {
    //  vec.erase(find(vec.begin(), vec.end(), 1 + k));
    //  vec.push_back(1);
    // }
    cout << vec.size() << '\n';
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << '\n';
}
