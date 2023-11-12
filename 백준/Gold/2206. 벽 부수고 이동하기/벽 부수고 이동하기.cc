#include <iostream>
#include <string>
#include <queue>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct Node{
	int	x;
	int y;
	int chance;
};

int arr[1000][1000];
int visit[1000][1000][2] = {0};
int	N, M;

int	bfs(Node n)
{
	int dy[4] = {0, -1, 0, 1}; 
	int dx[4] = {-1, 0, 1, 0};
	queue<Node> q;
	Node next;
	Node tmp;

	q.push(n);
	visit[n.y][n.x][n.chance] = 1;
	while(!q.empty())
	{
		next = q.front();
		q.pop();
		if (next.y == N-1 && next.x == M-1)
			return(visit[next.y][next.x][next.chance]);
		for (int i = 0; i < 4; i++)
		{
			if(next.y + dy[i] < 0 || next.x + dx[i] < 0 || next.y + dy[i] >= N || next.x + dx[i] >= M)
				continue;
			if(arr[next.y + dy[i]][next.x + dx[i]] == 0 && visit[next.y + dy[i]][next.x + dx[i]][next.chance] == 0)
			{
				visit[next.y + dy[i]][next.x + dx[i]][next.chance] = visit[next.y][next.x][next.chance] + 1; 
				tmp.y = next.y + dy[i];
				tmp.x = next.x + dx[i];
				tmp.chance = next.chance;
				q.push(tmp);
			}
			else if(arr[next.y + dy[i]][next.x + dx[i]] == 1)
			{
				if (next.chance == 1)
					continue;
				else if (visit[next.y + dy[i]][next.x + dx[i]][next.chance] == 0)
				{
					visit[next.y + dy[i]][next.x + dx[i]][next.chance + 1] = visit[next.y][next.x][next.chance] + 1;
					tmp.y = next.y + dy[i];
					tmp.x = next.x + dx[i];
					tmp.chance = 1;
					q.push(tmp);
				}
			}
		}
	}
	return (-1);
}

int main()
{
	string str;
	Node n = {0, 0, 0};
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
			arr[i][j] = str[j] - '0';
	}
	cout << bfs(n);	
}
