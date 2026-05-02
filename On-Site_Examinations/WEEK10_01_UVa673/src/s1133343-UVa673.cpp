#include<bits/stdc++.h>
using namespace std;
bool isv(string s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['){
            st.push(c);
        }
        else if(c==')'||c==']'){
            if(st.empty())
                return false;
            if(c==')'&&st.top()!='(')
                return false;
            if(c==']'&&st.top()!='[')
                return false;
            st.pop();
        }
    }
    return st.empty();
}
int main(){
    int n;
    string s;
    cin>>n;
    cin.ignore();
    while(n--){
        getline(cin,s);
        if(isv(s))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

}
