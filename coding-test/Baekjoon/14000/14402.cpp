#include <iostream>
#include <vector>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    int working = 0;
    string name, work;
    cin >> n;

    map<string, int> worker;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> work;
        if (worker.find(name) == worker.end())
        {
            if (work == "+")
            {
                worker[name] = 1;
                working++;
            }
            else
                working++;
        }
        else
        {
            if (work == "+")
            {
                worker[name]++;
                working++;
            }
            else
            {
                worker[name]--;
                working--;
                if (worker[name] == 0)
                    worker.erase(name);
            }
        }
    }
    cout << working;
}
