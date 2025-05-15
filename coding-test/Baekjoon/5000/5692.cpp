#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void make_arr(int arr[5])
{
    int res = 1;
    int next = 2;
    for (int i = 0; i < 5; i++) {
        arr[i] = res;
        res *= next;
        next++;
    }
}

int main()
{
	fast;
	int arr[5];
    make_arr(arr);
    int input;
    while (true) {
        int res = 0;
        int pos = 0;
        cin >> input;
        if (input == 0)
            break;
        while (input > 0) {
            int tmp = input % 10;
            input /= 10;
            res += arr[pos] * tmp;
            pos++;
        }
        cout << res << '\n';
    }
}