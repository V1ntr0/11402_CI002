
# UVa 10062 - Tell me the frequencies!
## Problem Description
給定多行輸入，每一行是一個字串。對於每一行，統計每個 ASCII 字元出現的次數，並依照以下規則輸出：

依「出現次數」由小到大排序
若出現次數相同，則依「ASCII 值」由大到小排序

輸出格式為：ASCII碼 次數

每筆測資之間需輸出一個空行（最後一筆除外）。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1003)

## Learning Objectives
- [ ] 熟悉字元頻率統計（Frequency Counting）
- [ ] 理解排序條件（多重排序：頻率 + ASCII）
## Solution Approach

### Algorithm Logic
1. 讀入一整行字串（使用 getline）
2. 使用陣列 count[129] 統計每個 ASCII 字元出現次數
3. 找出所有可能的頻率（從小到大）
4. 對於每個頻率，從 ASCII 大到小檢查字元
5. 若某字元出現次數符合目前頻率，則輸出
6. 注意測資間空行處理

### Key Insights
- 題目本質是「排序 + 計數」，但可以不用真的排序
- 利用「頻率當外層迴圈」可以自然達成排序效果
- ASCII 需從大到小掃描
- count[c]++ 利用了字元的 ASCII 值直接當 index
## Code Structure
```cpp
#include <iostream>
using namespace std;
int main(){
    string line{};
    bool first=true;
    while(getline(cin,line)){
            if(!first)
                cout<<endl;
            first=false;
        int count[129]{};
        for(char c:line){
            count[c]++;
        }
        for(int i=1;i<1000;i++){
            for(int j=128;j>=32;j--){
                if(i==count[j])
                    cout<<j<<" "<<count[j]<<endl;
            }
        }

    }


}
```
[source code](./src/s1133343-UVa10062)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 排序條件（頻率小→大 + ASCII 大→小）要想一下
    - 忘記「不同測資之間要空行」
- How would you improve this solution?
    - 可以用 vector<pair<int,int>> 搭配 sort 實作，更直觀
- What did you learn?
    - 多條件排序可以用「控制迴圈順序」取代 sort
    - 熟悉 ASCII 操作與字元處理技巧

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials