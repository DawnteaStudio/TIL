#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int size;
  vector<char> res;
  vector<int> s;
  int max = 0;
  cin >> size;

  for(int i = 0; i < size; i++)
  {
    int num;
    cin >> num;
    if (i == 0)
    {
      for(int j = 0; j < num; j++)
      {
        res.push_back('+');
        s.push_back(j+1);
      }
      res.push_back('-');
      s.pop_back();
      max = num;
    }
    else
    {
      if (!s.empty())
      {
        if (s.back() - num > 0)
        {
          cout << "NO";
          return (0);
        }
        else if (s.back() == num)
        {
          res.push_back('-');
          s.pop_back();
        }
        else
        {
          for(int j = max; j < num; j++)
          {
            res.push_back('+');
            s.push_back(j+1);
          }
          max = s.back();
          res.push_back('-');
          s.pop_back();
        }
      }
      else
      {
        if(max > num)
        {
          cout << "NO";
          return (0);
        }
        else
        {
          for(int j = max; j < num; j++)
          {
            res.push_back('+');
            s.push_back(j+1);
          }
          res.push_back('-');
          max = s.back();
          s.pop_back();
        }
      }
    }
  }


  for(int j = 0; j < res.size(); j++)
  {
    cout << res[j] << '\n';
  }
}