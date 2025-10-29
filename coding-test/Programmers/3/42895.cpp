#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int get_pure(int N, int cnt)
{
    int res = 0;
    for (int i = 0; i <= cnt; i++)
        res = res * 10 + N;

    return res;
}

int solution(int N, int number) {
    if (N == number)
        return 1;
    
    vector<unordered_set<int> > dp(8);
    dp[0].insert(N);
    
    for (int i = 1; i < 8; i++) {
        dp[i].insert(get_pure(N, i));
        
        for (int f = 0; f < 8; f++) {
            for (int b = 0; b < 8; b++) {
                if (f + b + 1 != i)
                    continue;
                
                for (unordered_set<int>::iterator iter1 = dp[f].begin(); iter1 != dp[f].end(); iter1++) {
                    for (unordered_set<int>::iterator iter2 = dp[b].begin(); iter2 != dp[b].end(); iter2++) {
                        int num_f = *iter1;
                        int num_b = *iter2;
                        
                        dp[i].insert(num_f + num_b);
                        if (num_f - num_b > 0)
                            dp[i].insert(num_f - num_b);
                        dp[i].insert(num_f * num_b);
                        if (num_f / num_b > 0)
                            dp[i].insert(num_f / num_b);
                    }
                }
            }
        }
        for (unordered_set<int>::iterator iter = dp[i].begin(); iter != dp[i].end(); iter++) {
            cout << i + 1 << "--> " << *iter << " "; 
            if (*iter == number)
                return i + 1;
        }
        cout << '\n' << '\n';
    }
    return -1;
}