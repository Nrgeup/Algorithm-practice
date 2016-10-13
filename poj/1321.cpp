/****************************************************************************\
 *题意：在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
       请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
 *
 *思路：  深度搜索dfs

\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<cstring>

//#define LOCAL

using namespace std;

const int maxn = 10;
int c, n, k, Map[maxn][maxn], flag[maxn], num;

void dfs(int depth){
    if(num == k){
        c++;
        return;
    }
    if(depth == n){
        return;
    }
    for(int i = 0; i < n; i++){
        if(!flag[i] && Map[depth][i]){
            flag[i] = 1;
            num++;
            dfs(depth+1);
            num--;
            flag[i] = 0;
        }
    }
    dfs(depth+1);
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i, j;
    char temp_str[maxn];
    while(scanf("%d %d", &n, &k) != EOF){
        if(n == -1 && k == -1)
            break;
        c = 0;
        memset(Map, 0 ,sizeof(Map));
        for(i = 0; i < n; i++){
            scanf("%s", &temp_str);
            for(j = 0; j < n; j++){
                if(temp_str[j] == '#')
                    Map[i][j] = 1;
            }
        }
        memset(flag, 0 ,sizeof(flag));
        num = 0;
        dfs(0);
        printf("%d\n", c);
    }
    return 0;
}
