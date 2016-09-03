/*
思路：
    求出总长度sum和小棒最长的长度max，则原棒可能的长度必在max~sum之间，
    然后从小到大枚举max~sum之间能被sum整除的长度len，
    用dfs求出所有的小棒能否拼凑成这个长度，如果可以，第一个len就是答案。
    以一个小棒为开头，用dfs看看能否把这个小棒拼凑成len长，如果可以，用vis[i]记录下用过的小棒，然后继续以另外一个小棒为开头，以此类推。
减枝部分：
    1.搜索顺序。首先依据小棒长度进行由大到小的排序，在每一层搜索时首先将长度大的小棒填入当前原棒中。
        因为当相对长的小棒占据了原棒的大部分空间后能大大减小可行的搜索状态。
    2.利用排序剪枝。在组合同一支原棒的时候，由于检验小棒是否可用的顺序也是由大到小的，因此在检验到一支小棒可用时，
        如果当前棒还合填满，可能填入当前棒的小棒的长度也不会比现在填入的这支小棒长。因此，增加一个递归参数NEXT表示
        可能用于组合当前棒的第一支小棒的数组下标。参数传递时，若当前正好拼成一支原棒，NEXT还原回1，否则将NEXT+1传递给下一层递归。
    3.不进行重复搜索。即在某一状态，若将某一长度的小棒填入当前原棒进行搜索无法最终拼出所有原棒，则对于当前状态，
        相同长度的小棒也无法填入当前原棒而得到最终解。因此，在记录小棒长度的数组L中增加一指针用于指向下一个与之长度不同的小棒的数组下标，
        则搜索时，若某一长度小棒不成功，直接尝试下一个与之长度不同的小棒。
    4.还可以有更多优化。。。。。。学习中
*/
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
const int Max = 65;

int N,i,sum,ans;

int visit[Max];
int data[Max];
bool  flag;

int comp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

void dfs(int dep, int now_len, int u){   // dep为当前已被用过的小棒数，u为当前要处理的小棒。
    if(flag) return;
    if(now_len == 0){                    //  当前长度为0，寻找下一个当前最长小棒。
        int k = 0;
        while(visit[k]) k ++;              //  寻找第一个当前最长小棒。
        visit[k] = true;
        dfs(dep + 1, data[k], k + 1);
        visit[k] = false;
        return;
    }
    if(now_len == ans){                  //  当前长度为len，即又拼凑成了一根原棒。
        if(dep == N) flag = true;        //  完成的标志：所有的n根小棒都有拼到了。
        else dfs(dep, 0, 0);
        return;
    }
    for(int i = u; i < N; i ++)
        if(!visit[i] && now_len + data[i] <= ans){
            if(!visit[i-1] && data[i] == data[i-1]) continue;      //  不重复搜索：最重要的剪枝。
            visit[i] = 1;
            dfs(dep + 1, now_len + data[i], i + 1);
            visit[i] = 0;
        }
}

int main(){

    while(cin>>N && N != 0){
        sum = 0;
        for(i =0 ; i<N ;i++){
            cin>>data[i];
            sum += data[i];
        }
        qsort(data,N,sizeof(int),comp);
        flag = false;
        for(ans = data[0] ; ans <= sum ; ans++){
            if(sum%ans == 0){
                memset(visit, 0 ,sizeof(visit));
                dfs(0,0,0);
                if(flag){
                    cout<<ans<<endl;
                    break;
                }
            }
        }

    }
    return 0;
}
