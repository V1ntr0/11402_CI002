# LeetCode 658 - Find K Closest Elements

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 658
- **Problem Title:** Find K Closest Elements
- **Problem Link:** https://leetcode.com/problems/find-k-closest-elements/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個已排序好的整數陣列 `arr`，以及兩個整數 `k`（欲尋找的元素個數）與 `x`（目標基準值）。
    
### 輸出
一個包含 `k` 個元素的整數陣列，且這 `k` 個元素必須是陣列中距離 `x` 最近的數字。結果也必須是由小到大排序好的。
    
### 主要限制與規則
- 距離定義：`a` 到 `x` 的距離為 `|a - x|`。
- 如果兩個數字與 `x` 的距離相同，則數值較小者優先（例如 `|a - x| == |b - x|` 且 `a < b`，則選擇 `a`）。
- `arr` 已經是升序排序好的。

### 核心任務
在已排序的陣列中，找出一個長度為 `k` 的連續子陣列，使得該子陣列內的所有元素與 `x` 的距離總和或個體距離為最小。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 先用二分搜尋法找到最接近 `x` 的位置，接著使用雙指針（向左與向右擴展）逐步挑選出 `k` 個最近的元素。
- 或者，直接使用雙指針從陣列兩端往中間縮減，直到陣列長度剩下 `k` 為止。
- 雖然可行，但這兩種方法在最差情況下仍需要 $O(k)$ 或 $O(n)$ 的時間來移動指針。


### 最終策略
1. 換個角度思考：由於答案一定是長度為 `k` 的連續區間，我們可以改為**對「區間的起始點 `left`」進行二分搜尋**。
2. 區間起點 `left` 的可能範圍是 `[0, arr.size() - k]`。
3. 每次取中點 `mid`，我們比較「`mid` 位置的元素」與「`mid + k` 位置的元素」誰距離 `x` 更近。
4. 如果 `x - arr[mid] > arr[mid + k] - x`，代表 `mid` 距離 `x` 太遠，且 `mid + k` 更靠近 `x`（或者平手時選右邊不符合題意），因此最佳區間的起點必定在 `mid` 的右方，令 `left = mid + 1`。
5. 反之，代表 `mid` 比 `mid + k` 更靠近 `x`（或兩者平手，依規則優先選左邊的 `mid`），所以最佳起點在 `mid` 或其左方，令 `right = mid`。
6. 當二分搜尋結束，`left` 就是最佳連續區間的起點，直接截取 `[left, left + k]` 的範圍即為答案。


## 4. Pseudocode
```text
START
1. Initialize left = 0
2. Initialize right = arr.size() - k
3. WHILE left < right:
       mid = (left + right) / 2
       IF (x - arr[mid]) > (arr[mid + k] - x) THEN
           left = mid + 1
       ELSE
           right = mid
       END IF
4. RETURN a new vector extracted from arr from index left to left + k
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
```
**Why it works:**
- **精準縮小起點範圍：** 傳統二分搜尋找元素，此解法則是利用二分搜尋直接定位「長度為 k 的視窗起點」，使時間複雜度優化至驚人的 $O(\log(n - k))$。
- **完美的邊界權重比較：** `x - arr[mid] > arr[mid + k] - x` 這個判斷式非常優雅。它不開根號也不用 `abs`，直接利用已排序的特性比較視窗左邊界外（`mid`）與右邊界外（`mid + k`）的相對距離，決定視窗該往哪邊滾動。
- **內建符合平手規則：** 當兩端距離相等時，因不滿足 `>` 條件，會走 `else` 分支將 `right` 設為 `mid`，這完美符合了題目「距離相同時，優先選擇數值較小（左邊）元素」的規定。

### Reflection
- What challenges did you face?
    - 區間二分搜尋法的抽象邏輯較難直覺想到。一開始容易陷入如何擴展雙指針的思維，忽略了「排好序的陣列中，k 個最近元素必定形成連續區間」進而對區間起點進行二分的進階技巧。
- How would you improve this solution?
    - 當前解法在時間 $O(\log(n - k))$ 與額外空間 $O(1)$ 上已是極致最優解。
- What did you learn?
    - 學到了二分搜尋法的變形應用：不只可以用來找單一數值，還可以用來在有序空間中尋找「滿足特定邊界關係的連續區間起點」。