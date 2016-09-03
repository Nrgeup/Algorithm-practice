/*
思路：dp方法
注意记忆搜索，已经判断过的就不要重复判断了

*/


#include<iostream>
#include<cstring>
#include <fstream>


using namespace std;


 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");


int R,C;
int region[102][102];
int des[102][102];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};


int dp(int i, int j){
    if(des[i][j]!= 0)
        return des[i][j];
    int maxx=0,s,temx,temy;
    for(int t=0;t<4;t++)
    {
        temx=i+dir[t][0];
        temy=j+dir[t][1];
        if(temx>=0&&temx<R&&temy>=0&&temy<C&&region[temx][temy]<region[i][j]){
            s=dp(temx,temy);
            if(s>maxx)maxx=s;
        }
    }
    des[i][j]=maxx+1;
    return  des[i][j];
}


int main(){
    int i,j,Max;
    while(cin>>R>>C){
        memset(region,0,sizeof(region));
        memset(des,0,sizeof(des));
        for(i = 0; i < R ; i++){
            for(j=0; j< C ; j++){
                cin>>region[i][j];
            }
        }
        Max = 0;
         for(i = 0; i < R ; i++){
            for(j=0; j< C ; j++){
                dp(i, j);
                Max = Max >= des[i][j] ? Max : des[i][j];
            }
        }
        cout<<Max<<endl;


    }
    return 0;
}
