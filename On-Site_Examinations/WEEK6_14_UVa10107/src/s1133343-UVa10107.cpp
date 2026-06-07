#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int n;
    vector <int> line;
    while(cin>>n){
        line.push_back(n);
        if(line.size()==1){
            cout<<n<<endl;
            continue;
        }
        sort(line.begin(),line.end());
        int m=line.size()/2;
        if(line.size()%2==0){
            cout<<(line[m]+line[m-1])/2<<endl;
        }
        else{
            cout<<line[m]<<endl;
        }

    }
}
