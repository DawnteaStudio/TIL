#include <iostream>
#include <string>
#include <sstream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	string input;
	string token;
	stringstream ss;

	cin >> input;
	int arr[3];
	ss.str(input);

	int i = 0;
	while (getline(ss, token, '/'))
	{
		arr[i] = stoi(token);
		i++;
	}
	if (arr[0] + arr[2] < arr[1] || arr[1] == 0)
		cout << "hasu";
	else
		cout << "gosu";
}
