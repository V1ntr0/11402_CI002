#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;
int main(){
    int p,c,casenum=1;
    while(cin>>p>>c&&(p!=0&&c!=0)){
        cout<<"Case "<<casenum++<<":"<<endl;
        deque<int>dp;
        int count=min(p,c);
        for(int i=1;i<=count;i++){
            dp.push_back(i);
        }
        while(c--){
            char cmd;
            cin>>cmd;
            if(cmd=='N'){
                int front=dp.front();
                cout<<dp.front()<<endl;
                dp.pop_front();
                dp.push_back(front);
            }
            else if(cmd=='E'){
                int x;
                cin>>x;
                for(auto it=dp.begin();it!=dp.end();++it){
                    if(*it==x){
                        dp.erase(it);
                        break;
                    }
                }
                dp.push_front(x);
            }
        }
    }
}
