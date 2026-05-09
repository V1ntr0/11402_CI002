# UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)
## Problem Description
你在輸入一段文字時，鍵盤壞掉了。其中 [ 鍵代表 Home（游標跳到最前面），] 鍵代表 End（游標跳到最後面）。
給你一段包含文字與這兩種特殊符號的字串，請輸出最終螢幕上顯示的文字順序。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139)

## Learning Objectives
- [ ] 學習如何處理需要頻繁改變插入位置的模擬問題。
## Solution Approach

### Algorithm Logic
1. 不斷讀入整行字串 s 直到結束
2. 建立一個 list<char> 用來存儲結果，並宣告一個 it 迭代器初始指向串列的開頭
3. 遍歷字串：
    - 遇到 [：將 it 重新指向串列的最前端 text.begin()
    - 遇到 ]：將 it 重新指向串列的最末端 text.end()
    - 遇到一般字元：使用 text.insert(it, c) 在目前 it 的位置插入字元
    注意： list::insert 插入後，迭代器依然指向原本的位置，因此連續輸入文字會維持正確順序
4. 輸出整個 list

### Key Insights
- 將迭代器視為「螢幕上的游標」，[ 和 ] 只是在移動游標，而打字是在游標處塞入東西。
- 
## Code Structure
```cpp
#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
    string s;
    while(cin>>s){
    list <char>text;
    auto it =text.begin();
        for(char c:s){
            if(c=='[')
                it=text.begin();
            else if(c==']')
                it=text.end();
            else
                text.insert(it,c);
        }
        for(char c:text){
            cout<<c;
        }
        cout<<endl;
    }
}
/*
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        deque<string> dq;
        string temp = "";
        bool toFront = false; 

        for (char c : s) {
            if (c == '[' || c == ']') {
                if (!temp.empty()) {
                    if (toFront) dq.push_front(temp);
                    else dq.push_back(temp);
                    temp = "";
                }
                toFront = (c == '[');
            } else {
                temp += c;
            }
        }

        if (!temp.empty()) {
            if (toFront) dq.push_front(temp);
            else dq.push_back(temp);
        }

        for (const string& part : dq) {
            cout << part;
        }
        cout << endl;
    }
    return 0;
}
*/

```
[source code](./src/s1133343-UVa11988.cpp)

## Complexity Analysis
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

## Notes & Reflection
- What challenges did you face?
    - 一開始本來想用vector 實作，後來發現太複雜
- How would you improve this solution?
    - 可以使用deque寫看看
- What did you learn?
    - 深刻理解了 list 的特性

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials