#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool is_valid(char c)
{
    if((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c =='-')
        return (true);
    return (false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int flag, i = 1;
    string  name;
    vector<int> v;

    while (i <= 5)
    {
        flag = 0;
        cin >> name;
        for(int j = 0; j < name.length(); j++)
        {
            if (!is_valid(name[j]))
                break;
            if (name[j] == 'F')
            {
                if (j > name.length()-2)
                    break;
                else
                {
                    if(name[j+1] == 'B' && name[j+2] == 'I')
                        flag = 1;
                }
            }
            if (flag == 1 && j == name.length() - 1)
                v.push_back(i);
        }
        i++;
    }
    if (v.empty())
        cout << "HE GOT AWAY!";
    else
    {
        for (int k = 0; k < v.size(); k++)
        {
            if (k != v.size() - 1)
                cout << v[k] << " ";
            else
                cout << v[k];
        }
    }
}
