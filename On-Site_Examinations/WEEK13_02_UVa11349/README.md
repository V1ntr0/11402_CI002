# UVa 11349 - Symmetric Matrix
## Problem Description
給定一個 N x N 的方陣，判斷它是否為「對稱矩陣」。
定義的對稱是指：以方陣的中心點為基準，所有相對應位置的元素都必須相等（即 M<sub>i, j</sub> = M<sub>N-1-i, N-1-j</sub>）。此外，若矩陣中包含任何負數，則直接視為不對稱。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2324)

## Learning Objectives
- [ ] 了解二維陣列的中心對稱索引映射關係
- [ ] 留意資料型態範圍，防止數值過大導致溢位
## Solution Approach

### Algorithm Logic
1. 讀入測試資料組數 t。
2. 每組測試資料開始時，讀入字元拋棄掉不需要的 N 與 =，接著讀入矩陣大小 n。
3. 使用二維陣列讀入整個矩陣。在讀入的同時，檢查是否有任何元素小於 0。若有負數，直接標記為不對稱（is_s = false）。
4. 遍歷矩陣，比較 matrix[i][j] 是否等於其中心對稱點 matrix[n-1-i][n-1-j]。若不相等，標記為不對稱並及早結束檢查。
5. 輸出 Test #X: Symmetric. 或 Test #X: Non-symmetric.。

### Key Insights
- 不能直接 cin >> n
-  矩陣大小為 N 時，點 (i, j) 中心的對稱點座標為 (N-1-i, N-1-j)。
## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int casenum=1;
    while(cin>>t){
        while(t--){
            char word;
            int n;
            cin>>word>>word>>n;
            vector<vector<long long>> matrix(n,vector<long long>(n));
            bool is_s=true;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                    cin>>matrix[i][j];
                    if(matrix[i][j]<0){
                        is_s=false;
                    }
                }

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]!=matrix[n-1-i][n-1-j]){
                        is_s=false;
                        break;
                    }


                }


            }
        cout<<"Test #"<<casenum++<<": ";
        if(is_s)
            cout<<"Symmetric."<<endl;
        else
            cout<<"Non-symmetric."<<endl;

        }

    }

}

```
[source code](./src/s1133343-UVa11349.cpp)

## Complexity Analysis
- **Time Complexity:** O(N<sup>2</sup>)
- **Space Complexity:** O(N<sup>2</sup>)

## Notes & Reflection
- What challenges did you face?
    - 一開始陣列設int，結果爆了。 
- How would you improve this solution?
    - 檢查對稱時，我們其實只要檢查到矩陣的一半即可。
- What did you learn?
    - 學到了如何計算二維陣列中點對稱的索引映射公式

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials