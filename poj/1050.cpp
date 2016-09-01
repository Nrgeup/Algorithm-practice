/*
思路： 最小子段和问题的二维形式
*/

#include<iostream>
#include<cstring>

using namespace std;

int Rect[101][101];
int col[101];

/* dp 方法 求一维 数组求最大子段和 */
int find_max_sub_value(int* S , int  n){
    int i,max_v =S[0],temp=S[0];
    for(i = 1 ; i < n ; i++){
        if(temp > 0)
            temp = temp + S[i];
        else
            temp = S[i];
        if(temp > max_v)
            max_v = temp;
    }
    return max_v;
}


int main(){
    int N,i,j,k,temp,ans ;
   while( cin>>N){
        memset(Rect,0,sizeof(Rect));
        for(i = 0; i< N ; i++){
            for(j = 0;j < N; j++ ){
                cin>>Rect[i][j];
            }
        }
        ans = Rect[0][0];
        for(i =0 ;i < N ; i++){
            memset(col, 0 ,sizeof(col));
            for( j = i ; j < N ;j++){
                for(k =0 ;k < N ;k++){
                    col[k] += Rect[j][k];
                }
                temp = find_max_sub_value( col , N );
                if(temp > ans){
                    ans = temp;
                }
            }
        }
        cout<<ans<<endl;
   }
    return 0;
}
