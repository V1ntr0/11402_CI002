# LeetCode 347-Top K Frequent Elements

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 347
- **Problem Title:** Top K Frequent Elements
- **Problem Link:** https://leetcode.com/problems/top-k-frequent-elements/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

## 2. Problem Statement in My Own Words
給定一個整數陣列 nums 和整數 k，請找出出現頻率最高的 k 個元素。

### 輸入
    一個整數陣列 nums
    一個整數 k
###　輸出
    出現次數最多的 k 個元素（順序不限）
### 主要限制與規則
- 元素可能重複
- 需要依照「出現頻率」排序
- 只需要回傳前 k 個高頻元素
### 核心任務
    找出：Top K Frequent Elements

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 先 sort
- 再數頻率

### 最終策略

1. Hash Map 計算頻率
2. Min Heap 維護 top k frequency

核心想法
- 用 unordered_map 記錄 freq
- 用 min heap 保留前 k 高頻元素
- 超過 k 就 pop 掉最小頻率

## 4. Pseudocode
```text
START

建立 freq map

FOR num in nums:
    freq[num]++

建立 min heap (frequency, num)

FOR 每個 (num, freq):
    push (freq, num)
    if size > k:
        pop

取出 heap 所有元素 → result

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto& [num, f] : freq) {
            pq.push({f, num});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
```
**Why it works:**

- unordered_map 建立 frequency table
- heap 保持 size ≤ k
- min heap 保留的是「目前最不重要的 k 個」
- 超過 k 時刪掉最低頻率 → 保留 top k
- 最終 heap 中就是答案集合

### Reflection
- What challenges did you face?
    - 容易混淆「排序全部」與「只保留前 k」
- How would you improve this solution?
    - 可以再優化成 bucket sort
- What did you learn?
    - hash map + heap 是頻率問題標準組合