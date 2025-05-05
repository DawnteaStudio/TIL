#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string str;
    cin >> N;
    N += 3071;
    str.push_back(N/4096 + 234);
    str.push_back(N/64 % 64 + 128);
    str.push_back(N % 64 + 128);
    cout << str;
}