#include <iostream>
#include <vector>

using namespace std;

int	main()
{
	int num;
	int answer = 0;
	int max = 0;
	cin >> num;
	vector<int> vec(num);

	for (int i = 0; i < num; i++)
	{
		cin >> vec[i];
	}
	while (!vec.empty())
	{
		if (max < vec.back())
		{
			answer++;
			max = vec.back();
		}
		vec.pop_back();
	}
	cout << answer;
	return (0);
}