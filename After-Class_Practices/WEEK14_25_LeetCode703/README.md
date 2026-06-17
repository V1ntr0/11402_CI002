# LeetCode 703-Kth Largest Element in a Stream
Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 703
- **Problem Title:** Kth Largest Element in a Stream
- **Problem Link:** https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words
設計一個資料結構，能持續接收數字 stream，並且每次加入新數字後，都能回傳目前第 k 大的數字。

### 輸入
    一個固定的 k
    初始陣列 nums
    不斷加入的新數字 val
###　輸出
    每次 add(val) 後回傳目前第 k 大元素
### 主要限制與規則
- 資料會持續更新（stream）
- 每次查詢都要快速
- 不能每次重新排序整個陣列（會 TLE）
### 核心任務
    

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 不能每次重新排序整個陣列（會 TLE）
- 然後 sort 整個 array
- 再取第 k 大

### 最終策略
只需要保留「前 k 大的元素」，其餘不用管。
用 min heap：
- heap size 永遠 ≤ k
- heap top = 第 k 大元素
## 4. Pseudocode
```text
START

建立 min heap

初始化：
    將 nums 放入 heap
    若 size > k → pop

add(val):
    push val
    若 size > k → pop
    return heap top

END
```
## 5. Fail Code vs Correct Code
### Fail Code
```cpp
class KthLargest {
public:
    vector<int> nums;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
    }

    int add(int val) {
        nums.push_back(val);

        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];
    }
};
```
**Why it failed:**
- 每次 add 都要 sort → O(n log n)
- stream 越來越長 → 直接 TLE
- 沒有利用「只需要 top k」的特性
### Correct Code
```cpp
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int x : nums) {
            pq.push(x);

            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};
```
**Why it works:**
- heap 只維持 k 個元素
- push/pop 都是 O(log k)
- 每次直接取 pq.top() = 第 k 大
- 避免整體排序
## 6. Difference and Reflection

### Key Differences



| Item | Fail Code | Correct Code |

|---|---|---|

| Logic | 每次加入元素後重新排序整個陣列，依賴完整排序結果 | 只維護前 k 大元素，用 min heap 動態更新 |

| Edge Cases | 忽略 stream 持續增長時的效率問題，資料越大越慢 | 忽略 stream 持續增長時的效率問題，資料越大越慢 |

| Output Handling | 每次從排序後陣列取第 k 大元素（nums[k-1]） | 直接從 heap top 取得第 k 大元素 |

| Other | 時間複雜度 O(n log n)，會 TLE | 時間複雜度 O(log k)，適合 stream 資料結構 |


### Reflection
- What challenges did you face?
    - 不熟 heap 在 ranking 題的用途
- How would you improve this solution?
    - 
- What did you learn?
    - 不熟 heap 在 ranking 題的用途
    - 不需要全部資料，只需要關鍵 k 個