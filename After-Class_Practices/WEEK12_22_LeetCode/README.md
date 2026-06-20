# LeetCode 1022 - Sum of Root To Leaf Binary Numbers

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1022
- **Problem Title:** Sum of Root To Leaf Binary Numbers
- **Problem Link:** https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個二元樹的根節點 `root`，樹上每個節點的數字不是 `0` 就是 `1`。
    
### 輸出
一個整數，代表從根節點走到所有葉子節點，所產生的二進位數字的「十進位總和」。
    
### 主要限制與規則
- 必須一路走到最底部的葉子節點（也就是沒有左右小孩的節點）才算一條完整的路徑。
- 樹的節點最多有 1000 個，節點的值只會是 0 或 1。

### 核心任務
找出所有從頭走到尾的路徑，把路徑上的 0 和 1 串成二進位數字，最後把這些數字全部加起來。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 既然要找從根節點到葉子節點的所有路徑，最直覺的就是用深度優先搜尋（DFS）一路往下走。
- 往下走的過程中，需要一個變數來記住目前一路上累積的二進位值。
- 如果要把舊的二進位值加上新的字元，其實就是把原本的數字乘以 2（往左移一位），再加上當前節點的值。


### 最終策略
1. 寫一個輔助函式 `dfs(node, cur)`，`cur` 用來代表走到目前這格之前，前面已經累積的數值。
2. 如果走到空節點（`!node`），就直接回傳 0。
3. 只要節點有東西，就把目前的累積值更新：`cur = cur * 2 + node->val`。
4. 接著檢查這格是不是最底部的葉子節點（`!node->left && !node->right`）：
   - 如果是，代表這條路徑走完了，直接回傳算好的 `cur`。
5. 如果不是葉子節點，就繼續往左邊和右邊走，最後把左右兩邊回傳的答案加起來。


## 4. Pseudocode
```text
START
1. Define function dfs(node, cur):
       IF node is NULL THEN RETURN 0
       cur = cur * 2 + node.val
       IF node.left is NULL AND node.right is NULL THEN
           RETURN cur
       END IF
       RETURN dfs(node.left, cur) + dfs(node.right, cur)
2. In main function sumRootToLeaf(root):
       RETURN dfs(root, 0)
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int dfs(TreeNode* node, int cur) {
        if (!node) return 0;

        cur = cur * 2 + node->val;
        
        if (!node->left && !node->right) {
            return cur;
        }

        return dfs(node->left, cur) + dfs(node->right, cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
```
**Why it works:**
- **十進位模擬二進位很方便：** `cur = cur * 2 + node->val` 這一行很妙，不需要真的用字串去串接 `0` 和 `1` 之後再轉型。直接乘以 2 就相當於二進位的往左移一位，既省空間又好寫。
- **只在葉子節點結算：** 在 `!node->left && !node->right` 成功攔截，確保只有完整的路徑才會把分數貢獻出來，不會在中間的半路上就重覆加到。
- **遞迴會自動加總：** 最後一行的 `return dfs(...) + dfs(...)` 會把整棵樹所有分支路徑算出來的數字一路往上加回去，最後在根節點拿到總和。
- **時間與空間都很有效率：** 每個節點只會走訪一次，時間複雜度是 $O(n)$。空間複雜度取決於樹的高度，平均狀況下是 $O(\log n)$。

### Reflection
- What challenges did you face?
    - 一開始容易分不清楚「空節點」跟「葉子節點」的返回時機。如果在空節點就直接回傳 `cur`，會因為葉子節點底下有左右兩個空小孩，導致同一條路徑的答案被重複加了兩次。把結算點定在葉子節點就沒這個問題了。
- How would you improve this solution?
    - 
- What did you learn?
    - 複習了利用 DFS 參數傳值來往下傳遞歷史狀態的技巧。這種寫法好處是往下走時數字會自動更新，回溯往上走時舊狀態也不會被弄髒，完全不需要手動去刪除或還原變數。