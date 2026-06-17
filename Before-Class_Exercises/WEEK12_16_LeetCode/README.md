# LeetCode 1022 - Sum of Root To Leaf Binary Numbers

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1022
- **Problem Title:** Sum of Root To Leaf Binary Numbers
- **Problem Link:** https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個二元樹的根節點 `root`，樹上的每個節點數值非 `0` 即 `1`。
    
### 輸出
一個整數，代表所有「從根節點到葉子節點」所形成的所有二進位數值的十進位總和。
    
### 主要限制與規則
- 必須是從根節點（Root）一路走到葉子節點（Leaf，即沒有左右子節點的節點）才算一條完整的路徑。
- 路徑上經過的 0 與 1 依序串接起來，代表一個二進位數字。

### 核心任務
遍歷二元樹的每條路徑，在向下的過程中動態計算累積的二進位值，並在到達葉子節點時將數值累加起來。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 只要是走訪二元樹從根到葉子的所有路徑，最直覺的就是使用**深度優先搜尋（DFS）**。
- 在向下傳遞的過程中，需要有一個變數去記錄從根節點到當前節點所代表的二進位數值。二進位每往下一層，就相當於把先前的數值向左位移一位（乘以 2），然後加上當前節點的值。


### 最終策略
1. 設計一個輔助函式 `dfs(node, cur)`，其中 `cur` 代表從根節點走到當前節點父位置時，已經累積的二進位數值（十進位表示）。
2. 如果目前節點為空（`!node`），直接回傳 0。
3. 更新當前累積值：`cur = cur * 2 + node->val`（如同二進位字串左移一位後加入新字元）。
4. 檢查當前節點是否為葉子節點（`!node->left && !node->right`）：
   - 如果是葉子節點，代表這條路徑已經完整結束，直接回傳當前計算出的 `cur`。
5. 如果不是葉子節點，則繼續往左右子樹遞迴，並將左右子樹回傳的總和加總：`dfs(node->left, cur) + dfs(node->right, cur)`。


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
- **動態進位處理：** `cur = cur * 2 + node->val` 的操作非常精妙。它利用十進位模擬二進位的左移。例如路徑 `1 -> 0 -> 1`，第一層 `cur = 1`，第二層 `cur = 1 * 2 + 0 = 2`，第三層 `cur = 2 * 2 + 1 = 5`（二進位 `101` 剛好等於 5），不需要開闢字串陣列再去做轉換。
- **直覺的轉折與返回點：** 只有在滿足葉子節點條件時才返回有效的路徑總和。對於非葉子節點，則利用分治法（Divide and Conquer）的思想，將左子樹所有的路徑和加上右子樹所有的路徑和，最後在根節點得到全局總和。
- **時空複雜度優良：** 每個節點僅被訪問一次，時間複雜度為 $O(n)$；空間複雜度取決於遞迴時的系統堆疊深度，最差情況下（樹呈現鏈狀）為 $O(n)$，平均狀況下（平衡樹）為 $O(\log n)$。

### Reflection
- What challenges did you face?
    - 需要清楚分開「空節點（!node）」與「葉子節點（!node->left && !node->right）」的返回邏輯。若在空節點就回傳 `cur`，會導致每一條走到葉子的路徑因為有左右兩個空子節點而被重複計算兩次。本解法在葉子節點就提早攔截並返回，完全避免了這個問題。
- How would you improve this solution?
    - 目前的解法在時間、空間和可讀性上已達到最優。在寫法上，也可以把 `cur * 2` 改寫為位元運算 `(cur << 1) | node->val`，雖然效能上編譯器通常會自動優化成一樣的底層組合語言，但位元運算更貼近二進位題目本質。
- What did you learn?
    - 學會了在二元樹 DFS 遍歷中，透過函數參數（傳值）來向下傳遞「路徑歷史狀態」的技巧。這種做法不需要手動進行回溯（Backtracking）清除狀態。