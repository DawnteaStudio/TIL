#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct t_list
{
  char data;
  struct t_list *next;
  struct t_list *before;
} q;

q *list_new(char data)
{
  q *new_q;

  new_q = (q *)malloc(sizeof(q));
  new_q->data = data;
  new_q->next = NULL;
  new_q->before = NULL;
  return (new_q);
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

void lst_push_back(q **end, q *node)
{
  q *tmp = *end;
  tmp->next = node;
  node->before = tmp;
  *end = node;
}
void lst_push_front(q **start, q *node)
{
  q *tmp = *start;
  tmp->before = node;
  node->next = tmp;
  *start = node;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string init;
  char command;
  char ch;
  cin >> init;
  int N, i = 0;
  cin >> N;

  q *node = list_new(0);
  q *end = node;
  q *head = node;
  q *tmp = NULL;

  for (int j = 0; j < init.length(); j++)
    lst_push_back(&end, list_new(init[j]));

  q *cursur = end;
  node = node->next;

  while (i < N)
  {
    cin >> command;
    switch (command)
    {
    case 'L':
      if (cursur != head)
        cursur = cursur->before;
      break;
    case 'D':
      if (cursur->next != NULL)
        cursur = cursur->next;
      break;
    case 'B':
      if (cursur != head)
      {
        tmp = cursur;
        cursur = cursur->before;
        if (tmp->next != NULL)
        {
          cursur->next = tmp->next;
          tmp->next->before = cursur;
          if (cursur == head)
            node = head->next;
        }
        else
        {
          cursur->next = NULL;
          if (cursur == head)
            node = head;
        }
      }
      break;
    case 'P':
      cin >> ch;
      tmp = list_new(ch);
      if (cursur->next != NULL)
      {
        tmp->next = cursur->next;
        cursur->next->before = tmp;
      }
      cursur->next = tmp;
      tmp->before = cursur;
      cursur = tmp;
      if (cursur == node->before)
        node = cursur;
      break;
    }
    i++;
  }
  while (node)
  {
    cout << node->data;
    node = node->next;
  }
}
