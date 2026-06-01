# UVa 10954 - Add All
## Problem Description
給定 N 個整數，每次將兩個數相加的「成本」就是它們的和。將所有數字合併成一個數字的過程中有不同的合併順序，請找出合併所有數字的最小總成本。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895)

## Learning Objectives
- [ ] 掌握 C++ STL 中 priority_queue 的用法
- [ ] 觀察合併過程對後續成本的連鎖影響
## Solution Approach

### Algorithm Logic
1. 讀入測資數量n 與建立最小堆積pq
2. 在pq放入所有初始數字
3. 取出最小的兩數累加成本並放回結果，做到pq size小於等於1停止
4. 輸出結果

### Key Insights
- 較早合併的數字會被重複加到之後的合併成本中。因此，越大的數字越晚被合併，越小的數字則可以先合併
- 每合併一次，新產生的 sum 可能會比剩下的數字大。使用 priority_queue 可以在 O(log N) 的時間內重新調整位置，這比每次都重新 sort() 的 O(N log N) 快得多
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        priority_queue <int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            pq.push(num);
        }
        int totalcost=0;

        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int sum=first+second;
            totalcost+=sum;
            pq.push(sum);
        }
        cout<<totalcost<<endl;

    }


}

```
[source code](./src/s1133343-UVa10952.cpp)

## Complexity Analysis
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

## Notes & Reflection
- What challenges did you face?
    - 如果誤用了一般的 priority_queue<int>（最大堆積），算出來的會是最大成本而非最小。
    - 不確定怎麼加會最好
- How would you improve this solution?
    - 在處理大數據量時，使用 scanf/printf 或 cin.tie(0) 加速輸入輸出。
- What did you learn?
    - 學習到如何利用資料結構（堆積）來優化需要不斷選取極值的演算法。

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials