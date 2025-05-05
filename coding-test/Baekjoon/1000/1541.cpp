#include <iostream>
#include <string>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define PLUS true
#define MINUS false

int make_num(string str, int start, int end)
{
    int num;
    string tmp = "";

    for (int i = start; i < end; i++)
        tmp += str[i];
    num = stoi(tmp);
    return (num);
}

int main()
{
    fast;
    string str;
    vector<int> v;
    vector<bool> sign;
    int start = 0, end = 0, res;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (i == str.length() - 1)
                v.push_back(make_num(str, start, end + 1));
        }
        else
        {
            if (str[i] == '-')
                sign.push_back(MINUS);
            else
                sign.push_back(PLUS);
            v.push_back(make_num(str, start, end));
            start = i + 1;
        }
        end++;
    }

    int tmp, tmp_i;
    res = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        tmp = 0;
        if (sign[i - 1] == MINUS)
        {
            tmp += v[i];
            tmp_i = i + 1;
            for (int j = tmp_i; j < v.size(); j++)
            {
                if (sign[j - 1] == PLUS)
                {
                    tmp += v[j];
                    i++;
                }
                else
                    break;
            }
            res -= tmp;
        }
        else
            res += v[i];
    }
    cout << res;
}
