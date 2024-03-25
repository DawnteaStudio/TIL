#include <iostream>
#include <string>
#include <queue>
#include <utility>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string answer;
int flag;

void	D(queue<pair<int, string>> &q, bool visited[10000], int goal)
{
	int res;
	string str = q.front().second;

	res = (q.front().first * 2) % 10000;
	str += "D";
	if (res == goal && flag == 0)
	{
		flag = 1;
		answer = str;
	}
	if (visited[res] == false)
	{
		visited[res] = true;
		q.push({res, str});
	}
}

void	S(queue<pair<int, string>> &q, bool visited[10000], int goal)
{
	int res;
	string str = q.front().second;

	res = q.front().first - 1;
	if (res < 0)
		res = 9999;
	str += "S";
	if (res == goal && flag == 0)
	{
		flag = 1;
		answer = str;
	}
	if (visited[res] == false)
	{
		visited[res] = true;
		q.push({res, str});
	}
}

void	L(queue<pair<int, string>> &q, bool visited[10000], int goal)
{
	int res;
	string str = q.front().second;

	res = (q.front().first % 1000) * 10 + (q.front().first / 1000);
	str += "L";
	if (res == goal && flag == 0)
	{
		flag = 1;
		answer = str;
	}
	if (visited[res] == false)
	{
		visited[res] = true;
		q.push({res, str});
	}
}

void	R(queue<pair<int, string>> &q, bool visited[10000], int goal)
{
	int res;
	string str = q.front().second;

	res = (q.front().first % 10) * 1000 + (q.front().first / 10);
	str += "R";
	if (res == goal && flag == 0)
	{
		flag = 1;
		answer = str;
	}
	if (visited[res] == false)
	{
		visited[res] = true;
		q.push({res, str});
	}
}

void	find_answer(int start, int goal, bool visited[10000])
{
	queue<pair<int, string>> q;
	string str = "";
	int tmp;
	q.push({start, str});
	visited[start] = true;
	void (*ft[4])(queue<pair<int, string>> &q, bool[], int) = {D, S, L, R};

	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			ft[i](q, visited, goal);
			if (flag == 1)
			{
				cout << answer << '\n';
				return ;
			}
		}
		q.pop();
	}
}

int main()
{
	fast;

	int n, start, goal;
	bool visited[10000] = {false};
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> start >> goal;
		flag = 0;
		for (int j = 0; j < 10000; j++)
			visited[j] = false;
		find_answer(start, goal, visited);
	}
}
