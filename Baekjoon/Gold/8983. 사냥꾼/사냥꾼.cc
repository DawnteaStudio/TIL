#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool is_catch(pair<long long, long long> animal, long long sade[], long long left, long long right, long long L)
{
  long long mid;

  while (left <= right)
  {
    mid = (left + right) / 2;
    if (abs(sade[mid] - animal.first) + animal.second <= L)
      return (true);
    else if (animal.first < sade[mid])
      right = mid - 1;
    else if (animal.first > sade[mid])
      left = mid + 1;
    else
      return (false);
  }
  return (false);
}

long long solve(long long M, long long sade[], pair<long long, long long> animal[], long long N, long long L)
{
    long long cnt = 0;

    for (int i = 0; i < N; i ++)
    {
        if(is_catch(animal[i], sade, 0, M - 1, L))
            cnt++;
    }
    return (cnt);
}

int main()
{
    fast;
    int M, N, L;
    long long fir, scn;
    cin >> M >> N >> L;

    pair<long long, long long> *animal = new pair<long long, long long>[N];
    long long *sade = new long long[M];

    for (int i = 0; i < M; i++)
        cin >> sade[i];
    sort(sade, sade + M);
    for (int i = 0; i < N; i++)
    {
        cin >> fir >> scn;
        animal[i] = make_pair(fir, scn);
    }
    cout << solve(M, sade, animal, N, L);
    delete[] animal;
    delete[] sade;
}