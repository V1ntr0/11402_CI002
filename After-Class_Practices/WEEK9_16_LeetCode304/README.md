# LeetCode 304-Range Sum Query 2D - Immutable

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 304
- **Problem Title:** Range Sum Query 2D - Immutable
- **Problem Link:** https://leetcode.com/problems/range-sum-query-2d-immutable/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words
給定一個 2D 矩陣 matrix，需要支援多次查詢：

每次查詢給定左上角 (row1, col1) 和右下角 (row2, col2)，請回傳這個矩形區域內所有數字的總和。

### 輸入
    一個 2D 整數矩陣 matrix
    多次查詢 (row1, col1, row2, col2)
###　輸出
    每次查詢的矩形區域總和
### 主要限制與規則
- matrix 是 immutable（不能修改）
- 查詢次數很多
- 每次查詢需要快速計算
### 核心任務
    在 2D 空間中快速計算：submatrix sum query

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 每次 query 直接雙迴圈加總

### 最終策略
使用「二維前綴和」：
1. 預先建立 prefix matrix
2. prefix[i][j] 表示 (0,0) 到 (i,j) 的總和
3. 利用容斥原理計算任意區間


## 4. Pseudocode
```text
START

建立 prefix 2D array

FOR i:
    FOR j:
        prefix[i][j] =
            matrix[i][j]
            + prefix[i-1][j]
            + prefix[i][j-1]
            - prefix[i-1][j-1]

QUERY:
    return A - B - C + D

END
```
## 5. Correct Code
### Correct Code

```cpp
class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefix.assign(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] =
                    matrix[i - 1][j - 1]
                    + prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1]
             - prefix[row1][col2 + 1]
             - prefix[row2 + 1][col1]
             + prefix[row1][col1];
    }
};
```

### Reflection
- What challenges did you face?
    - 二維 prefix sum 的公式一開始容易混亂
- How would you improve this solution?
    - 
- What did you learn?
    - matrix 題型通常都可以轉換成 prefix / DP 問題