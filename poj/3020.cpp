/****************************************************************************\
 *题意：
 *
 *思路：

\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<cstring>

//#define LOCAL

using namespace std;

const int nMax = 402;
const int rMax = 42;
const int cMax = 12;


struct{
    int v, next;
}edge[nMax*nMax];
int row, col, n, ver[nMax];
int k, edgeHead[nMax], link[nMax];
bool vis[nMax];
char map[rMax][cMax];
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};



bool inmap(int r, int c){
    if(r >= 0 && r < row && c >= 0 && c <= col)
        return true;
    return false;
}



bool dfs(int u){
    for(int i = edgeHead[u]; i != 0; i = edge[i].next){
        int v = edge[i].v;
        if(!vis[v]){
            vis[v] = true;
            if(link[v] == -1 || dfs(link[v])){
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int t,  r, c, i;
    scanf("%d", &t);
    while(t --){
        memset(edgeHead, 0, sizeof(edgeHead));
        scanf("%d%d", &row, &col);
        getchar();
        for(r = 0; r < row; r ++)
            scanf("%s", map[r]);
        for(k = 1, n = 0, r = 0; r < row; r ++)
            for(c = 0; c < col; c ++){
                if(map[r][c] == 'o') continue;
                ver[n ++] = r*col+c;
                for(i = 0; i < 4; i ++){
                    int rr = r + dr[i];
                    int cc = c + dc[i];
                    if(inmap(rr, cc) && map[rr][cc] == '*'){
                        edge[k].v = rr*col+cc;
                        edge[k].next = edgeHead[r*col+c];
                        edgeHead[r*col+c] = k ++;
                    }
                }
            }
        int ans = 0;
        memset(link, -1, sizeof(link));
        for(int i = 0; i < n; i ++){
            memset(vis, 0, sizeof(vis));
            if(dfs(ver[i])) ans ++;
        }
        printf("%d\n", n - ans/2);
    }
    return 0;
}
