#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;

int main() {
	fast;
    
        cin >> n;
        n %= 100;
        if (n == 0 || n == 10 || n == 30 || n == 60)
            cout << 0;
        else if (n < 10)
            cout << 1;
        else if (n < 30) {
            n -= 10;
            if (n > 5 && n < 15)
                cout << 2;
            else
                cout << 1;
        }
        else if (n < 60) {
            n -= 30;
            if (n > 10 && n < 20)
                cout << 3;
            else if (n > 5 && n < 25)
                cout << 2;
            else
                cout << 1;
        }
        else {
            n -= 60;
            if (n > 15 && n < 25)
                cout << 4;
            else if (n > 10 && n < 30)
                cout << 3;
            else if (n > 5 && n < 35)
                cout << 2;
            else
                cout << 1;
        }
}
