# LeetCode 378-Kth Smallest Element in a Sorted Matrix

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 378
- **Problem Title:** Kth Smallest Element in a Sorted Matrix
- **Problem Link:** https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

## 2. Problem Statement in My Own Words
給定一個 n x n 的矩陣 matrix，其中：
- 每一列是遞增排序
- 每一行也是遞增排序
請找出矩陣中第 k 小的元素。

### 輸入
    一個 n x n 的排序矩陣 matrix
    一個整數 k
###　輸出
    矩陣中第 k 小的數字
### 主要限制與規則
- 每一行、每一列皆為升序排列
- 必須找到「第 k 小」，不是第 k 個位置
- 不能直接 flatten 後排序（可行但不是最佳）
### 核心任務
    在排序矩陣中找出：第 k 小的元素

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 把 matrix 攤平成一個 array
- sort
- 回傳第 k 個元素


### 最終策略

1. 把每一行的第一個元素加入 min heap
2. 每次取出最小值
3. 將該元素所在 row 的下一個元素加入 heap
4. 重複 k 次


## 4. Pseudocode
```text
START

建立 min heap

FOR 每一行:
    push 第一個元素 (value, row, col)

REPEAT k-1 次:
    pop 最小值
    若該 row 還有下一個元素:
        push 下一個元素

return heap top

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > pq;

        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int ans = 0;

        while (k--) {
            auto [val, r, c] = pq.top();
            pq.pop();
            ans = val;

            if (c + 1 < n) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }

        return ans;
    }
};
```
**Why it works:**

- 每一行都是排序好的 → 可以當作 sorted list
- min heap 保證每次取出全局最小值
- 每次只擴展「當前 row 的下一個元素」
- 等價於 k-way merge sorted lists
- 不需要完全排序整個 matrix

### Reflection
- What challenges did you face?
    - heap 的設計較抽象
- How would you improve this solution?
    - 練習 heap + matrix 類型題型轉換
- What did you learn?
    - heap 很適合「多來源最小值合併」