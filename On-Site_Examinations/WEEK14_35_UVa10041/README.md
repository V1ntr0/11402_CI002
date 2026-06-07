# UVa 10041 - Vito's Family
## Problem Description
Vito搬到了紐約，他有很多親戚住在同一條街（一維座標）。他想找一間房子住，使得他家到所有親戚家的距離總和最小。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=982)

## Learning Objectives
- [ ] 理解中位數在距離優化問題中的特性
- [ ] 學習如何計算絕對值距離之和
## Solution Approach

### Algorithm Logic
1. 讀入整數 n
2. 讀入親戚數 r
3. 讀入每位親戚家裡座標
4. 將座標從小到大排列
5. 找出中位數
6. 計算 Vito 家到每個親戚家的絕對距離
7. 輸出最小距離總和

### Key Insights
- 如果選取的點不在中位數上（例如偏左），當你向右移動一點點，所有在你右邊的點（較多數）距離都會減少，而左邊的點（較少數）距離增加。因此，移動到左右兩邊點數相等的位置（即中位數）時，距離總和會達到最小。
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int r;
        cin>>r;
        vector<int> s(r);
        for(int i=0;i<r;i++){
            cin>>s[i];
        }
        sort(s.begin(),s.end());
        int d=0;
        int mid=s[r/2];

        for(int i=0;i<r;i++){
            d+=abs(mid-s[i]);
        }
        cout<<d<<endl;
    }
}

```
[source code](./src/s1133343-UVa10041.cpp)

## Complexity Analysis
- **Time Complexity:** O(rlogr)
- **Space Complexity:** O(r)

## Notes & Reflection
- What challenges did you face?
    - 一開始可能會想用「平均值」，但平均值最小化的是「距離平方和」（最小平方法），而非「絕對距離和」。
- How would you improve this solution?
    - 如果 R 很大，可以使用 nth_element 來尋找中位數，將時間複雜度降至平均 O(R)
- What did you learn?
    - 理解了中位數在特性

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials