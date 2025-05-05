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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, i = 0;
  string line;
  cin >> N;

  q *head;
  q *tmp;
  q *cursur;

  while (i < N)
  {
    cin >> line;
    head = list_new(0);
    cursur = head;
    for (int j = 0; j < line.length(); j++)
    {
      switch (line[j])
      {
      case '<':
        if (cursur != head)
          cursur = cursur->before;
        break;
      case '>':
        if (cursur->next != NULL)
          cursur = cursur->next;
        break;
      case '-':
        if (cursur != head)
        {
          tmp = cursur;
          cursur = cursur->before;
          if (tmp->next != NULL)
          {
            cursur->next = tmp->next;
            tmp->next->before = cursur;
          }
          else
            cursur->next = NULL;
        }
        break;
      default:
        tmp = list_new(line[j]);
        if (cursur->next != NULL)
        {
          tmp->next = cursur->next;
          cursur->next->before = tmp;
        }
        cursur->next = tmp;
        tmp->before = cursur;
        cursur = tmp;
        break;
      }
    }
    i++;
    while (head->next)
    {
      cout << head->next->data;
      head = head->next;
    }
    cout << '\n';
  }
}
