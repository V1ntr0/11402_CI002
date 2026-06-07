# UVa 11615 - Family Tree

## Problem Description
在常規的N代完美二元樹中，家族成員總人數為2^N-1。
然而，若家族中有兩個人A與B為同父母的親兄弟，則代表他們「往上追溯的所有祖先」都是完全重合的。在不重複計算相同祖先的前提下，求此家族樹中實際「不同（Unique）」的總人數。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=390&page=show_problem&problem=2662)

## Learning Objectives
- [ ] 了解完美二元樹的編號與世代層級關係
- [ ] 學習使用位元運算（如 1 << n）高效計算 2 的次方
## Solution Approach

### Algorithm Logic
1. 讀入測試筆數 t，並使用 while(t--) 依序處理每組測資。
2. 讀入n(世代)、a b(同父母的親兄弟)
3. 計算總人數total
4. 推算a b分別是第幾代，並計算最多幾代(max_d)
5. 計算重疊子樹的高度(sub_h)，並計算重複節點(sub_nodes)
6. 扣除重複節點，並輸出

### Key Insights
- 利用log2(a) + 1計算第幾代
- 寫 2^n 的位元代換時，是 1 << n
## Code Structure
```cpp
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int t;
    int n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        int total=(1<<n)-1;//(1<<n)-1原本是(2^n)-1
        int da=log2(a)+1;
        int db=log2(b)+1;
        int max_d=max(da,db);
        int sub_h=n-max_d+1;
        int sub_nodes=(1<<sub_h)-1;//1<<sub_h原本是2 ^sub_h
        cout<<total-(sub_nodes - 1)<<endl;
    }
}
```
[source code](./src/s1133343-UVa11615.cpp)

## Complexity Analysis
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    -  誤用^導致錯誤
- How would you improve this solution?
    - 引入了 __builtin_clz（Count Leading Zeros）來取代帶有浮點數風險的 log2()，從根本上杜絕精度造成的 Bug
- What did you learn?
    - 學會了 2^n 的位元代換時，是 1 << n

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials