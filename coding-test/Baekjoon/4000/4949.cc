#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  while(true)
  {
    string line;
    getline(cin, line);
    if (line == ".")
      break;
    stack<char> s = {};
    for(int i = 0; i < line.size(); i++)
    {
      if (line[i] == '(' || line[i] == '[')
        s.push(line[i]);
      else if (line[i] == ')' || line[i] == ']')
      {
        if ((line[i] == ')' && (s.empty() || s.top() != '(')) || (line[i] == ']' && (s.empty() ||s.top() != '[')))
        {
          cout << "no" << '\n';
          break;
        }
        else
          s.pop();
      }
      else if(line[i] == '.')
      {
        if(s.empty())
          cout << "yes" << '\n';
        else
          cout << "no" << '\n';
      }
      else
        continue;
    }
  }
}