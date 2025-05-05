#include <iostream>
#include <string>
#include <utility>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
  fast;

  int N;
  string str;
  cin >> N;

  pair<string, string> p[7];
  p[0] = make_pair("Algorithm", "204");
  p[1] = make_pair("DataAnalysis", "207");
  p[2] = make_pair("ArtificialIntelligence", "302");
  p[3] = make_pair("CyberSecurity", "B101");
  p[4] = make_pair("Network", "303");
  p[5] = make_pair("Startup", "501");
  p[6] = make_pair("TestStrategy", "105");

  while (N--)
  {
    cin >> str;
    for (int i = 0; i < 7; i++)
    {
      if (p[i].first == str)
      {
          cout << p[i].second <<'\n';
          break;
      }
    }
  }
}
