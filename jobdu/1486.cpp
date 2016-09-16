#include<cstdio>
#include<algorithm>
#include<cstring>

#define LOCAL

using namespace std;

int N,K;
int coin[1001];
int data[100][2][1001];
int num[100]; //0 : 0 = , 1 <  >  1: num
int pos;


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif


    /* TO DO  HERE!  */
    int i,j,k,n;
    char s[10];
    scanf("%d %d",&N,&K);
    memset(coin,0,sizeof(coin));
    pos = 0;
    for(i = 0; i < K; i ++){
        scanf("%d",&n);
        for(j = 0; j < n; j ++){
            scanf("%d",&data[pos][0][j]);
        }
        for(j = 0; j < n; j ++){
            scanf("%d",&data[pos][1][j]);
        }
        scanf("%s",&s);
        if(strcmp(s,"=")== 0){
            for(k = 0; k < n; k ++){
                coin[data[pos][0][k]]  =  1;
                coin[data[pos][1][k]]  =  1;
            }
        }
        else{
            num[pos] = n;
            pos++;
        }
    }



    for(i = 1; i <= N; i ++)
        printf("%d" , coin[i]);
    printf("\n");

    return 0;
}
