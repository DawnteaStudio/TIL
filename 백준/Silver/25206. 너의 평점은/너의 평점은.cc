#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

double  get_grade(string score, double creidt)
{
    double  grade = 0;
    if (score[0] == 'A')
    {
        grade += 4;
        if (score[1] == '+')
            grade += 0.5;
    }
    else if (score[0] == 'B')
    {
        grade += 3;
        if (score[1] == '+')
            grade += 0.5;
    }
    else if (score[0] == 'C')
    {
        grade += 2;
        if (score[1] == '+')
            grade += 0.5;
    }
    else if (score[0] == 'D')
    {
        grade += 1;
        if (score[1] == '+')
            grade += 0.5;
    }
    return (grade * creidt);
}

int main()
{
    fast;
    double sum = 0, all_credit = 0, credit;
    string str, score;

    for (int i = 0; i < 20; i++)
    {
        cin >> str >> credit >> score;
        if (score[0] != 'P')
        {
            sum += get_grade(score, credit);
            all_credit += credit;
        }
    }
    if (all_credit == 0)
        cout << 0;
    else
        cout << sum/all_credit;
}
