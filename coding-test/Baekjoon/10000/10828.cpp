#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void  command_print(string command, vector<int> &v)
{
  if(command == "top")
  {
    if(v.size() == 0)
      cout << -1 << '\n';
    else
      cout << v.back() << '\n';
  }
  else if(command == "size")
  {
    cout << v.size() << '\n';
  }
  else if(command == "empty")
  {
    if(v.size() == 0)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
  else if(command == "pop")
  {
    if(v.size() == 0)
      cout << -1 << '\n';
    else
    {
      cout << v.back() << '\n';
      v.pop_back();
    }
  }
  else
  {
    istringstream ss(command);
    string buffer;
    vector<string> split_buffer;

    while(getline(ss, buffer, ' '))
      split_buffer.push_back(buffer);
    v.push_back(stoi(split_buffer[1]));
  }
}

int main()
{
  int num;
  cin >> num;
  cin.ignore();

  vector<int> v;

  for(int i = 0; i < num; i++)
  {
    string command;

    getline(cin, command);
    command_print(command, v);
  }
}