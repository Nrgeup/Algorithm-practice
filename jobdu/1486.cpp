/*

(1) 当结果为even(=)时，说明称上的几个硬币一定是真币
(2) 当结果为up(>)时，说明其余的硬币一定是真币，并且重的硬币一定在左边，轻的硬币一定在右边（所以这是把左边的硬币标记为重，右边的硬币标记为轻）。
(3) 当结果为down(<)时，说明其余的硬币一定是真币，并且重的硬币一定在右边，轻的硬币一定在左边（所以这是把左边的硬币标记为轻，右边的硬币标记为重）。
(4) 如果上次判断一个钱币为真币，则不论下次结果如何，它还应当是真币；如果上次判断它可能较轻，而本次判断它可能较重，则它一定是真币
    （等于说是这种不平衡是由其它硬币造成的，因为如果该硬币为假币的话，假设它较重，那一定是它在哪边，哪边就较重，而不会出现这种又重又轻的情况），反之亦然！
(5)用一个数组记录每个钱币的状态，初始为-1（表示不确定状态），如果一定为真币记为0，如果可能较重记为2，如果可能较轻记为1，最后判断大于0的钱币一定为假币，而相应的状态表示它的相对重量。

*/
#include<iostream>
#include<cstdio>s
#include<algorithm>
#include<cstring>

//#define LOCAL

using namespace std;

int N,K;
int coin[1001];
int check[1001];
int data[2][1001];

void pro(int i, int v){
    if(coin[i] == -1 || v == 0)
        coin[i] = v;
    if((coin[i] == 1 && v == 2) || (coin[i] == 2 && v == 1))
        coin[i] = 0;
    return;
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i,j,k,n;
    char s;
    while(scanf("%d %d",&N,&K)!= EOF){
        memset(coin,-1,sizeof(coin));
        for(i = 0; i < K; i ++){
            scanf("%d",&n);
            for(j = 0; j < n; j ++){
                scanf("%d",&data[0][j]);
            }
            for(j = 0; j < n; j ++){
                scanf("%d",&data[1][j]);
            }
            cin>>s;
            if(s == '=' ){
                for(k = 0; k < n; k ++){
                    pro(data[0][k],0);
                    pro(data[1][k],0);
                }
                continue;
            }
            memset(check,0,sizeof(check));
            if(s == '<'){
                for(k = 0; k < n; k ++){
                    pro(data[0][k],1);
                    pro(data[1][k],2);
                    check[data[0][k]] = check[data[1][k]] = 1;
                }
            }
            if(s == '>' ){
                for(k = 0; k < n; k ++){
                    pro(data[0][k],2);
                    pro(data[1][k],1);
                    check[data[0][k]] = check[data[1][k]] = 1;
                }
            }

            for(j = 1; j <= N; j ++){
                if(!check[j])
                    pro(j,0);
            }
        }

        int ok = 0,sum=0;
        for(i = 1; i <= N; i ++){
            if(coin[i] > 0 || coin[i] == -1){
                ok = i;
                sum++;
            }
        }
        if(sum > 1 ){
            ok = 0;
        }
        printf("%d\n" , ok);
    }
    return 0;
}
