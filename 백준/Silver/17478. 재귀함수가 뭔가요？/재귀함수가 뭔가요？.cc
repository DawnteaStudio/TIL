#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

string mulstr(int n)
{
    string opt = "____";
    string res = "";

    for (int i = 0; i < n; i++)
        res += opt;
    return (res);
}

void reculsive(int n)
{
    string opt;
    opt = mulstr(n);
    if (n == N)
    {
        cout << opt << "\"재귀함수가 뭔가요?\"\n";
        cout << opt << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cout << opt << "라고 답변하였지.\n";
        return ;
    }
    else
    {
        cout << opt << "\"재귀함수가 뭔가요?\"\n";
        cout << opt << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        cout << opt << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        cout << opt << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        reculsive(n + 1);
    }
    cout << opt << "라고 답변하였지.\n";
}

int main()
{
    fast;
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    reculsive(0);
}