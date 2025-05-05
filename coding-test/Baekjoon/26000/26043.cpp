#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
  int size;
  int num;
  int food;
  int stu_num;
  vector<int> A;
  vector<int> B;
  deque<int> C_deque;
  deque<int> foods_deque;
  cin >> size;

  for(int i = 0; i < size; i++)
  {
    cin >> num;
    if (num == 1)
    {
      cin >> stu_num;
      C_deque.push_back(stu_num);
      cin >> food;
      foods_deque.push_back(food);
    }
    else
    {
      cin >> food;
      if (food == foods_deque.front())
        A.push_back(C_deque.front());
      else
        B.push_back(C_deque.front());
      C_deque.pop_front();
      foods_deque.pop_front();
    }
  }
  if(A.empty())
    cout <<"None\n";
  else
  {
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size() - 1; i++)
      cout << A[i] << ' ';
    cout << A[A.size() - 1] << '\n';
  }
  if(B.empty())
    cout <<"None\n";
  else
  {
    sort(B.begin(), B.end());
    for(int i = 0; i < B.size() - 1; i++)
      cout << B[i] << ' ';
    cout << B[B.size() - 1] << '\n';
  }
  if(C_deque.empty())
    cout <<"None\n";
  else
  {
    vector<int> C(C_deque.begin(), C_deque.end());
    sort(C.begin(), C.end());
    for(int i = 0; i < C.size() - 1; i++)
      cout << C[i] << ' ';
    cout << C[C.size() - 1] << '\n';
  }
}