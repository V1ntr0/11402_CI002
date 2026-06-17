# LeetCode 74 - Search a 2D Matrix

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 74
- **Problem Title:** Search a 2D Matrix
- **Problem Link:** https://leetcode.com/problems/search-a-2d-matrix/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個 $m \times n$ 的二維整數矩陣 `matrix`（每一列皆已升序排序，且每一列的第一個整數大於前一列的最後一個整數），以及一個目標值 `target`。
    
### 輸出
一個布林值（`true` 或 `false`），代表 `target` 是否存在於該二維矩陣中。
    
### 主要限制與規則
- 矩陣具有極強的單調遞增特性：如果把矩陣的每一列首尾相連，它會完美形成一個完整的、已排序的一維陣列。
- 必須設計一個時間複雜度為 $O(\log(m \times n))$ 的演算法。

### 核心任務
利用矩陣全局有序的特點，將二維空間映射成一維索引，在對數時間內完成目標值的查找。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 可以先對第一欄進行二分搜尋，定位出目標值可能在哪一列（Row）。
- 接著，再對該列進行一次一維的二分搜尋來尋找 `target`。
- 雖然這樣做也是 $O(\log m + \log n) = O(\log(m \times n))$，但需要寫兩次二分搜尋，邏輯較為繁瑣。


### 最終策略
1. 既然矩陣全局有序，可以直接將這張二維矩陣**虛擬地看作一個長度為 $m \times n$ 的一維陣列**。
2. 建立標準的二分搜尋指針：`left = 0`，`right = m * n - 1`。
3. 每次計算一維的中點索引 `mid`。
4. 關鍵步驟（虛擬索引映射）：利用除法與取餘數，將一維索引 `mid` 轉換回二維矩陣的座標。
   - 列座標：`row = mid / n`（`n` 為矩陣每列的欄數）
   - 欄座標：`col = mid % n`
5. 取出 `matrix[row][col]` 的數值進行標準二分搜尋比較，逐步限縮 `left` 與 `right` 的範圍。


## 4. Pseudocode
```text
START
1. Initialize m = matrix.size(), n = matrix[0].size()
2. Initialize left = 0, right = m * n - 1
3. WHILE left <= right:
       mid = left + (right - left) / 2
       row = mid / n
       col = mid % n
       val = matrix[row][col]
       IF val == target THEN
           RETURN true
       ELSE IF val < target THEN
           left = mid + 1
       ELSE
           right = mid - 1
       END IF
4. RETURN false
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int row = mid / n;
            int col = mid % n;
            
            int val = matrix[row][col];
            
            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
    
};
```
**Why it works:**
- **空間展平思想（Flattening）：** 題目給定的矩陣特性符合全局遞增，因此一維與二維索引存在完美的一對一映射關係。透過 `mid / n` 和 `mid % n` 不需要佔用額外記憶體重新搬移資料，就能在邏輯上做到「一次二分搜尋搞定二維矩陣」。
- **極致的時間效能：** 單次遍歷範圍由 0 到 $m \times n - 1$，時間複雜度完美符合題目要求的 $O(\log(m \times n))$。
- **空間開銷極小：** 完全利用數學索引轉換在原地（In-place）進行搜尋，額外空間複雜度為 $O(1)$。

### Reflection
- What challenges did you face?
    - 在寫索引映射公式時，除數與取餘數的對象必須精準使用「欄數 `n`」（即每一列有幾個元素），若誤用成 `m` 會導致座標計算完全錯亂。
- How would you improve this solution?
    - 
- What did you learn?
    - 學到了如何透過「維度轉換（一維與二維座標映射）」將看似複雜的二維問題，降維轉化成最基礎、最直覺的一維二分搜尋模板。