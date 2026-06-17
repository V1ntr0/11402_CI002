# LeetCode 1700 - Number of Students Unable to Eat Lunch

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1700
- **Problem Title:** Number of Students Unable to Eat Lunch
- **Problem Link:** https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
兩個整數陣列：`students`（學生對三明治的喜好，0 代表圓形，1 代表方形）與 `sandwiches`（三明治堆疊，0 代表圓形，1 代表方形）。
    
### 輸出
一個整數，代表最終有多少位學生無法吃到午餐。
    
### 主要限制與規則
- 學生排成一個佇列（Queue），三明治則疊成一個堆疊（Stack）。
- 如果排在最前面的學生喜歡最上面的三明治，該學生會拿走三明治並離開佇列。
- 如果不喜歡，該學生會離開隊伍並重新排到佇列的最後方。
- 這個過程會持續進行，直到最上面的三明治沒有任何排隊中的學生想要為止。

### 核心任務
模擬或推導出何時會發生「死鎖（Deadlock）」，即最上層的三明治與所有剩餘學生的喜好皆不符合，進而統計出無法用餐的人數。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 建立一個實際的 `queue` 模擬學生排隊，並用一個指標去遍歷三明治。
- 每次比對隊頭與三明治，符合就彈出，不符合就將隊頭移到隊尾。
- 必須計算連續不符合的次數，當連續失敗次數等於當前隊伍人數時，代表大家都拒絕這塊三明治，模擬結束。
- 雖然直覺，但這種模擬法包含大量的搬移操作。


### 最終策略
1. 換個角度思考：由於不喜歡三明治的學生可以**無限次重新排到隊尾**，這意味著學生的「排隊順序」其實根本不重要，重要的是「剩下多少個喜歡 0 的學生」與「剩下多少個喜歡 1 的學生」。
2. 首先，走訪 `students` 陣列，統計出喜歡圓形（0）與方形（1）的學生總數，分別記錄在 `cnt0` 與 `cnt1`。
3. 接著，由上往下依序檢視三明治堆疊 `sandwiches`：
   - 如果當前三明治是圓形（0）：檢查是否還有喜歡圓形的學生（`cnt0 > 0`）。如果有，因為該學生遲早會繞到最前面把它拿走，所以直接 `cnt0--`；若此時 `cnt0 == 0`，代表剩下的人全都要方形，這塊圓形三明治永遠沒人要，隊伍卡死，直接回傳剩下的方形學生數 `cnt1`。
   - 如果當前三明治是方形（1）：同理，若 `cnt1 > 0` 則 `cnt1--`；若 `cnt1 == 0`，代表圓形學生全數卡死，直接回傳 `cnt0`。
4. 若所有三明治都順利被拿完，則回傳 0。


## 4. Pseudocode
```text
START
1. Initialize cnt0 = 0, cnt1 = 0
2. FOR each s IN students:
       IF s == 0 THEN cnt0 = cnt0 + 1
       ELSE cnt1 = cnt1 + 1
       END IF
3. FOR each s IN sandwiches:
       IF s == 0 THEN
           IF cnt0 == 0 THEN RETURN cnt1
           cnt0 = cnt0 - 1
       ELSE
           IF cnt1 == 0 THEN RETURN cnt0
           cnt1 = cnt1 - 1
       END IF
4. RETURN 0
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt0 = 0, cnt1 = 0;

        for (int s : students) {
            if (s == 0) cnt0++;
            else cnt1++;
        }

        for (int s : sandwiches) {
            if (s == 0) {
                if (cnt0 == 0) return cnt1;
                cnt0--;
            } else {
                if (cnt1 == 0) return cnt0;
                cnt1--;
            }
        }

        return 0;
    }
};
```
**Why it works:**
- **打破常規的計數優化（Counting Approach）：** 洞察到佇列的循環特性使得學生的相對順序不影響最終結果，將 $O(n^2)$ 的模擬問題，降維成 $O(n)$ 的計數配對問題。
- **精準抓出停止邊界：** 三明治是強制卡死在頂端動彈不得的。一旦發現最上面的三明治類型的喜好計數已經歸零，就代表整個系統發生永久死鎖，此時另一種類型的學生人數就是被卡住、無法吃飯的人數。
- **極致的空間與時間：** 只需要兩次單層的線性掃描，時間複雜度為 $O(n)$，僅使用兩個常數變數，額外空間複雜度為 $O(1)$。

### Reflection
- What challenges did you face?
    - 題目用文字包裝了 Queue 和 Stack 的操作，一開始極容易去寫真實的資料結構模擬，耗費時間與空間。
- How would you improve this solution?
    -  
- What did you learn?
    - 學到了「抽象化」的重要性。當一個佇列具備「不符合條件就無限退回隊尾重新排隊」的性質時，它的本質就會轉化為一個與順序無關的集合（Set / Bag），利用計數法往往能寫出解法。