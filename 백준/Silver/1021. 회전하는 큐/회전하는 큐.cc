#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct t_list
{
  int data;
  struct t_list *next;
  struct t_list *before; 
} q;

q  *list_new(int data)
{
  q  *new_q;

  new_q = (q *)malloc(sizeof(q));
  new_q->data = data;
  new_q->next = NULL;
  new_q->before = NULL;
  return(new_q);
}

q *lst_pop_front(q **node)
{
  q *tmp = *node;
  *node = (*node)->next;
  if (*node != NULL)
    (*node)->before = NULL;
  return (tmp);
}
q *lst_pop_back(q **node)
{
  q *tmp = *node;
  *node = (*node)->before;
  if (*node != NULL)
    (*node)->next = NULL;
  return (tmp);
}

void  lst_push_back(q **end, q *node)
{
  q *tmp = *end;
  tmp->next = node;
  node->before = tmp;
  *end = node;
}
void  lst_push_front(q **start, q *node)
{
  q *tmp = *start;
  tmp->before = node;
  node->next = tmp;
  *start = node;
}

int lst_find(q *start, int data)
{
  int pos = 0;
  while (start->data != data)
  {
    start = start->next;
    pos++;
  }
  return (pos);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, cnt, i = 2;
  int num, pos, res = 0;
  cin >> N >> cnt;
  q  *node = list_new(1);
  q  *end = node;
  while (i <= N)
  {
    lst_push_back(&end, list_new(i));
    i++;
  }
  while (cnt != 0)
  {
    cin >> num;
    pos = lst_find(node, num);
    if (pos <= N/2)
    {
      while (pos != 0)
      {
        lst_push_back(&end, list_new(node->data));
        lst_pop_front(&node);
        pos--;
        res++;
      }
      lst_pop_front(&node);
      N--;
      cnt--;
    }
    else
    {
      while (pos < N)
      {
        lst_push_front(&node, list_new(end->data));
        lst_pop_back(&end);
        pos++;
        res++;
      }
      lst_pop_front(&node);
      N--;
      cnt--;
    }
  }
  cout << res;
}