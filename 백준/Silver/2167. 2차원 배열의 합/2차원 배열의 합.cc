#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct solve
{
    /* data */
};


int main()
{
    fast;
    int height, width, k, sum;
    int start_w, start_h, end_w, end_h;
    cin >> height >> width;
    int arr[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cin >> arr[i][j];
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        sum = 0;
        cin >> start_h >> start_w >> end_h >> end_w;
        for (int j = start_h; j <= end_h; j++)
        {
            for (int l = start_w; l <= end_w; l++)
                sum += arr[j - 1][l - 1];
        }
        cout << sum << '\n';
    }
}
