#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int h = triangle.size();
    vector<vector<int>> dp = triangle;
    
    for (int i = 0; i < h - 1; i++) {
        int size = triangle[i].size();
        
        for (int j = 0; j < size; j++) {
            if (dp[i][j] + triangle[i + 1][j] > dp[i + 1][j])
                dp[i + 1][j] = dp[i][j] + triangle[i + 1][j];
            if (dp[i][j] + triangle[i + 1][j + 1] > dp[i + 1][j + 1])
                dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
        }
    }
    
    
    int res = 0;
    int len = dp[h - 1].size();
    for (int i = 0; i < len; i++) {
        if (res < dp[h - 1][i])
            res = dp[h - 1][i];
    }
    return res;
}