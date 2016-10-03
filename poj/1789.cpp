/****************************************************************************\
题意：用一个7位的string代表一个编号，两个编号之间的distance代表这两个编号之间不同字母的个数。
一个编号只能由另一个编号“衍生”出来，代价是这两个编号之间相应的distance，现在要找出一个“衍生”方案，
使得总代价最小，也就是distance之和最小。

思路：由于是稠密图，使用prim算法

\****************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>

//#define LOCAL

using namespace std;


const int Max_size = 2002;
const int inf = 10;

int N;

char str[Max_size][8];
int dist[Max_size][Max_size];

int calDistance(int i ,int j){
    int ans = 0;
    for( int t = 0; t < 7; t++){
        if(str[i][t] != str[j][t])
            ans++;
    }
    return ans;
}

int prim(){

    int i, ans = 0, Min_i, Min_d, s = 0,n = 1, flag[Max_size], low_dist[Max_size];
    memset(low_dist,inf,sizeof(low_dist));
    memset(flag,0,sizeof(flag));
    flag[s] = 1;

    while(n < N){
        Min_d = inf;
        for(i = 0; i < N; i++){
            if(!flag[i] && dist[s][i] < low_dist[i])
                low_dist[i] = dist[s][i];
            if(!flag[i] && Min_d > low_dist[i]){
                Min_d = low_dist[i];
                Min_i = i;
            }
        }
        flag[Min_i] = 1;
        ans += Min_d;
        n++;
        s = Min_i;
        //cout<<"n = "<<n<<" Min_i = "<<Min_i<<"  Min_d = "<<Min_d<<endl;
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
    while(cin>>N && N){
        for( i = 0; i < N; i++)
            cin>>str[i];

        for(i = 0; i < N; i++)
             for(j=i+1;j < N; j++)
                 dist[i][j] = dist[j][i] = calDistance(i,j);

        cout<<"The highest possible quality is 1/"<<prim()<<'.'<<endl;
    }
    return 0;
}
