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
