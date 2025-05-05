#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, last_node;

void swap(int *heap, int a, int b)
{
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}

void rearrange(int *heap)
{
    int index = 1;
    int tmp;
    while (index <= last_node)
    {
        if (index << 1 > last_node)
            break;
        if ((index << 1 ) + 1 <= last_node)
            tmp = heap[index << 1] < heap[(index << 1) + 1] ? index << 1 : (index << 1) + 1;
        else
            tmp = index << 1;

        if (heap[index] > heap[tmp])
        {
            swap(heap, index, tmp);
            index = tmp;
        }
        else
            break;
    }
}

void pop(int *heap)
{
    if (last_node < 1)
        cout << 0 << '\n';
    else
    {
        cout << heap[1] << '\n';
        heap[1] = heap[last_node];
        last_node--;
        rearrange(heap);
    }
}

void push(int *heap, int input)
{
    last_node++;
    int index = last_node;

    heap[index] = input;
    while (index)
    {
        if (heap[index >> 1] > heap[index] && index >> 1 != 0)
            swap(heap, index >> 1, index);
        else
            break;
        index >>= 1;
    }
}

int main()
{
    fast;

    cin >> n;

    int heap[n + 1];
    int tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            pop(heap);
        else
            push(heap, tmp);
    }
}
