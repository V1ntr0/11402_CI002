# UVa 11292 - Dragon of Loowater
## Problem Description
給定 n 隻龍，每隻龍有一個頭部直徑；以及 m 位騎士，每位騎士有一個身高。
一位騎士只能砍掉直徑不大於自己身高的龍頭，且每位騎士只能使用一次。

求消滅所有龍所需支付的最小總成本（所有被雇用騎士身高總和）。若無法消滅所有龍，輸出：Loowater is doomed!

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2267)

## Learning Objectives
- [ ] Greedy Algorithm
- [ ] 排序與雙指針
## Solution Approach

### Algorithm Logic
1. 讀入 n, m，且n、m不等於0
2. 讀入 dragon[] 與 knight[]
3. 對兩者排序（小到大）
4. 用雙指針：
    - dragon[i]：目前最小未處理龍
    - knight[j]：目前最小可用騎士
5. 若 knight[j] >= dragon[i] → 配對成功
6. 否則換下一個騎士
7. 若所有龍都被配對 → 輸出 cost
8. 否則輸出 "Loowater is doomed!"

### Key Insights
- 每次都用「能剛好砍掉目前最小龍的最小騎士」
- 排序後，若某位騎士無法砍掉當前最小龍，則他也不可能砍掉任何尚未處理的龍，因此可以直接捨棄。
## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m&&(n!=0||m!=0)){
        if(n>m){
             cout<<"Loowater is doomed!"<<endl;
             continue;
        }
        int dragon[n],knight[m];
        for(int a=0;a<n;a++)
            cin>>dragon[a];
        for(int a=0;a<m;a++)
            cin>>knight[a];
        sort(dragon,dragon+n);
        sort(knight,knight+m);

        int cost=0;
        int i=0,j=0;
        while (i < n && j < m) {
            if (knight[j] >= dragon[i]) {
                cost += knight[j];
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == n)
            cout<<cost<<endl;
        else
            cout<<"Loowater is doomed!"<<endl;
    }
}
```
[source code](./src/s1133343-UVa11292.cpp)

## Complexity Analysis
- **Time Complexity:** O(nlogn+mlogm)
- **Space Complexity:** O(n+m)

## Notes & Reflection
- What challenges did you face?
    - 最後輸出判斷要想一下雙指針位置
- How would you improve this solution?
    - 使用 vector<int> 取代變長陣列（VLA），提高程式可攜性。
- What did you learn?
    - 當目標是「最小成本」時，通常應優先考慮使用剛好足夠的資源完成任務

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials