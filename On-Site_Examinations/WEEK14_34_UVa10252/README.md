# UVa 10252 - Common Permutation
## Problem Description
給定兩個由小寫英文字母組成的字串 a 和 b，找出一個最長的字串 x，使得 x 同時是 a 的排列（子集）也是 b 的排列（子集）。輸出的字串 x 必須依照 字典順序（a-z） 排列。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1193)

## Learning Objectives
- [ ] 熟悉處理包含空字行的輸入
- [ ] 掌握如何使用 頻率陣列來統計字元
## Solution Approach

### Algorithm Logic
1. 使用 getline 讀取每一行
2. 宣告兩個長度為 128 的整數陣列，分別統計字串 s1 與 s2 中每個字母出現的次數。
3. 遍歷字母 'a' 到 'z'，取字母在結果字串中出現的次數的交集
4. 算出的最小次數，將該字元印出來。

### Key Insights
- 自動排序： 因為是從 'a' 遍歷到 'z'，所以輸出的字元自然會符合字典順序，不需要額外呼叫 sort()。
- UVa 的測資中，字串可能是空的，使用 while(getline(cin, s1) && getline(cin, s2)) 能確保正確讀取。
## Code Structure
```cpp 
//modify
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        int count1[128] = {0};
        int count2[128] = {0};

        for (char c : s1) {
            count1[(int)c]++;
        }
        for (char c : s2) {
            count2[(int)c]++;
        }

        for (int i = 'a'; i <= 'z'; i++) {
            int common = min(count1[i], count2[i]);
            for (int j = 0; j < common; j++) {
                cout << (char)i;
            }
        }
        cout << endl;
    }
    return 0;
}

```
[source code](./src/s1133343-UVa10252.cpp)

## Complexity Analysis
- **Time Complexity:** O(n+m)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 忘記怎麼取字串
- How would you improve this solution?
    - 目前使用 128 大小的陣列是為了方便直接用 ASCII code 當索引，若空間極度受限，可減去 'a' 改用大小 26 的陣列。
- What did you learn?
    - 當處理對象是英文字母且需要排序時，計數排序 的思想通常比直接 sort() 更快且更簡潔。

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials