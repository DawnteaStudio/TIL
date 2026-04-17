#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	unordered_map<char, int> wrongCount;
    unordered_set<char> solved;

    int solvedCnt = 0;
    int penalty = 0;

    while (true) {
        string first;
        cin >> first;

        if (first == "-1") break;

        int time = stoi(first);
        char problem;
        string result;
        cin >> problem >> result;

        if (solved.count(problem)) continue;

        if (result == "wrong") {
            wrongCount[problem]++;
        } else { // right
            solved.insert(problem);
            solvedCnt++;
            penalty += time + wrongCount[problem] * 20;
        }
    }

    cout << solvedCnt << ' ' << penalty << '\n';
}
