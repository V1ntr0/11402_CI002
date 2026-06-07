#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,b;
    while(cin>>s>>b&&(s!=0||b!=0)){
        //vector<bool> soldier(s+1,true);
         for (int i = 1; i <= s; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[s] = 0;
        int L[100005], R[100005];
        for (int i = 0; i < b; i++) {
            int l, r;
            cin >> l >> r;
            R[L[l]] = R[r];
            L[R[r]] = L[l];
            cout << (L[l] == 0 ? "*" : to_string(L[l])) << " " << (R[r] == 0 ? "*" : to_string(R[r])) << endl;
        }
        // int r,l;
        // for(int i=0;i<b;i++){
        //     cin>>l>>r;
        //     for(int a=l;a<=r;a++){
        //         soldier[a]=false;
        //     }
        //     int sur_l=-1,sur_r=-1;
        //     for(int j=1;j<l;j++){
        //         if(soldier[j])
        //             sur_l=j;
        //     }
        //     for(int j=s;j>r;j--){
        //         if(soldier[j])
        //             sur_r=j;
        //     }
        //     if(sur_l==-1)
        //         cout<<'*'<<" ";
        //     else
        //         cout<<sur_l<<" ";
        //     if(sur_r==-1)
        //          cout<<'*'<<endl;
        //     else
        //         cout<<sur_r<<endl;
        // }
        cout<<"-"<<endl;
    }

}
