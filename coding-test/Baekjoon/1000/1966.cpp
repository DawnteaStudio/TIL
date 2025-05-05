#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

vector<int> ft_split(string line, vector<int> q)
{
  string word;
  int n_word;
  istringstream ss(line);
  while(getline(ss, word, ' '))
  {
    n_word = stoi(word);
    q.push_back(n_word);
  }
  return (q);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int size;
  int res;
  int num;
  int pos;
  int max;
  int target;
  string line;
  vector<int> q;
  vector<int> sort_q;
  cin >> size;

  for(int i = 0; i < size; i++)
  {
    res = 0;
    cin >> num >> pos;
    cin.ignore();
    getline(cin, line);
    q = ft_split(line, q);
    target = q[pos];
    sort_q = q;
    sort(sort_q.begin(), sort_q.end());
    reverse(sort_q.begin(), sort_q.end());
    max = sort_q.front();
    while(true)
    {
      if(q.front() == sort_q.front())
      {
        if(target == q.front() && pos == 0)
        {
          res++;
          cout << res << '\n';
          break;
        }
        res++;
        q.erase(q.begin());
        sort_q.erase(sort_q.begin());
        pos != 0  ? pos -= 1 : pos = q.size() -1;
      }
      else
      {
        q.push_back(q.front());
        q.erase(q.begin());
        pos != 0  ? pos -= 1 : pos = q.size() -1;
      }
    }
    q = vector<int>();
  }
}
