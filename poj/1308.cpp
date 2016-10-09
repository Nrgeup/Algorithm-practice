/****************************************************************************\
 *题意：给定边，判断是不是一棵树
 *
 *思路：使用并查集判断有无环，若有环，则直接不是树；
      若无环，还需要判断是不是森林，记录一下root的个数，若等于1或0（空树）则是一棵树

\****************************************************************************/
#include<cstdio>   //尽量使用scanf和printf输入输出
#include<cstring>

//#define LOCAL

using namespace std;

const int maxn = 101;

int node[maxn];
int if_root[maxn], num_root = 0;

int find_parent(int i){
    if(node[i] == i)
        return i;
    return find_parent(node[i]);
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int x, y, case_i = 1, ok = 1, i;
    for(i = 0; i < maxn; i++)
        node[i] = i;
    while(scanf("%d %d", &x, &y) != EOF){
        if(x == -1 && y == -1)
            break;
        if(x == 0 && y == 0){
            if(ok && num_root <= 1)
                printf("Case %d is a tree.\n", case_i);
            else
                printf("Case %d is not a tree.\n", case_i);
            case_i++;
            ok = 1;
            num_root = 0;
            for(i = 0; i < maxn; i++)
                node[i] = i;
            memset(if_root, 0, sizeof(if_root));
            continue;
        }
        if(ok){
            x = find_parent(x);
            y = find_parent(y);
            if(x == y)
                ok = 0;
            else{
                node[y] = x;
                if(!if_root[x]){
                    num_root ++;
                    if_root[x] = 1;
                }
                if(if_root[y]){
                    num_root --;
                    if_root[y] = 0;
                }
            }
        }
    }
    return 0;
}
