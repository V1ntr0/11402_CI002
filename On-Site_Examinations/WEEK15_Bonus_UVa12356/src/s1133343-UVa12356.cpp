#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,b;
    while(cin>>s>>b&&(s!=0||b!=0)){
        vector<bool> soldier(s,true);
        int r,l;
        for(int i=0;i<b;i++){
            cin>>l>>r;
            for(int a=l-1;a<r;a++){
                soldier[a]=false;
            }
            int sur_l='*',sur_r='*';
            for(int j=0;j<l;j++){
                if(soldier[j])
                    sur_l=j;
            }
            for(int j=r;j<s;j++){
                if(soldier[j])
                    sur_r=j;
            }

            cout<<sur_l<<" "<<sur_r<<endl;
        }


        cout<<"-"<<endl;
    }



}
