#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
    string s;
    while(cin>>s){
    list <char>text;
    auto it =text.begin();
        for(char c:s){
            if(c=='[')
                it=text.begin();
            else if(c==']')
                it=text.end();
            else
                text.insert(it,c);
        }
        for(char c:text){
            cout<<c;
        }
        cout<<endl;
    }



}
