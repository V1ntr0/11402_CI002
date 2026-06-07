# UVa 10189 - Minesweeper
## Problem Description
輸入一個 n x m 的踩地雷地圖，其中 * 代表地雷，. 代表安全格子。
請將每個 . 取代為其周圍 8 個格子中包含的地雷總數，並依格式輸出。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1130)

## Learning Objectives
- [ ] 熟練二維陣列的邊界檢查與遍歷
## Solution Approach

### Algorithm Logic
1. 讀入整數 row 與 col ，若兩者皆為 0 則結束程式。
2. 建立二維陣列讀入地圖，並初始化一個相同大小的計數陣列 field。
3. 遍歷地圖上的每一個格子：如果是安全格子就去檢查周圍 8 格有沒有地雷。
4. 輸出 Field #X:。
5. 輸出更新後的地圖，每筆測資之間的空行處理。

### Key Insights
- 可以用把地雷周遭加1，這樣只要地雷少，計算量就會變小。
- 可以使用方向陣列優化
## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int row,col;
    int casenum=1;
    while(cin>>row>>col&&(row!=0&&col!=0)){
        char matrix[row][col]{};
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cin>>matrix[i][j];
                }
            }
        vector<vector<int>> field(row,vector<int>(col,0));
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(matrix[i][j]!='*'){
                        if( (i-1>=0&&j-1>=0) && matrix[i-1][j-1]=='*')
                            field[i][j]+=1;
                        if( i-1>=0 && matrix[i-1][j]=='*')
                            field[i][j]+=1;
                        if( (i-1>=0&&j+1<col) && matrix[i-1][j+1]=='*')
                            field[i][j]+=1;
                        if( (j-1>=0) && matrix[i][j-1]=='*')
                            field[i][j]+=1;
                        if( (j+1<col) && matrix[i][j+1]=='*')
                            field[i][j]+=1;
                        if( (i+1<row&&j-1>=0) && matrix[i+1][j-1]=='*')
                            field[i][j]+=1;
                        if( (i+1<row) && matrix[i+1][j]=='*')
                            field[i][j]+=1;
                        if( (i+1<row&&j+1<col) && matrix[i+1][j+1]=='*')
                            field[i][j]+=1;
                }
            }
        }
        cout<<"Field #"<<casenum++<<":"<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='*')
                    cout<<matrix[i][j];
                else
                    cout<<field[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }

}


```
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    int casenum = 1;

    bool first = true;

    while (cin >> row >> col && (row != 0 && col != 0)) {
        if (!first) {
            cout << endl;
        }
        first = false;

        vector<string> matrix(row);
        for (int i = 0; i < row; i++) {
            cin >> matrix[i];
        }

        vector<vector<int>> field(row, vector<int>(col, 0));

        // 8 方向的相對座標位移
        int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '*') {
                    // 往 8 個方向擴散
                    for (int d = 0; d < 8; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni >= 0 && ni < row && nj >= 0 && nj < col) {
                            field[ni][nj]++;
                        }
                    }
                }
            }
        }

        cout << "Field #" << casenum++ << ":" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '*') {
                    cout << '*';
                } else {
                    cout << field[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
```
[source code](./src/s1133343-UVa10189.cpp)

## Complexity Analysis
- **Time Complexity:** O(NxM)
- **Space Complexity:** O(NxM)

## Notes & Reflection
- What challenges did you face?
    - 不太熟悉座標位移，所以用if寫
- How would you improve this solution?
    - 使用 dx[] 和 dy[] 方向陣列。
- What did you learn?
    - 學習到座標位移用法。

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials