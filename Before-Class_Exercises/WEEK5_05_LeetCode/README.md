# LeetCode 179 - Largest Number

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 179
- **Problem Title:** Largest Number
- **Problem Link:** https://leetcode.com/problems/largest-number/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個非負整數陣列 `nums`。
    
### 輸出
一個字串，將所有數字重新排列組合後能拼湊出的「最大整數」。
    
### 主要限制與規則
- 數字可能非常大，因此結果必須以字串（string）形式回傳。
- 不能只依照數字大小或字典序單獨排序（例如 30 和 3，3 應該排在 30 前面才能拼成 330，而不是 303）。
- 注意多個 0 的邊界情況。

### 核心任務
尋找一個正確的自訂排序規則，讓任兩個數字組合時都能產生最大的排序結果。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 將數字轉為字串後按字典序排序，但發現無法處理長度不同時的特殊組合（如 "30" 與 "3"）。
- 單純比較單個字元大小會失效，必須比較兩者相加後的最終字串。


### 最終策略
1. 將 `nums` 內所有整數轉換為字串陣列 `strs`。
2. 設計自訂比較函式 `cmp`：若 `a + b > b + a`，則 `a` 排在 `b` 前面。
3. 使用 `sort` 對 `strs` 進行排序。
4. 檢查特殊邊界：若排序後第一個元素為 "0"，代表整體皆為 0，直接回傳 "0"。
5. 將排序後的字串依序拼接成 `result` 並回傳。


## 4. Pseudocode
START
1. Convert all integers in nums to strings and store in strs.
2. Define custom comparator cmp(a, b):
       RETURN (a + b) > (b + a)
3. Sort strs using cmp.
4. IF strs[0] == "0" THEN
       RETURN "0"
5. Initialize result = ""
6. FOR each s IN strs:
       result = result + s
7. RETURN result
END

## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strs;

        // 轉成字串
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        // 自訂排序
        sort(strs.begin(), strs.end(), cmp);

        // 特殊情況：全部都是 0
        if (strs[0] == "0") return "0";

        // 拼接答案
        string result = "";
        for (string s : strs) {
            result += s;
        }

        return result;
    }
};
```
**Why it works:**
- 自訂排序邏輯（`a + b > b + a`）直接模擬了兩數字拼接後的實際大小，具備傳遞性，能確保整體排序最優。
- 轉字串處理避開了整數型態溢位（Overflow）的問題。
- `strs[0] == "0"` 判斷式有效防範了例如 `[0, 0]` 輸出成 `"00"` 的錯誤，正確輸出 `"0"`。

### Reflection
- What challenges did you face?
    - 一開始卡在長度不同的字串比較（如 34 和 3），後來發現直接把兩字串相加比大小最直覺。
- How would you improve this solution?
    - 目前的時間複雜度為 $O(n \log n \times k)$（$k$ 為字串平均長度），已是本題最優解法。
- What did you learn?
    - 自訂 `sort` 的比較函式時，直接以「目標組合結果」作為比較依據，可以非常優雅地解決複雜的貪婪（Greedy）排序問題。