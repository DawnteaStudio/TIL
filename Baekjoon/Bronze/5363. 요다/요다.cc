#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;
	cin.ignore();

	string input, tmp;
	vector<string> arr;
	stringstream ss;
	for (int i = 0; i < n; i++)
	{
		input = "";
		arr.clear();
		ss.clear();
		getline(cin, input);
		ss.str(input);
		while (ss >> tmp)
			arr.push_back(tmp);
		for (int i = 2; i < arr.size(); i++)
			cout << arr[i] << " ";
		for (int i = 0; i < 2; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}
}
