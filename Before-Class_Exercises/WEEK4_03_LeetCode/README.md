# LeetCode 48 - Rotate Image

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 48
- **Problem Title:** Rotate Image
- **Problem Link:** https://leetcode.com/problems/rotate-image/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)


## 2. Problem Statement in My Own Words

### 輸入
一個 `n x n` 的二維矩陣 `matrix`

### 輸出
將這個矩陣 **順時針旋轉 90 度（in-place）**

### 主要限制與規則
- 必須 in-place 旋轉（不能開額外矩陣）
- n x n square matrix
- 只能修改原陣列

### 核心任務
將矩陣做 **順時針 90 度旋轉**


## 3. Thinking Logic and Solution Strategy

### 最初想法

- 直覺會想到開一個新 matrix 來存結果
- 或逐點計算 `(i, j) -> (j, n-1-i)`
- 但會違反 in-place 限制或增加空間複雜度


### 最終策略

利用兩個步驟完成旋轉：

1. **Transpose（轉置矩陣）**
   - 將 `matrix[i][j]` 與 `matrix[j][i]` 交換
   - 讓 row/column 對調

2. **Reverse 每一列**
   - 每一 row 做 reverse
   - 完成順時針 90 度旋轉

## 4. Pseudocode

```text
START

n = matrix size

// Step 1: transpose matrix
FOR i from 0 to n-1:
    FOR j from i to n-1:
        swap(matrix[i][j], matrix[j][i])

// Step 2: reverse each row
FOR each row in matrix:
    reverse(row)

RETURN matrix

END
````

## 5. Correct Code

### Correct Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1 transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2 reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

### Why it works:

* Transpose 會把 `(i, j)` 變成 `(j, i)`
* 再 reverse 每一列，相當於：

  * column flip → 變成順時針旋轉效果
* 合起來等價於：

  * `(i, j) → (j, n - 1 - i)`
* 時間複雜度：`O(n^2)`
* 空間複雜度：`O(1)`（in-place）


### Reflection

- What challenges did you face?
    - transpose + reverse 的組合不容易一開始就想到
    - 容易混淆「逆時針 vs 順時針」的變換順序
- How would you improve this solution?
    -  
-  What did you learn?
    - 矩陣旋轉可以拆成：
        - transpose + reverse
