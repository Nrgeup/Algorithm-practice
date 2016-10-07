/****************************************************************************\
 *题意：求给定的第几个条件之后可以决定图的状态
 *
 *思路：拓扑排序：先判断是否有环（3），再判断是否有序（1），最后才能判断是否能得出结果（2）。注意：对于（2）必须遍历完整个图，而（1）和（3）一旦得出结果，对后面的输入就不用做处理了。

\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<cstring>

//#define LOCAL

using namespace std;

int map[27][27], indegree[27], q[27];


int TopoSort(int n){ //拓扑排序
    int c = 0, temp[27], loc, m, flag = 1, i, j;  ////flag=1:有序 flag=-1:不确定
    for(i = 1; i <= n; i++)
        temp[i] = indegree[i];
    for(i = 1; i <= n; i++){
        m = 0;
        for(j = 1; j <= n; j++)
            if(temp[j] == 0){
                m++;
                loc = j;
            }  //查找入度为零的顶点个数
        if(m == 0) return 0;  //有环
        if(m > 1) flag = -1;  // 无序  （注：没有立即结束是因为后面可能有环）
        q[c++] = loc;   //入度为零的点入队
        temp[loc] = -1;
        for(j = 1; j <= n; j++)
            if(map[loc][j] == 1) temp[j]--;
    }
    return flag;
}


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int m, n, i, sign;  //当sign=1时，已得出结果
    char str[5];
    while(scanf("%d%d",&n,&m)){
        if(m == 0 && n == 0) break;
        memset(map, 0, sizeof(map));
        memset(indegree, 0, sizeof(indegree));
        sign = 0;
        for(i = 1; i <= m; i++){
            scanf("%s",str);
            if(sign) continue; //一旦得出结果，对后续的输入不做处理
            int x=str[0]-'A'+1;
            int y=str[2]-'A'+1;
            map[x][y]=1;
            indegree[y]++;
            int s=TopoSort(n);
            if(s==0){//有环
                printf("Inconsistency found after %d relations.\n",i);
                sign=1;
            }
            if(s==1){ //有序
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    printf("%c",q[j]+'A'-1);
                printf(".\n");
                sign=1;
            }
        }
        if(!sign) //不确定
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
