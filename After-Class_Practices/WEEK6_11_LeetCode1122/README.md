# LeetCode 1122-

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1122
- **Problem Title:** Relative Sort Array
- **Problem Link:** https://leetcode.com/problems/relative-sort-array/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words
給定兩個陣列 arr1 和 arr2。

要求依照 arr2 的順序來重新排序 arr1：
- arr1 中出現在 arr2 的元素，必須依照 arr2 的順序排列
- 沒出現在 arr2 的元素，放在最後
- 最後這些剩餘元素要按照升序排列

### 輸入
    整數陣列 arr1
    整數陣列 arr2
###　輸出
    重新排序後的 arr1
### 主要限制與規則
- arr2 中的順序是優先排序依據
- arr1 中未出現在 arr2 的元素要排序在後面（升序）
- 不能改變 arr2 的順序
### 核心任務
    將 arr1 依照：arr2 priority + remaining sorted進行排序。

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 直接 sort arr1
- 再依照 arr2 去調整順序


### 最終策略
使用 counting / hash map：
1. 用 map 記錄 arr1 每個數字出現次數
2. 依照 arr2 順序輸出對應數字
3. 剩下沒出現在 arr2 的數字收集起來
4. 對剩餘數字排序後輸出


## 4. Pseudocode
```text
START

count map = frequency of arr1

result = empty list

FOR num in arr2:
    append num (count times) to result
    remove from map

collect remaining numbers:
    sort them
    append to result

return result

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;

        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;

        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        vector<int> rest;
        for (auto& [num, count] : freq) {
            while (count--) {
                rest.push_back(num);
            }
        }

        sort(rest.begin(), rest.end());

        for (int x : rest) {
            ans.push_back(x);
        }

        return ans;
    }
};
```
**Why it works:**

- unordered_map 記錄所有元素出現次數
- 先依照 arr2 排序輸出（保證優先順序）
- 剩餘元素不在 arr2 → 單獨收集
- 對剩餘元素排序保證升序
- 最後合併結果

### Reflection
- What challenges did you face?
    - 忘記 arr2 是「優先級排序」，不是一般排序條件
- How would you improve this solution?
    - 減少 map + sort，改用 array frequency table
- What did you learn?
    - 學會使用unordered_map