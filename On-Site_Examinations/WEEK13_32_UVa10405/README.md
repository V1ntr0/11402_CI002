
# UVa 10405 - Longest Common
## Problem Description
給定兩個字串，求它們的「最長公共子序列（LCS）」的長度。子序列指的是從原本字串中刪除零個或多個字元後，其餘字元保持原本相對順序所組成的新字串。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346)

## Learning Objectives
- [ ] 了解 最長公共子序列（LCS）
## Solution Approach

### Algorithm Logic
1. 使用 getline(cin, s1) 與 getline(cin, s2) 連續讀入兩字串，直到檔案結束（EOF）。
2. 建立一個大小為 (len_1 + 1) x (len_2 + 1) 的二維陣列 dp，並全部初始化為 0。其中 dp[i][j] 代表 s1 的前 i 個字元與 s2 的前 j 個字元的最長公共子序列長度。
3. 使用雙層迴圈遍歷兩個字串的所有字元組合（索引從 1 開始）：
    - 如果 s1[i-1] == s2[j-1]，代表目前字元相同，則：
        - dp[i][j] = dp[i-1][j-1] + 1
    - 如果字元不同，則當前最佳解必來自於「忽略 s1 目前字元」或「忽略 s2 目前字元」的兩種情況之一，取其最大值：
        - dp[i][j] = max(dp[i-1][j], dp[i][j-1])
4. 輸出dp[len1][len2]

### Key Insights
- 邊界處理： 將 dp 陣列的第 0 列與第 0 行保留為 0，代表任一字串長度為 0 時，LCS 長度必為 0。這樣可以避免在程式碼中寫一堆 i-1 < 0 的邊界判斷。
## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    while(getline(cin,s1)&&getline(cin,s2)){
        int len1=s1.size();
        int len2=s2.size();

        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }

            }
        }
        cout<<dp[len1][len2]<<endl;

    }

}

```
[source code](./src/s1133343-UVa10450.cpp)

## Complexity Analysis
- **Time Complexity:** O(NxM)
- **Space Complexity:** O(NxM)

## Notes & Reflection
- What challenges did you face?
    - 
    - 
- How would you improve this solution?
    - 
- What did you learn?
    - 理解最長公共子字串概念

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials