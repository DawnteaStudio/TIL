#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct t_list
{
  int data;
  struct t_list *next;
} card;

card  *list_new(int data)
{
  card  *new_card;

  new_card = (card *)malloc(sizeof(card));
  new_card->data = data;
  new_card->next = NULL;
  return(new_card);
}

card *lst_pop(card **node)
{
  card *tmp = *node;
  *node = (*node)->next;
  return (tmp);
}

void  lst_push(card **end, card *node)
{
  card *tmp = *end;
  tmp->next = node;
  *end = node;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, i = 2;
  cin >> N;
  card  *node = list_new(1);
  card  *end = node;
  while (i <= N)
  {
    lst_push(&end, list_new(i));
    i++;
  }
  while (node != end)
  {
    lst_pop(&node);
    lst_push(&end, list_new(node->data));
    lst_pop(&node);
    i--;
  }
  cout << node->data;
}