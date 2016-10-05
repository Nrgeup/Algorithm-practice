/****************************************************************************\
题意：最小生成树问题

思路：prim   算法

\****************************************************************************/
#include<cstdio>
#include<cstring>

//#define LOCAL

using namespace std;

const int Max = 102;
const int inf = 100002;

int n;
int Map[Max][Max];

int prim(){
    int ans = 0, i, flag[Max], s = 0, num = 1, Min, low_dist[Max], Min_i;
    memset(flag, 0, sizeof(flag));
    for(int i = 0; i < n; i++)
        low_dist[i] = inf;
    while(num < n){
        flag[s] = 1;
        Min = inf;
        for(i = 0; i < n; i++){
            if(!flag[i] && low_dist[i] > Map[s][i])
                low_dist[i] = Map[s][i];
            if(!flag[i] && Min > low_dist[i]){
                Min = low_dist[i];
                Min_i = i;
            }
        }
        num++;
        ans += Min;
        s = Min_i;
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
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d",&Map[i][j]);
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
