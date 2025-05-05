#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int last_node;

void	swap(int *heap, int a, int b)
{
	int tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
}

void	pop(int *heap)
{
	int tmp, index = 1;

	if (last_node == 0)
		cout << "0" << '\n';
	else
	{
		cout << heap[1] << '\n';
		heap[1] = heap[last_node];
		last_node--;
		while ((index << 1) <= last_node)
		{
			if ((index << 1) + 1 <= last_node)
				tmp = heap[index << 1] > heap[(index << 1) + 1] ? index << 1 : (index << 1) + 1;
			else
				tmp = index << 1;
			if (heap[index] < heap[tmp])
			{
				swap(heap, index, tmp);
				index = tmp;
			}
			else
				break;
		}
	}
}

void	push(int *heap, int input)
{
	last_node++;
	int index = last_node;
	heap[last_node] = input;

	while (index > 1)
	{
		if (heap[index] > heap[index >> 1])
			swap(heap, index, index >> 1);
		else
			break;
		index >>= 1;
	}
}

int main()
{
	fast;

	int n, tmp;
	cin >> n;

	int heap[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		if (tmp == 0)
			pop(heap);
		else
			push(heap, tmp);
	}
}
