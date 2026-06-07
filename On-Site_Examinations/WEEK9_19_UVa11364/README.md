# UVa 11364 - Parking
## Problem Description
有一條直線街道，上面有多家商店（位置為整數）。你需要選一個停車位置，使得：
- 所有人從停車點走到各商店的「總距離最小」

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2349)

## Learning Objectives
- [ ] 
- [ ] 
## Solution Approach

### Algorithm Logic
1. 讀入測資數量 t
2. 對每筆測資：
    - 讀入商店數量 n
3. 記錄：
    - 最小位置 min_pos
    - 最大位置 max_pos
4. 計算距離：
    - distance = (max_pos - min_pos) * 2
5. 輸出結果

### Key Insights
- 最佳停車位置其實在中間某處，但不用真的找
- 
## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int max_pos=-1;
        int min_pos=100;
        for(int i=0;i<n;i++){
            int pos;
            cin>>pos;
            if(pos<min_pos)
                min_pos=pos;
            if(pos>max_pos)
                max_pos=pos;
        }
        cout<<( max_pos - min_pos) *2<<endl;
    }
}
```
[source code](./src/s1133343-UVa11364.cpp)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 不知道怎麼算
- How would you improve this solution?
    - 
- What did you learn?
    - 數學化簡

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials