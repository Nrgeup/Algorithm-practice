/****************************************************************************\
 *题意：各个城市之间要铺设光缆，求是每个城市联通起来最少的长度耗费
 *
 *思路：最小生成树问题，使用kuscal算法

\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<string>
#include<cstring>
#include<algorithm>


//#define LOCAL

using namespace std;

const int maxn = 1000;


float Max_tenth;
int n,m;
int par[maxn];
char name[maxn][22];

struct Edge{
    int head;
    int tail;
    float val;
}E[maxn * maxn];

int cmp(Edge a, Edge b){
    return a.val < b.val;
}

int getIndex(char Name[22]){
    int ans = 0;
    for(; ans < n; ans++){
        if(strcmp(Name, name[ans]) == 0)
            break;
    }
    return ans;
}

int getParent(int index){
    if(par[index] == index)
        return index;
    return getParent(par[index]);
}


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i,num,x,y;
    float temp_val,sum;
    char temp_name1[22],temp_name2[22];
    scanf("%f", &Max_tenth);
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", name[i]);
    }

    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%s %s %f", &temp_name1, &temp_name2, &temp_val);
        E[i].head = getIndex(temp_name1);
        E[i].tail = getIndex(temp_name2);
        E[i].val = temp_val;
    }

    sort(E, E + m, cmp);
    for(i = 0; i < n; i++)
        par[i] = i;

    for(i = 0, num = 0, sum = 0; i < m; i++){
        //printf("%d => %d : %f\n", E[i].head, E[i].tail, E[i].val);
        if(num == n - 1)
            break;
        x = getParent(E[i].head);
        y = getParent(E[i].tail);
        if(x != y){
            sum += E[i].val;
            num++;
            par[y] = x;
        }
    }

    if(sum > Max_tenth)
        printf("Not enough cable\n");
    else
        printf("Need %.1f miles of cable\n", sum);

    return 0;
}
