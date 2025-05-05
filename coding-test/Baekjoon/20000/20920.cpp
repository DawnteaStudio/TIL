#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// bool alpha_cmp(pair<string, int>& a, pair<string, int>& b) {
//     return a.first < b.first;
// }

// bool cnt_len(pair<string, int>& a, pair<string, int>& b)
// {
//   return (a.first.length() > b.first.length());
// }

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
  if (a.second > b.second)
    return true;
  else if (a.second == b.second)
  {
    if (a.first.length() > b.first.length())
      return true;
    else if (a.first.length() == b.first.length())
      {
        if (a.first < b.first)
          return true;
        else
          return false;
      }
      return false;
  }
    return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, i = 0;
  string word;
  cin >> N >> M;
  map<string, int> alpha_map;
  vector<pair<string, int>> v;
    vector<pair<string, int>>::iterator iter;
    iter = v.begin();

  while (i < N)
  {
    cin >> word;
    if (word.length() >= M)
    {
      if (alpha_map.find(word) != alpha_map.end())
        alpha_map[word] += 1;
      else
        alpha_map[word] = 1;
    }
    i++;
  }
  v.assign(alpha_map.begin(), alpha_map.end());
  sort(v.begin(), v.end(), cmp);

  for (iter = v.begin(); iter != v.end(); iter++)
  {
    cout << iter->first << '\n';
  }
}