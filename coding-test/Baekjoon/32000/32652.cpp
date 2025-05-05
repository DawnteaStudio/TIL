#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n;
    cin >> n;
    
    string res = "AKARAKA";
    for (int i = 1; i < n; i++)
        res += "RAKA";
    cout << res;
}
