#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void right(vector<int> &vec, int start, int &res, bool empty)
{
    int size = vec.size();
    for (int i = start; i < size; i++) {
        if (empty) {
            if (vec[i] == 0)
                res++;
        }
        else
            res += vec[i];
    }
}

void left(vector<int> &vec, int start, int &res, bool empty)
{
    for (int i = start; i >= 1; i--) {
        if (empty) {
            if (vec[i] == 0)
                res++;
        }
        else
            res += vec[i];
    }
}

int main()
{
    fast;
    int room, cnt = 0, empty = 0;
    cin >> room;
    vector<int> vec(room + 1);
    for (int i = 1; i <= room; i++)
        cin >> vec[i];

    int start_a, start_b;
    string dir_a, dir_b;
    cin >> start_a >> dir_a >> start_b >> dir_b;
    if (dir_a == "right")
        right(vec, start_a, cnt, false);
    else
        left(vec, start_a, cnt, false);
    if (dir_b == "right")
        right(vec, start_b, empty, true);
    else
        left(vec, start_b, empty, true);
    cout << cnt << " " << empty;
}