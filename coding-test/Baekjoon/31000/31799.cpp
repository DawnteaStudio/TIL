#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    set_score(vector<int> &res, string &tmp)
{
    if (tmp[0] == 'C')
        res.push_back(0);
    else if (tmp[0] == 'B')
    {
        if (tmp[1] != '+')
            res.push_back(1);
        else
            res.push_back(2);
    }
    else
    {
        if (tmp[1] == '-')
            res.push_back(2);
        else if (tmp[1] == '0')
            res.push_back(3);
        else
            res.push_back(4);
    }
}

void    print(vector<int> &res, int n)
{
    int now;
    int before = res[0];
    char grade[5] = {'B', 'D', 'P', 'E', 'E'};
    cout << grade[before];

    for (int i = 1; i < n; i++)
    {
        now = res[i] - before;
        if (res[i] == 0)
            cout << grade[0];
        else if (res[i] == 1)
        {
            if (now <= 0)
                cout << grade[0];
            else
                cout << grade[now];
        }
        else if (res[i] == 2)
        {
            if (now <= 0)
                cout << grade[1];
            else
                cout << grade[2];
        }
        else if (res[i] == 3)
        {
            if (now <= 0)
                cout << grade[2];
            else
                cout << grade[3];
        }
        else
            cout << grade[3];
        before = res[i];
    }
}

int main() {
    fast;
    int n;
    cin >> n;
    string grade, tmp= "";
    cin >> grade;

    vector<int> res;
    int len = grade.length();
    tmp += grade[0];
    for (int i = 1; i < len; i++)
    {
        if (grade[i] >= 'A')
        {
            if (tmp.length() == 1)
                tmp += '0';
            set_score(res, tmp);
            tmp = grade[i];
        }
        else
            tmp += grade[i];
    }
    if (tmp.length() == 1)
        tmp += '0';
    set_score(res, tmp);
    print(res, n);
}
