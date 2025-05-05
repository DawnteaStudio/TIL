#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct t_list
{
  int num;
  int move;
  struct t_list *next;
  struct t_list *before;
} q;

q *list_new(int num, int move)
{
  q *new_q;

  new_q = (q *)malloc(sizeof(q));
  new_q->num = num;
  new_q->move = move;
  new_q->next = NULL;
  new_q->before = NULL;
  return (new_q);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, move, i = 2;
  int num;
  cin >> N >> move;

  q *ballon = list_new(1, move);
  q *tmp;
  q *node = ballon;

  while (i <= N)
  {
    cin >> move;
    tmp = list_new(i, move);
    if(i != N)
    {
      node->next = tmp;
      tmp->before = node;
      node = tmp;
    }
    else
    {
      node->next = tmp;
      tmp->before = node;
      tmp->next = ballon;
      ballon->before = tmp;
    }
    i++;
  }
  for(int j = 0; j < N; j++)
  {
    cout << ballon->num << ' ';
    move = ballon->move;
    tmp = ballon;
    if (j != N - 1)
    {
      tmp->before->next = ballon->next;
      tmp->next->before = ballon->before;
      if (move > 0)
      {
        for(int k = 0; k < move; k++)
          ballon = ballon->next;
      }
      else
      {
        move *= -1;
        for(int k = 0; k < move; k++)
          ballon = ballon->before;
      }
    }
  }
}
