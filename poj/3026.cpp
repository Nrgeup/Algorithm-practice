/****************************************************************************\
题意：对每个"A"或”S“, 计算使其全部连接起来的最短路径和

思路：对每一个人'用一次BFS，记录其他人与他的距离，并建图。图建好后，用Prim求最小生成树即为答案

\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<cstring>
#include<iostream>


//#define LOCAL

using namespace std;

const int maxn = 52;
const int inf = 100000;

int MAP[maxn][maxn];
int dist[maxn*2][maxn*2];
int node[maxn*2][2];
int visit[maxn][maxn];
int T,num,x,y;

int que[maxn*maxn][3];

int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void bfs(int node_index){
    int t,head,tail,nx,ny,xx,yy;
    memset(visit,0,sizeof(visit));
    tail = head = 0;
    que[tail][0] = 0;
    que[tail][1] = node[node_index][0];
    que[tail][2] = node[node_index][1];
    visit[que[tail][1]][que[tail][2]] = 1;
    tail++;

    while(head <= tail){
        xx = que[head][1];
        yy = que[head][2];
        for(t = 0; t < 4; t++){
            nx = xx + dir[t][0];
            ny = yy + dir[t][1];
            if((nx >= 0 && nx < y) && (ny >= 0 && ny < x) && !visit[nx][ny] && MAP[nx][ny] >= 0){
                que[tail][0] = que[head][0] + 1;
                que[tail][1] = nx;
                que[tail][2] = ny;
                if(MAP[nx][ny] > 0){
                    dist[node_index][MAP[nx][ny]] = dist[MAP[nx][ny]][node_index] = que[tail][0];
                }
                visit[que[tail][1]][que[tail][2]] = 1;
                tail++;
            }
        }
        head++;
    }
    return;
}

int prim(){
    int ans = 0,flag[maxn*2], i, low_dist[maxn*2], nn = 1, low_i, s, low_min;
    memset(flag, 0, sizeof(flag));
    for(i = 1; i <= num; i++)
        low_dist[i] = inf;
    s = 1;
    while(nn < num){
        flag[s] = 1;
        low_min = inf;
        for(i = 1; i <= num; i++){
            if(!flag[i] && low_dist[i] > dist[s][i])
                low_dist[i] = dist[s][i];
            if(!flag[i] && low_min > low_dist[i]){
                low_min = low_dist[i];
                low_i = i;
            }
        }
        nn++;
        ans += low_min;
        s = low_i;
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
    cin>>T;
    int i, j;
    char temp_str[maxn];
    while(T--){
        num = 0;
        cin>>x>>y;
        cin.getline(temp_str,maxn,'\n');
        memset(MAP,0,sizeof(MAP));
        memset(dist,0,sizeof(dist));
        for(i = 0; i < y; i++){
            cin.getline(temp_str,maxn,'\n');
            for(j = 0; j < x; j++){
                if(temp_str[j] == '#')
                    MAP[i][j] = -1;
                else if(temp_str[j] == 'A' || temp_str[j] == 'S'){
                    MAP[i][j] = ++num;
                    node[num][0] = i;
                    node[num][1] = j;
                }
            }
        }
        for(i = 1; i <= num; i++)
            bfs(i);
        printf("%d\n",prim());

    }
    return 0;
}
