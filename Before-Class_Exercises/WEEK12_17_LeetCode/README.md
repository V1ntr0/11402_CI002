# LeetCode 110 - Balanced Binary Tree

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 110
- **Problem Title:** Balanced Binary Tree
- **Problem Link:** https://leetcode.com/problems/balanced-binary-tree/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個二元樹的根節點 `root`。
    
### 輸出
一個布林值（`true` 或 `false`），代表這棵二元樹是否為高度平衡（Height-Balanced）的二元樹。
    
### 主要限制與規則
- 高度平衡二元樹的定義：這棵樹中「每一個節點」的左右兩棵子樹，它們的**高度差不能大於 1**。
- 樹的節點數量範圍在 `[0, 5000]` 之間，因此設計的演算法在最差狀況下也需要保持高效。

### 核心任務
在遍歷二元樹的過程中，計算各個子樹的高度，並同步檢查任一節點是否打破了高度差小於等於 1 的平衡規則。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 最直覺的做法是寫一個計算樹高度的函式 `getHeight(node)`。
- 然後主函式對每個節點呼叫 `abs(getHeight(node->left) - getHeight(node->right)) <= 1`，並遞迴檢查左右子樹。
- 但這種 Top-down（自上而下）的方法會導致同一個節點被重複計算高度多次，時間複雜度會劣化到 $O(n^2)$。必須設法在計算高度的同時「順便」回傳是否平衡，做到只遍歷一次。


### 最終策略
1. 採用 **Bottom-up（自下而上）後序走訪** 的優化策略。
2. 設計一個輔助函式 `checkHeight(root)`，它具備雙重功能：
   - 如果子樹是平衡的，回傳該子樹的**真實高度**。
   - 如果子樹不平衡，則回傳一個特殊標記值 `-1`。
3. 進入遞迴後，先求得左子樹高度 `left`。若 `left == -1`，代表左子樹早已不平衡，無需再算右子樹，直接剪枝（Pruning）向外回傳 `-1`。
4. 同理，再求得右子樹高度 `right`。若 `right == -1`，同樣立即回傳 `-1`。
5. 若左右子樹皆平衡，此時比對兩者高度差：
   - 若 `abs(left - right) > 1`，代表當前節點失衡，回傳 `-1`。
   - 若高度差在合理範圍內，則回傳當前節點的真實高度 `1 + max(left, right)`。
6. 主函式只需判斷 `checkHeight(root)` 的最終回傳值是否不等於 `-1` 即可。


## 4. Pseudocode
```text
START
1. Define function checkHeight(node):
       IF node is NULL THEN RETURN 0
       
       left = checkHeight(node.left)
       IF left == -1 THEN RETURN -1
       
       right = checkHeight(node.right)
       IF right == -1 THEN RETURN -1
       
       IF abs(left - right) > 1 THEN 
           RETURN -1
       ELSE
           RETURN 1 + max(left, right)
       END IF
2. In main function isBalanced(root):
       RETURN checkHeight(root) != -1
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
   int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1;

        int right = checkHeight(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
```
**Why it works:**
- **自底向上的單次掃描（Bottom-up）：** 藉由後序走訪（先處理左右子樹，再處理當前節點），高度的計算是從葉子節點一路向上传遞。每個節點只會被訪問一次，時間複雜度優化至 $O(n)$。
- **神奇的 `-1` 錯誤傳遞機制：** 將錯誤標記與樹高融合在同一個 `int` 回傳值中。一旦底層某個小分支失衡回傳 `-1`，這個 `-1` 就會像骨牌效應一樣，透過 `if (left == -1)` 與 `if (right == -1)` 一路快速彈回最上層，完全避免了不必要的後續高度計算（高效剪枝）。
- **完全覆蓋邊界情況：** 當樹為空（`!root`）時，回傳 `0`，主函式正確判定 `0 != -1` 得到 `true`，符合「空樹也是平衡樹」的定義。

### Reflection
- What challenges did you face?
    - 關鍵在於思維要從「一邊算高度、一邊問平不平衡」的兩個獨立行為，融合成「用高度來當作平不平衡的指標」。若沒理清這層關係，很容易寫出 $O(n^2)$ 的重複走訪解法。
- How would you improve this solution?
    - 此解法在時間複雜度 $O(n)$ 與空間複雜度 $O(H)$（$H$ 為樹高，即系統呼叫堆疊深度）上已經是最優的寫法。
- What did you learn?
    - 深刻體會到二元樹 Bottom-up（樹形 DP / 後序遍歷）的強大威力。利用特定無效值（如 `-1`）來進行遞迴過程中的「錯誤狀態回傳與提早剪枝」，是解決複雜樹狀結構檢查時非常高效的設計模式。