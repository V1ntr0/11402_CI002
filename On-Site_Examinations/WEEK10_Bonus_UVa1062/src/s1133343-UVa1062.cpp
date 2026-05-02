#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int casenum=1;
     while(cin>>s&&s!="end"){
        vector<char> st;
        for(char c:s){
            int beststack =-1;
            char mintop='{';
            for(int i=0;i<st.size();++i)
                if(st[i]>=c){
                    if(st[i]<mintop){
                        mintop=st[i];
                        beststack=i;
                    }
                }

            if(beststack!=-1){
                st[beststack]=c;
            }
            else{
                st.push_back(c);
            }
        }
        cout<<"Case "<<casenum++<<": "<<st.size()<<endl;
    }



}
