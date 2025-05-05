#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int last_node;

bool	ft_abs(int a, int b)
{
	int tmp_a = a;
	int tmp_b = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a < b)
		return (true);
	else if (a == b)
	{
		if (tmp_a < tmp_b)
			return (true);
		return (false);
	}
	else
		return (false);
}

void	swap(int *heap, int a, int b)
{
	int tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
}

void	rearrange(int *heap)
{
	int tmp, index = 1;

	while (index << 1 <= last_node)
	{
		if ((index << 1) + 1 <= last_node)
			tmp = ft_abs(heap[index << 1], heap[(index << 1) + 1]) ? index << 1 : (index << 1) + 1;
		else
			tmp = index << 1;
		if (ft_abs(heap[tmp], heap[index]))
		{
			swap(heap, index, tmp);
			index = tmp;
		}
		else
			break;
	}
}

void	pop(int *heap)
{
	if (last_node == 0)
		cout << 0;
	else
	{
		cout << heap[1];
		heap[1] = heap[last_node];
		last_node--;
		rearrange(heap);
	}
	cout << '\n';
}

void	push(int *heap, int input)
{
	heap[++last_node] = input;
	int index = last_node;

	while (1 < index)
	{
		if (ft_abs(heap[index], heap[index >> 1]))
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
