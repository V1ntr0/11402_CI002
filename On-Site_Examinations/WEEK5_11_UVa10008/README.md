
# UVa 10008 - What's Cryptanalysis?
## Problem Description
給定 n 行文字，統計：
- 每個英文字母（A–Z）出現的次數（不分大小寫）
- 忽略所有非英文字元

最後依照以下規則輸出：
- 出現次數 由大到小
- 若次數相同 → 字母 字典序（A→Z）

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949)

## Learning Objectives
- [ ] 字元處理（isalpha, toupper）
- [ ] 排序

## Solution Approach

### Algorithm Logic
1. 讀入整數 n
2. 建立大小為 26 的陣列（A–Z）
3. 對每一行字串：
    - 掃描每個字元，如果是字母：
        - 轉成大寫
        - 對應 index++
4.  排序：
    - 依 count 由大到小
    - 若相同 → id 由小到大
5. 輸出所有 count > 0 的字母

### Key Insights
- 不分大小寫 → 用 toupper() 統一
- 排序規則:「次數優先，其次字母順序」
## Code Structure
```cpp
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Alpha {
    char id;
    int count;
};
bool compare(Alpha a, Alpha b) {
    if (a.count != b.count)
        return a.count > b.count;
    return a.id < b.id;
}
int main() {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    vector<Alpha> data(26);
    for (int i = 0; i < 26; i++) {
        data[i].id = 'A' + i;
        data[i].count = 0;
    }
    while (n--) {
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            char c{};
            c = s[j];
            if (isalpha(c)) {
                data[toupper(c) - 'A'].count++;
            }
        }

    }
    sort(data.begin(), data.end(), compare);
    for (int i = 0; i < 26; i++) {
        if (data[i].count > 0) {
            cout << data[i].id << " " << data[i].count << endl;
        }
    }


}

```
[source code](./src/s1133343-UVa10008)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 大小寫處理
    - 排序條件容易寫錯
- How would you improve this solution?
    - 可以不用 struct，直接用：
        - vector<int> count(26);
    - 再搭配 index 排序
- What did you learn?
    - 如何寫 自訂排序
    - 字串處理的基本技巧（getline, isalpha）

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials