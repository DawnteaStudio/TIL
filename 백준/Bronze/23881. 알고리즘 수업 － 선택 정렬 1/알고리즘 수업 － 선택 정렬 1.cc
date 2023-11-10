#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int N, chance, last, swap_index, index, max, cnt = 0;
	cin >> N >> chance;
	int *arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	last = N - 1;

	for (int i = 0; i < N; i++)
	{
		max = 0;
        for (index = 0; index <= last; index++)
		{
			if (arr[index] > max)
			{
				max = arr[index];
				swap_index = index;
			}
		}
		if (max != arr[last])
		{
			arr[swap_index] = arr[last];
			arr[last] = max;
            cnt++;
            if (cnt == chance)
            {
                cout << arr[swap_index] << ' ' << max;
                break;
            }
		}
		last--;
	}
    if (cnt < chance)
        cout << -1;
	delete[] arr;
}