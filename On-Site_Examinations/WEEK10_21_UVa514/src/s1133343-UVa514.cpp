#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        while(true){
            vector<int> target(n);
            cin>>target[0];
            if(target[0]==0)
                break;
            for(int i=1;i<n;i++){
                cin>>target[i];
            }

            stack<int> station;
            int curr_train=1;
            bool poss=true;
            for(int i=0;i<n;i++){
                while(curr_train<=n&&(station.empty()||station.top()!=target[i])){
                    station.push(curr_train++);
                }
                if(!station.empty()&&station.top()==target[i]){
                    station.pop();
                }
                else{
                    poss=false;
                    break;
                }
            }
            if(poss)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }


}
