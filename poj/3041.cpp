/****************************************************************************\
 *题意：这道题将每行x看成是结点x,没列y看成是结点y,而障碍物的坐标xy看成是从x到y的
    一条边。建图后问题就变成了，找最少的点，使得这些点与所有的边相邻，即最小
    点覆盖，用匈牙利算法解决。
 *
 *思路：
    定理：最小点覆盖数 = 最大匹配数，即求图的最大匹配即可，匈牙利算法
\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<cstring>

//#define LOCAL

using namespace std;

int n,k,r,c;
int g[550][550];
bool vis[10010];
int link[10010];

bool find(int v){
    for(int i=1; i<=n; i++){
        if(g[v][i] && !vis[i]){
            vis[i] = true;
            if(link[i] == 0 || find(link[i])){
                link[i] = v;
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
    int ans;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        memset(g,0,sizeof(g));
        memset(link,0,sizeof(link));
        for(int i = 0; i < k; i++){
            scanf("%d%d",&r,&c);
            g[r][c] = 1;
        }
        ans = 0;
        for(int i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));//清空上次搜索时的标记
            if(find(i))//从节点i尝试扩展
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
