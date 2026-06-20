class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // 多開一格空間，用來代表空字串的邊界（預設全部填 0）
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 因為 dp 的指標是從 1 開始，對應到字串的索引要減 1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 字母相同，左上角的值加 1
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 字母不同，取上面或左邊的最大值
                }
            }
        }

        return dp[m][n];
    }
};