#include <iostream>
#include <string>
using namespace std;

string make_string(int num)
{
  int i = 0;
  string res = "";
  while (i < num)
  {
    res += "@";
    i++;
  }
  return (res);
}

string make_blank(int num)
{
  int i = 0;
  string res = "";
  while (i < num)
  {
    res += " ";
    i++;
  }
  return (res);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num, i = 1;
  string res = "";

  cin >> num;
  while(i <= num * 5)
  {
    if (i <= num)
    {
      cout << make_string(num * 3);
      cout << make_blank(num);
      cout << make_string(num);
      cout << "\n";
    }
    else if (i <= num * 4)
    {
      cout << make_string(num);
      cout << make_blank(num);
      cout << make_string(num);
      cout << make_blank(num);
      cout << make_string(num);
      cout << "\n";
    }
    else 
    {
      cout << make_string(num);
      cout << make_blank(num);
      cout << make_string(num * 3);
      cout << "\n";
    }
    i++;
  }
  cout << res << '\n';
}
