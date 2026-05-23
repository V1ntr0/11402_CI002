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
