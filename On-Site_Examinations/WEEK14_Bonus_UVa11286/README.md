# UVa 11286 - Conformity
## Problem Description
大一新生有 5 門選修課。給定 n 位學生的選課組合，每位學生選 5 門課。如果某個選課組合被選中的次數最多，則該組合是「最受歡迎」的。題目要求統計所有選了最受歡迎組合的人數總和。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2261)

## Learning Objectives
- [ ] 學習使用 std::map<vector<int>, int> 進行複雜資料的計數
- [ ] 理解如何處理多組「最高頻率」並累加人數
## Solution Approach

### Algorithm Logic
1. 讀入整數 n
2. 讀入每位學生的 5 門課後，進行排序
3. 使用 map<vector<int>, int> counts紀錄該組合出現次數
4. 使用 max_f 紀錄目前出現最多次的次數
5. 遍歷整個統計表，只要某個組合的出現次數等於 max_f，就把該次數加進總人數
6. 輸出總人數

### Key Insights
- 需要把課排序:{1, 2, 3, 4, 5} 和 {5, 4, 3, 2, 1} 是同一種選課組合，如果不排序，map 會把它們當作不同的東西
- map 幫我們自動處理了「分類」與「數數」的工作。當我們寫 counts[courses]++ 時，它會自動找到那個組合並把次數加 1
## Code Structure
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        map<vector<int>, int> counts;
        int max_f = 0;

        for (int i = 0; i < n; i++) {
            vector<int> courses(5);
            for (int j = 0; j < 5; j++) cin >> courses[j];
            sort(courses.begin(), courses.end());
            
            counts[courses]++;
            max_f = max(max_f, counts[courses]);
        }

        int total_popular = 0;
       for (pair<vector<int>, int> p : counts) {
            if (p.second == max_f) {
                total_popular += p.second;
        }
}
        cout << total_popular << endl;
    }
    return 0;
}
```
[source code](./src/s1133343-UVa11286.cpp)

## Complexity Analysis
- **Time Complexity:** O(n logn)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 看不懂題目要幹嘛
- How would you improve this solution?
    - 可以把 5 門課轉成一個長字串或 long long 數字來加速
- What did you learn?
    - 學習 map 的遍歷寫法，了解如何從 pair 中提取出 second
    - 學會了用 std::map 處理「非單一數字」的統計問題

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials