class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));//建立一個 m x n 的二維陣列，全部初始化成 1

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//上面格子 + 左邊格子
            }
        }

        return dp[m - 1][n - 1];
    }
};