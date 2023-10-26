#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

typedef struct a{
    int num;
    struct a *next;
} card;

card *ft_new(int num)
{
    card *new_node;
    
    new_node = (card *)malloc(sizeof(card));
    new_node->num = num;
    new_node->next = NULL;
    return (new_node);
}

int ft_size(card *start)
{
    int i = 0;
    while(start)
    {
        start = start->next;
        i++;
    }
    return (i);
}

card* ft_last(card* start) 
{
    while(start->next)
    {
        start = start-> next;
    }
    return (start);
}

void    ft_push(card* start, card* node)
{
    card *tmp = ft_last(start);
    tmp->next = node;
}

card* ft_pop(card **start)
{
    card *tmp = *start;
    *start = (*start)->next;
    return (tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i = 1;
    cin >> N;
    card *start = ft_new(i++);
    while(i <= N)
    {
        ft_push(start, ft_new(i));
        i++;
    }
    while(ft_size(start) != 1)
    {
        cout << ft_pop(&start)->num << ' ';
        ft_push(start, ft_new(start->num));
        ft_pop(&start);
    }
    cout << ft_pop(&start)->num;
    return (0);
}
