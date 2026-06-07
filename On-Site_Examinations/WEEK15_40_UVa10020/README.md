# UVa 10020 - Minimal coverage
## Problem Description
給定一個目標區間 [0, M]，以及許多線段 (l, r)。
請從這些線段中選出最少數量的線段，使它們的聯集能夠完整覆蓋區間 [0, M]。
若無法覆蓋整個區間，輸出 0。

題目要求輸出所選的線段數量以及實際選到的線段。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=961)

## Learning Objectives
- [ ] Greedy Algorithm
- [ ] Sorting + Interval Processing
## Solution Approach

### Algorithm Logic
1. 讀入測試資料數量 T
2. 讀入目標區間右端點 M
3. 持續讀入線段 (l, r)，直到讀到 (0, 0)
4. 將所有線段依照左端點 l 由小到大排序
5. 在所有滿足 l <= current_r 的線段中：
    - 找出右端點最遠的線段
    - 將其加入答案
6. 更新覆蓋範圍為該線段的右端點
7. 重複直到：
    - 已覆蓋到 M
    - 或找不到可延伸覆蓋範圍的線段
8. 若成功覆蓋 [0, M]，輸出答案；否則輸出 0

### Key Insights
- 若目前已覆蓋到 current_r，下一條線段必須滿足 l≤current_r​
- 在所有可選線段中，選擇右端點最大的線段最划算，因為能一次延伸最遠距離。
- 若某一步找不到符合條件的線段，表示覆蓋出現空缺，不可能完成任務。
## Code Structure
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct seg{
    int l,r;
};
bool compare(seg a, seg b) {
    return a.l < b.l;
}
int main(){
    int casenum;
    cin>>casenum;
    while(casenum--){
        int m;
        cin>>m;
        int l,r;
        vector<seg> segment;
        while(cin>>l>>r&&(l!=0||r!=0))
            segment.push_back({l,r});
        sort(segment.begin(),segment.end(),compare);

        vector<seg>ans;

        int current_r=0;
        int i=0;
        bool possible=false;
        while(current_r<m){
            int best_i=-1;
            int best_r=current_r;

            while(i<segment.size()&& segment[i].l <= current_r){
                if (segment[i].r > best_r) {
                    best_r = segment[i].r;
                    best_i = i;
                }
                i++;
            }

            if (best_i == -1) break;

            ans.push_back(segment[best_i]);
            current_r = best_r;

            if (current_r >= m) {
                possible = true;
                break;
            }
        }
        if (possible) {
            cout << ans.size() <<endl;
            for (int k = 0; k < ans.size(); k++) {
                cout << ans[k].l << " " << ans[k].r << endl;
            }
        } else {
            cout << 0<<endl;
        }

        if (casenum > 0)
            cout << endl;

    }
    return 0;
}

```
[source code](./src/s1133343-UVa10020.cpp)

## Complexity Analysis
- **Time Complexity:** O(nlogn)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 在所有可行的線段中選最佳的那一條要思考一陣子
- How would you improve this solution?
    - 將貪心流程封裝成函式。
- What did you learn?
    - 區間覆蓋問題通常可以透過排序加貪心解決

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials