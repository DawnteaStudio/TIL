#include <iostream>
using namespace std;

int main()
{
    int num;

    while (1) {
        cin >> num;
        if (num == 0)
            break ;
        cout << num * (1 + num) / 2 << '\n';
    }
    return 0;
}
