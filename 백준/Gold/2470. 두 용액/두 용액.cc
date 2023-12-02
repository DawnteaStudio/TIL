#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

int main()
{
    fast;
    cin >> N;
    
    int *arr = new int[N];
    int left = 0;
    int right = N-1;
    long long ans_L, ans_R;
    int sum = 2000000000, new_sum;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);

    ans_L = arr[left];
    ans_R = arr[right];
    while (left < right)
    {
        new_sum = abs(arr[left] + arr[right]);
        if (new_sum < sum)
        {
            sum = new_sum;
            ans_L = arr[left];
            ans_R = arr[right];
        }
        if (arr[left] + arr[right] < 0)
            left++;
        else
            right--;
    }
    cout << ans_L << ' ' << ans_R;
    delete[] arr;
}