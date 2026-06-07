# UVa 12356 - Army Buddies
## Problem Description
在一支軍隊中，士兵編號為 1 ~ S，並依照編號順序站成一直線。
接下來會發生 B 次戰鬥，每次給定區間 [L, R]，表示這段區間內的士兵全部陣亡。
對於每次戰鬥，需要輸出：

陣亡區間左邊最近仍存活的士兵編號
陣亡區間右邊最近仍存活的士兵編號

若某一側已經沒有存活士兵，輸出 *。
每組測試資料結束後輸出：
-

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3778&mosmsg=Submission+received+with+ID+31169180)

## Learning Objectives
- [ ] Doubly Linked List
- [ ] Array Simulation
## Solution Approach

### Algorithm Logic
1. 讀入士兵數量 S 與戰鬥次數 B
2. 建立兩個陣列：
    - L[i]：士兵 i 左邊最近存活的士兵
    - R[i]：士兵 i 右邊最近存活的士兵
3. 初始化雙向鏈結串列
4. 對每次戰鬥：
    - 讀入陣亡區間 [l, r]
    - 輸出區間外側仍存活的左右鄰居
    - 將區間左右兩側直接連接
5. 每組資料結束輸出 -

### Key Insights
- 只需要知道每位士兵目前的左右鄰居即可
- 
## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,b;
    while(cin>>s>>b&&(s!=0||b!=0)){
         int L[100005], R[100005];
         for (int i = 1; i <= s; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[s] = 0;
        for (int i = 0; i < b; i++) {
            int l, r;
            cin >> l >> r;
            R[L[l]] = R[r];
            L[R[r]] = L[l];
            cout << (L[l] == 0 ? "*" : to_string(L[l])) << " " << (R[r] == 0 ? "*" : to_string(R[r])) << endl;
        }
        cout<<"-"<<endl;
    }

}

```
[source code](./src/s1133343-UVa12356.cpp)

## Complexity Analysis
- **Time Complexity:** O(S+B)
- **Space Complexity:** O(S)

## Notes & Reflection
- What challenges did you face?
    - 原本想用bool標記，會超時，沒考慮到大測資問題
    - 理解如何利用陣列模擬雙向鏈結串列需要一些觀察
- How would you improve this solution?
    - 將陣列大小改為依輸入動態配置
- What did you learn?
    - 雙向鏈結串列非常適合處理大量區間刪除問題

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials