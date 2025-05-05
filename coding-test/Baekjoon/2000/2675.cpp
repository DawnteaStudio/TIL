#include <iostream>
#include <string>
#include <vector>
using namespace std;

void    print_chr(int num, char c)
{
    int i = 0;
    while(i < num)
    {
        cout << c;
        i++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, R, i = 0;
    vector<char> v;
    string str;
    cin >> T;
    while (i < T)
    {
        cin >> R >> str;
        for(int j = 0; j < str.length(); j++)
            v.push_back(str[j]);
        for (int k = 0; k < v.size(); k++)
            print_chr(R, v[k]);
        cout << '\n';
        v.clear();
        i++;
    }
}
