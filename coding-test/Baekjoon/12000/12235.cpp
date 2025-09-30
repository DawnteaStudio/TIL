#include <iostream>
#include <algorithm>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

int main()
{
  fast;
  int t, x, n;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int res = 0;
    cin >> x >> n;
    vector<int> file(x);
    for (int j = 0; j < x; j++)
      cin >> file[j];
    sort(file.begin(), file.end());

    int s = 0;
    int e = x - 1;
    while (e >= s) {
      if (n >= file[e] + file[s])
        s++;
      e--;
      res++;
    }
    cout << "Case #" << i <<": " << res << '\n';
  }
}  
