# LeetCode 148-Sort List

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 148
- **Problem Title:** Sort List
- **Problem Link:** https://leetcode.com/problems/sort-list/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

## 2. Problem Statement in My Own Words
給定一個單向鏈結串列 head，請將所有節點按照升序排序。

### 輸入
    一個 linked list 的 head 節點
###　輸出
    排序後的 linked list（由小到大）
### 主要限制與規則
- 必須在 O(n log n) 時間內完成
- 不能使用額外陣列做排序（或空間需很小）
- 只能調整節點，不是重新建立整條 list
### 核心任務
    對 linked list 進行排序，使其變成：從小到大排列的 linked list

## 3. Thinking Logic and Solution Strategy
### 最初想法


- 把 linked list 轉成 array
- 用 sort 排序
- 再轉回 linked list


### 最終策略

1. 將 linked list 分成兩半
2. 遞迴排序左半與右半
3. 再把兩個排序好的 list 合併


## 4. Pseudocode
```text
START

IF head 為空 or 只有一個節點:
    return head

1. 計算 linked list 長度 n
2. 找到中點 mid
3. 將 list 切成 left 和 right

4. left = sortList(left)
5. right = sortList(right)

6. return merge(left, right)

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }

        int mid = n / 2;

        cur = head;
        for (int i = 1; i < mid; i++) {
            cur = cur->next;
        }

        ListNode* right = cur->next;
        cur->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* t = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                t->next = a;
                a = a->next;
            } else {
                t->next = b;
                b = b->next;
            }
            t = t->next;
        }

        t->next = a ? a : b;
        return dummy.next;
    }
};
```
**Why it works:**

- 使用 Merge Sort，符合 O(n log n)
- 每次將 linked list 平均切成兩半
- 遞迴排序確保子問題有序
- merge step 將兩個 sorted list 合併成完整 sorted list
- 整體流程符合 divide and conquer

### Reflection
- What challenges did you face?
    - 找中點與切割 list 容易出錯
- How would you improve this solution?
    - 可以改成 fast & slow pointer 找中點，不用先算長度
    - 加強 pointer 操作穩定性
- What did you learn?
    - linked list 排序的標準解法就是 merge sort