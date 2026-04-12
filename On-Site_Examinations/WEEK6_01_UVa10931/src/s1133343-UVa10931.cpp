#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    while(cin>>i&&i!=0){
        string s;
        int count=0;
        while(i>0){

            if(i%2==1){
                s+='1';
                count++;

            }
            else{
                s+='0';
            }

            i/=2;
        }
        reverse(s.begin(),s.end());
        cout<<"The parity of "<<s<<" is "<<count<<" (mod 2)."<<endl;
  }



}
