
# UVa 10474 - Where is the Marble?
## Problem Description
給定一組Marble（整數），以及多個查詢值。對每個查詢值，請找出它在排序後序列中的第一個出現位置（1-based index）。
- 若存在 → 輸出位置
- 若不存在 → 輸出 not found

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1415&mosmsg=Submission+received+with+ID+31075235)

## Learning Objectives
- [ ] 熟悉排序（Sorting）
- [ ]  理解二分搜尋（Binary Search）與「找第一個出現位置」
## Solution Approach

### Algorithm Logic
1. 讀入整數 n 與 q（查詢數）
2. 若 n == 0 && q == 0，結束
3. 讀入 n 個彈珠並排序
4. 對每個查詢值 target：
    - 使用二分搜尋
    - 找到「最左邊（第一個）」等於 target 的位置
5. 若找到 → 輸出位置（index + 1）
6. 否則 → 輸出 not found

### Key Insights
- 關鍵不是「找到」，而是「找到第一個」
- 當 marble[mid] == target 時：
    - 不能直接 break
    - 要繼續往左找
## Code Structure
```cpp
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int n,q,target;
    int casenum=1;
    while(cin>>n>>q&&(n!=0||q!=0)){
        int marble[n]{};
        for(int i=0;i<n;i++)
            cin>>marble[i];
        sort(marble,marble+n);
        cout<<"CASE# "<<casenum++<<":"<<endl;

        while(q--){
            cin>>target;
            int ans=-1;
            int left=0,right=n-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(marble[mid]==target){
                    ans=mid;
                    //break;
                }
                if(marble[mid]<target){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            if(ans>=0){
                cout<<target<<" found at "<<ans+1<<endl;
            }
            else{
                cout<<target<<" not found"<<endl;
            }
        }
    }
}

```
[source code](./src/s1133343-UVa10474)

## Complexity Analysis
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 寫成「找到就 break」，但這樣會錯（不是第一個）
- How would you improve this solution?
    - 可以使用lower_bound 寫
- What did you learn?
    - 排序 + 搜尋

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials