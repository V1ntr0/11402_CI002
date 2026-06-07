#include <iostream>
using namespace std;
int main(){
    string line{};
    bool first=true;
    while(getline(cin,line)){
            if(!first)
                cout<<endl;
            first=false;
        int count[129]{};
        for(char c:line){
            count[c]++;
        }
        for(int i=1;i<1000;i++){
            for(int j=128;j>=32;j--){
                if(i==count[j])
                    cout<<j<<" "<<count[j]<<endl;
            }
        }

    }


}
