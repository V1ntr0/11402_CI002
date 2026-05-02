# UVa 11559 - Event Planning
## Problem Description
有 N 個人要參加活動，總預算為 B。有 H 間飯店，每間飯店提供：
- 每人住宿價格 price
- 接下來 W 週的床位數量
條件：
1. 必須選擇某一間飯店的某一週
2. 該週床位數 ≥ N（所有人都有床）
3. 總花費 N × price 不得超過預算 B
目標：
- 找出 最便宜的可行方案
- 若沒有符合條件的 → 輸出 "stay home"

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2595)

## Learning Objectives
- [ ] 模擬問題
- [ ] 條件篩選 + 最小值
## Solution Approach

### Algorithm Logic
1. 讀入 N（人數）、B（預算）、H（飯店數）、W（週數）
2. 設 min_cost = B + 1（代表尚未找到可行解）
3. 對每間飯店：
    - 讀入 price
    - 檢查接下來 W 週：
    - 若某一週 beds >= N → 表示可住
4. 如果該飯店存在可住週：
    - 計算總費用 N * price
    - 更新 min_cost
5. 輸出:
    - 若 min_cost <= B → 輸出費用
    - 否則 → "stay home"

### Key Insights
- 要找的是有沒有任何一週能住下全部人，不是找最多床
- 一間飯店只要有「一週符合」就可以考慮
## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,B,H,W;
    while(cin>>N>>B>>H>>W){
        int min_cost=B+1;
        for(int i=0;i<H;i++){
            int price;
            cin>>price;

            bool canstay=false;
            for(int j=0;j<W;j++){
                int beds;
                cin>>beds;
                if(beds>=N){
                    canstay=true;
                }
            }
            if(canstay)
                min_cost=min(min_cost,N*price);
        }
        if(min_cost<B+1)
            cout<<min_cost<<endl;
        else
            cout<<"stay home"<<endl;
    }
}
```
[source code](./src/s1133343-UVa)

## Complexity Analysis
- **Time Complexity:** O(H × W)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 忘記要同時滿足：床位、預算
    - 
- How would you improve this solution?
    - 進一步優化：一旦 N * price > B，其實可以直接略過
- What did you learn?
    - 篩選 + 找最小值

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials