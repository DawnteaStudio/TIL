#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
  int num;
  cin >> num;
  cin.ignore();

  vector<vector<string>> v(num);

  for (int i = 0; i < num; i++)
  {
    string line;
    getline(cin, line);
    string word;
    stringstream ss(line);
    while (ss >> word)
    {
      v[i].push_back(word);
    }
  }

  for(int j = 0; j < num; j++)
  {
    cout << "Case #" << j+1 << ": ";
    int cases = v[j].size();
    for(int k = 0; k < cases; k++)
    {
      cout << v[j].back();
      if (k != cases - 1)
        cout << " ";
      else
        cout << '\n';
      v[j].pop_back();
    }
  }
}