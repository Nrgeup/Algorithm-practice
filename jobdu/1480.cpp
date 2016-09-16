#include<cstdio>
#include<algorithm>
#include<cstring>

//#define LOCAL

using namespace std;

int data[1002];
int ans[1002];
int N,Max;


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */

    int i,j;
    while(scanf("%d",&N)!=EOF && N!=0){
        memset(ans,0,sizeof(ans));
        for(i = 0; i < N; i ++)
            scanf("%d",&data[i]);
        Max = 0;
        ans[0] = data[0];

        for( i = 1; i < N; i ++){
            ans[i] = data[i];
            for(j=0; j < i; j ++){
                if(data[j] < data[i]){
                    ans[i] = ans[i] > (ans[j] + data[i]) ? ans[i]:(ans[j] + data[i]) ;
                }
            }
            Max = Max > ans[i] ? Max : ans[i];
        }
        printf("%d\n",Max);
    }
    return 0;
}
