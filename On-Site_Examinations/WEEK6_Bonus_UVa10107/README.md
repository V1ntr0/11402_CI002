
# UVa 10107 - What is the Median?
## Problem Description
持續讀入整數序列，每讀入一個數字，就輸出目前所有數字的「中位數（median）」。
- 若目前數量為奇數 → 輸出中間那個數
- 若為偶數 → 輸出中間兩個數的平均（整數除法）

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1048)

## Learning Objectives
- [ ] 理解中位數（Median）的定義
- [ ] 
## Solution Approach

### Algorithm Logic
1. 持續讀入整數 n
2. 將 n 加入 vector 中
3. 將 vector 排序
4. 計算目前元素數量 size
5. 若為奇數 → 直接輸出中位數
6. 若為偶數 → 輸出中間兩數平均

### Key Insights
- 中位數必須在「排序後」才能取得
## Code Structure
```cpp
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int n;
    vector <int> line;
    while(cin>>n){
        line.push_back(n);
        if(line.size()==1){
            cout<<n<<endl;
            continue;
        }
        sort(line.begin(),line.end());
        int m=line.size()/2;
        if(line.size()%2==0){
            cout<<(line[m]+line[m-1])/2<<endl;
        }
        else{
            cout<<line[m]<<endl;
        }

    }
}

```
[source code](./src/s1133343-UVa10107)

## Complexity Analysis
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

## Notes & Reflection
- What challenges did you face?
    - 一開始搞錯「偶數個時要取哪兩個數」
- How would you improve this solution?
    - 使用兩個 heap：
        - max heap 存左半部
        - min heap 存右半部
- What did you learn?
    - 中位數是排序問題的核心應用之一

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials