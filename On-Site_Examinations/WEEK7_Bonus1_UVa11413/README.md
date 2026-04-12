
# UVa 11413 - Fill the Containers
## Problem Description
給定 n 個液體容量（依序不能改變），需要用 m 個容器裝這些液體。

每個容器的容量相同，請找出「最小的容器容量」，使得可以在不改變順序的情況下，把所有液體裝入這 m 個容器中。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2408&mosmsg=Submission+received+with+ID+31075254)

## Learning Objectives
- [ ] 理解二分搜尋在答案空間
## Solution Approach

### Algorithm Logic
1. 讀入 n（液體數）與 m（容器數）
2. 記錄：
    - mx：單一液體最大值（下界）
    - sum：所有液體總和（上界）
3. 在 [mx, sum] 範圍內進行二分搜尋
4. 對每個 mid（容量）：
    - 呼叫 check(mid) 判斷是否可行
5. 若可行 → 嘗試更小容量（往左縮）
6. 若不可行 → 增加容量（往右找）
7. 最終得到最小可行容量

### Key Insights
- 容量越大 → 越容易裝下（單調性）→ 可以二分
- 每次裝不下就開新容器
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
bool check(int cap){
    int used=1,capacity=0;
    for(int i=0;i<n;i++){
        if(capacity+a[i]>cap){
            used++;
            capacity=a[i];
        }
        else{
            capacity+=a[i];
        }
    }
    return m>=used;
}
int main(){
    while(cin>>n>>m){
        int ans=-1;
        int mx=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
            sum+=a[i];
        }
        int low=mx,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        cout<<ans<<endl;
    }
}
```
[source code](./src/s1133343-UVa11413)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - check() 的寫法（何時換容器）容易出錯
- How would you improve this solution?
    - 可以改用 vector 增加彈性
- What did you learn?
    - 二分搜尋不只用在「找元素」，也可以用在「找答案」
    
## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials