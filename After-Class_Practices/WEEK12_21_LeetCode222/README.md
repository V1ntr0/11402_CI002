# LeetCode 222 - Count Complete Tree Nodes

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 222
- **Problem Title:** Count Complete Tree Nodes
- **Problem Link:** https://leetcode.com/problems/count-complete-tree-nodes/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個「完全二元樹（Complete Binary Tree）」的根節點 `root`。
    
### 輸出
一個整數，代表這棵樹總共有多少個節點。
    
### 主要限制與規則
- 這棵樹保證是完全二元樹。完全二元樹的特點是：除了最後一層外，其他層都是滿的，而且最後一層的節點都靠左排列。
- 題目要求設計一個時間複雜度比 $O(n)$ 還快的演算法。

### 核心任務
利用完全二元樹的幾何特性，不需要把每個節點都走訪一遍，就能在最快時間內算出總節點數。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 最直接的方法是用一般的二元樹走訪（像是 DFS 或 BFS），每看到一個節點就把計數器加 1。
- 雖然這樣寫最簡單，但時間複雜度是 $O(n)$，完全沒有利用到題目給的「完全二元樹」這個條件，不符合題目想追求的速度。


### 最終策略
1. 完全二元樹有一個特性：如果我們從某個節點一直往左走算出的深度，剛好等於一直往右走算出的深度，那這棵子樹就一定是一棵「滿二元樹（Perfect Binary Tree）」。
2. 滿二元樹的節點數可以用數學公式直接算出來。如果深度是 $h$（從 1 開始算），總節點數就是 $2^h - 1$。
3. 這樣我們就可以用遞迴來做：
   - 算左邊最左側的深度 `leftHeight`。
   - 算右邊最右側的深度 `rightHeight`。
   - 如果 `leftHeight == rightHeight`，代表是滿二元樹，直接用公式 $(1 \ll \text{leftHeight}) - 1$ 算出答案回傳，不需要再往下走訪。
   - 如果不相等，代表不是滿二元樹，那我們就只好乖乖退回一般做法：`1 + countNodes(root->left) + countNodes(root->right)`（目前的 1 加上左子樹節點數，再加右子樹節點數）。
4. 因為完全二元樹的特性，左、右子樹切開後，一定會有一邊是滿二元樹。所以每次遞迴都至少有一半會被公式直接解掉，速度會變成 $O(\log n \times \log n)$。


## 4. Pseudocode
```text
START
1. Define function countNodes(node):
       IF node is NULL THEN RETURN 0
       
       Initialize leftHeight = 0, rightHeight = 0
       Initialize curr = node
       WHILE curr is not NULL:
           leftHeight = leftHeight + 1
           curr = curr.left
       END WHILE
       
       curr = node
       WHILE curr is not NULL:
           rightHeight = rightHeight + 1
           curr = curr.right
       END WHILE
       
       IF leftHeight == rightHeight THEN
           RETURN (1 << leftHeight) - 1
       ELSE
           RETURN 1 + countNodes(node.left) + countNodes(node.right)
       END IF
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = 0;
        int rightHeight = 0;

        TreeNode* leftNode = root;
        while (leftNode) {
            leftHeight++;
            leftNode = leftNode->left;
        }

        TreeNode* rightNode = root;
        while (rightNode) {
            rightHeight++;
            rightNode = rightNode->right;
        }

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
**Why it works:**
- **利用位元運算加速**：公式中的 $2^h$ 直接寫成 `1 << leftHeight`，用位元左移代替乘法，速度非常快。
- **大量的剪枝效果**：只要發現某一棵子樹是滿的，直接用公式回傳，那一整棵子樹底下的成千上萬個節點都不用再派人去數，省下了大量的時間。
- **符合時間限制**：每次計算深度需要 $O(\log n)$，而樹的每一層最多只會遇到一個不滿的節點。遞迴總共會走 $O(\log n)$ 層，所以總時間複雜度是 $O((\log n)^2)$，遠快於常規的 $O(n)$。

### Reflection
- What challenges did you face?
    - 一開始在算深度時，要注意是從 0 開始還是從 1 開始。這裡如果把空節點當作 0，有節點時算 1，那公式就是 `(1 << height) - 1`。如果高度沒對齊，位元移位算出來的數字就會差兩倍，需要小心測試。
- How would you improve this solution?
    - 如果想把時間複雜度再壓低，可以結合二分搜尋法來直接對最後一層的最底層節點做檢測，不過寫法會複雜很多。
- What did you learn?
    - 學到了完全二元樹與滿二元樹之間的幾何連結。以前覺得數節點只能一個個數，這次知道只要利用樹的結構特性搭配數學公式，就能做到跨越節點的大幅度跳躍計數。