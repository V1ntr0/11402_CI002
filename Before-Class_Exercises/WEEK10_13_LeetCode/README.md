# LeetCode 394 - Decode String

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 394
- **Problem Title:** Decode String
- **Problem Link:** https://leetcode.com/problems/decode-string/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個經過編碼的字串 `s`，格式包含數字、字母以及方括號（例如 `3[a]2[bc]`）。
    
### 輸出
一個解碼後的字串。編碼規則為：`k[encoded_string]` 表示方括號內的 `encoded_string` 必須正好重複 `k` 次。
    
### 主要限制與規則
- `k` 保證為正整數。
- 輸入字串格式總是有效的，沒有多餘的空格，且方括號總是對稱配對。
- 原始資料不包含任何數字，數字只用來表示重複次數。
- 會有巢狀括號的情況（例如 `3[a2[c]]` 應解碼為 `accaccacc`）。

### 核心任務
妥善處理括號的巢狀結構，在遇到閉合括號時，能正確將當前層級的字串依據對應的次數重複，並與上一層的字串無縫拼接。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 由於存在巢狀括號（如內層的 `2[c]` 完結後，要融入外層的 `3[a...]` 中），這代表解碼的順序具有「後進先出（LIFO）」的特性。
- 可以使用雙堆疊（Stack）來維護狀態：一個堆疊 `numStack` 用來存重複次數 `k`，另一個堆疊 `strStack` 用來存遇到 `[` 之前的上一層字串。


### 最終策略
1. 宣告兩個堆疊：`numStack` 與 `strStack`。同時用變數 `num` 記錄當前正在組合的數字，`cur` 記錄當前正在組合的字串。
2. 遍歷字串 `s` 中的每個字元 `c`，分為四種情況處理：
   - **若為數字：** `num = num * 10 + (c - '0')`，用以處理多位數（如 10, 23 等）。
   - **若為 `[`（進入內層）：** 將當前的 `num` 和 `cur` 分別推入各自的堆疊，隨後將兩者清空（`num = 0`, `cur = ""`），開始全新一輪的內層記錄。
   - **若為 `]`（結束內層，準備解碼）：** 從 `numStack` 彈出重複次數 `k`，從 `strStack` 彈出上一層的字串 `prev`。將當前的 `cur` 重複 `k` 次後，拼接在 `prev` 後面，並將新結果更新回 `cur`（此時 `cur` 回到上一層並包含了剛解碼完的內容）。
   - **若為一般字母：** 直接加到當前字串 `cur` 的尾端。
3. 走訪結束後，`cur` 即為最終完整的解碼答案。

## 4. Pseudocode
```text
START
1. Initialize empty stacks numStack and strStack
2. Initialize cur = "", num = 0
3. FOR each character c IN string s:
       IF c is a digit THEN
           num = num * 10 + (c - '0')
       ELSE IF c == '[' THEN
           numStack.push(num)
           strStack.push(cur)
           num = 0
           cur = ""
       ELSE IF c == ']' THEN
           k = numStack.pop()
           prev = strStack.pop()
           temp = ""
           FOR i from 0 to k - 1:
               temp = temp + cur
           END FOR
           cur = prev + temp
       ELSE
           cur = cur + c
       END IF
4. RETURN cur
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        string cur = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '[') {
                numStack.push(num);
                strStack.push(cur);

                num = 0;
                cur = "";
            } 
            else if (c == ']') {
                int k = numStack.top(); numStack.pop();
                string prev = strStack.top(); strStack.pop();

                string temp = "";
                for (int i = 0; i < k; i++) {
                    temp += cur;
                }

                cur = prev + temp;
            } 
            else {
                cur += c;
            }
        }

        return cur;
    }
};
```
**Why it works:**
- **雙堆疊同步狀態：** 透過將數字與字串分開儲存，使得在遇到 `[` 時，可以完美地把外層環境「封存」起來；而在遇到 `]` 時，又能精準地彈出對應的次數與前綴字串。
- **天然支援巢狀結構：** 堆疊的 LIFO 特性保證了解碼順序必定是「由內而外」。最內層的括號會最先遇到 `]` 被解碼，解碼後的字串會融入它的外層，接著當外層遇到 `]` 時就能正確連同內層結果一起重複。
- **連續多位數處理：** `num = num * 10 + (c - '0')` 的邏輯確保了像 `100[a]` 這樣的測資，數字能被完整讀取而不被截斷。

### Reflection
- What challenges did you face?
    - 在處理 `]` 的拼接時需要理清邏輯。當前的 `cur` 代表的是方括號內需要被重複的內容，而彈出的 `prev` 是括號前的文字。必須是 `prev + (cur 重複 k 次)`，順序如果反了答案就會出錯。
- How would you improve this solution?
    - 另一種解法是使用遞迴，但雙堆疊在理解與實作上往往比遞迴更不易發生 Stack Overflow。
- What did you learn?
    - 深刻理解了利用堆疊來儲存「Context Snapshot」的技巧。在面對複雜的字串解析與巢狀結構時，堆疊是暫存狀態並在之後依序回復的最強大工具。