#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        queue<int> cards;
        for(int i=1;i<=n;i++)
            cards.push(i);
        vector<int> discarded;
        while(cards.size()>1){
            discarded.push_back(cards.front());
            cards.pop();

            int top=cards.front();
            cards.pop();
            cards.push(top);
        }
        cout<<"Discarded cards:";
        for(int i=0;i<discarded.size();i++){
            cout<<" "<<discarded[i];
            if(i!=discarded.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
        cout<<"Remaining card: "<<cards.front()<<endl;


    }





}
