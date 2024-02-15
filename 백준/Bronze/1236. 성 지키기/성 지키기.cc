#include <iostream>
#include <cstring>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, a_res, b_res, res;
    string input;
    cin >> a >> b;
    int arr_y[a];
    int arr_x[b];
    memset(arr_y, 0, sizeof(int) * a);
    memset(arr_x, 0, sizeof(int) * b);
    a_res = a;
    b_res = b;
    for (int i = 0; i < a; i++)
    {
        cin >> input;
        for (int j = 0; j < b; j++)
        {
            if (input[j] == 'X' && (arr_y[i] == 0 || arr_x[j] == 0))
            {
                if (arr_y[i] == 0)
                {
                    arr_y[i] = 1;
                    a_res--;
                }
                if (arr_x[j] == 0)
                {
                    arr_x[j] = 1;
                    b_res--;
                }
            }
        }
    }
    res = a_res > b_res ? a_res : b_res;
    cout << res;
}
