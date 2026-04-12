
# UVa 11063 - B2-Sequence
## Problem Description
給定一個整數序列，判斷它是否為 B2-Sequence。條件如下：
1. 所有數字皆為正整數（> 0）
2. 序列必須嚴格遞增
3. 任意兩個元素（可相同位置，即 i ≤ j）的和都必須 唯一（不能重複）
若符合以上條件，輸出：
- It is a B2-Sequence.
否則輸出：
- It is not a B2-Sequence.

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2004)

## Learning Objectives
- [ ] 理解序列驗證（Sequence Validation）
- [ ] 學習利用排序與檢查重複來解決問題
## Solution Approach

### Algorithm Logic
1. 讀入整數 n
2. 讀入序列 b[i]
3. 檢查：
    - 是否所有數字 > 0
    - 是否嚴格遞增（b[i] > b[i-1]）
4. 若前面條件成立：
    - 列舉所有 b[i] + b[j]（i ≤ j）
    - 存入 vector
5. 將所有和排序
6. 檢查是否有重複的和
7. 根據結果輸出答案
### Key Insights
- 「嚴格遞增」是必要條件，可以提前檢查
- 「所有 pair sum 必須唯一」
- i ≤ j 代表包含自己加自己（例如 b[i] + b[i]）
## Code Structure
```cpp
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int n,b[105],casenum=1;
    while(cin>>n){
        bool isb2=true;
        for(int i=0;i<n;i++){
            cin>>b[i];
        if(b[i]<1||(i>0&&b[i]<=b[i-1]))
            isb2=false;
        }
        if(isb2){
            vector<int> sums;
            for(int i=0;i<n;i++)
                for(int j=i;j<n;j++)
                    sums.push_back(b[i]+b[j]);
            sort(sums.begin(),sums.end());
            for(int i=0;i<(int)sums.size()-1;i++)
                if(sums[i]==sums[i+1]){
                isb2=false;
                break;
                }
        }
        cout<<"Case #"<<casenum++<<":"<<(isb2?" It is a B2-Sequence.":" It is not a B2-Sequence.")<<endl<<endl;
    }
}

```
[source code](./src/s1133343-UVa11063)

## Complexity Analysis
- **Time Complexity:** O(n² log n)
- **Space Complexity:** O(n²)

## Notes & Reflection
- What challenges did you face?
    - 容易漏掉「可以自己加自己（i ≤ j）」這個條件
    - 輸出格式（Case 編號 + 空行）容易出錯
    - 輸出完後還要多換行一次
- How would you improve this solution?
    - 可以用 set 在生成 sums 時直接檢查重複（避免排序）
- What did you learn?
    - 熟悉「兩兩組合（pair）」問題的處理方式
    - 理解如何逐步驗證多條件問題

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials