#include<bits/stdc++.h>
using namespace std;
long long cnt;
int main(){
    int l;
    while(cin>>l&&l!=-1){
        while(l--){
            int D,I;
            cin>>D>>I;
            int pos=1;
            for(int i=0;i<D-1;i++){
                if(I%2==1){
                    I=(I+1)/2;
                    pos=pos*2;
                }
                else{
                    pos=pos*2+1;
                    I=I/2;
                }
            }
            cout<<pos<<endl;;
        }

    }




}
