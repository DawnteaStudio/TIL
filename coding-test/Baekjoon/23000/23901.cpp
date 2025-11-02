#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, tmp;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        cin >> n;
        tmp = 0;
        vector<int> vec(n);
        for (int j = 0; j < n; j++)
            cin >> vec[j];
        for (int j = 1; j < n - 1; j++) {
            if (vec[j] > vec[j - 1] && vec[j] > vec[j + 1])
                tmp++;
        }
        cout << "Case #" << i << ": " << tmp << '\n';    
    }
    return 0;
}