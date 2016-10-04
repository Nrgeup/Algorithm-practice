/****************************************************************************\
题意：求最小生成树的最大边。

思路：使用prim算法，注意使用sacnf读入。

\****************************************************************************/
#include<cstdio>
#include<iostream>
#include<cstring>

//#define LOCAL

using namespace std;

const int inf = 65540;
const int Max_size = 502;
int dist[Max_size][Max_size];
int n;

int prim(){
    int ans = 0, s = 0, num = 1, flag[Max_size], Min, Min_i, low_dist[Max_size], i;
    memset(flag,0,sizeof(flag));
    memset(low_dist,inf,sizeof(low_dist));
    flag[s] = 1;
    while(num < n){
        Min = inf;
        for(i = 0; i < n; i++){
            if(!flag[i] && low_dist[i] > dist[s][i]){
                low_dist[i] = dist[s][i];
            }
            if(!flag[i] && Min > low_dist[i]){
                Min_i = i;
                Min = low_dist[i];
            }
        }
        s = Min_i;
        ans = Min < ans ? ans : Min;
        num++;
        flag[Min_i] = 1;
    }
    return ans;
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int T,i,j;
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d",&dist[i][j]);
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
