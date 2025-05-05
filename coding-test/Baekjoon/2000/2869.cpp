#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int A, B, V;
  int res = 1;

  cin >> A >> B >> V;
  V -= A;
  if(V <= 0)
    cout << res;
  else if(V >= (A-B))
  {
    res += ceil((double)V/(A-B));
    cout << res;
  }
  else
    cout << res + 1;
  return(0);
}