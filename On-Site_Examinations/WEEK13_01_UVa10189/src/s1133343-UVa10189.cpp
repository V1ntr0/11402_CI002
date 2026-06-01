#include <bits/stdc++.h>
using namespace std;
int main(){
    int row,col;
    int casenum=1;
    while(cin>>row>>col&&(row!=0&&col!=0)){
        char matrix[row][col]{};
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cin>>matrix[i][j];
                }
            }
        vector<vector<int>> field(row,vector<int>(col,0));
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(matrix[i][j]!='*'){
                        if( (i-1>=0&&j-1>=0) && matrix[i-1][j-1]=='*')
                            field[i][j]+=1;
                        if( i-1>=0 && matrix[i-1][j]=='*')
                            field[i][j]+=1;
                        if( (i-1>=0&&j+1<col) && matrix[i-1][j+1]=='*')
                            field[i][j]+=1;
                        if( (j-1>=0) && matrix[i][j-1]=='*')
                            field[i][j]+=1;
                        if( (j+1<col) && matrix[i][j+1]=='*')
                            field[i][j]+=1;
                        if( (i+1<row&&j-1>=0) && matrix[i+1][j-1]=='*')
                            field[i][j]+=1;
                        if( (i+1<row) && matrix[i+1][j]=='*')
                            field[i][j]+=1;
                        if( (i+1<row&&j+1<col) && matrix[i+1][j+1]=='*')
                            field[i][j]+=1;
                }
            }
        }
        cout<<"Field #"<<casenum++<<":"<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='*')
                    cout<<matrix[i][j];
                else
                    cout<<field[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }

}
