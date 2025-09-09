#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    int cnt = 0;
    // Please write your code here.
    int len = A.length();
    
    for (int i = 0; i < len; i++) {
        if (A[i] == ')')
            continue;
        for (int j = i + 1; j < len; j++)
            if (A[j] == ')')
                cnt++;
    }
    cout << cnt;
    return 0;
}