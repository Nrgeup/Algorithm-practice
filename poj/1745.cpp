/*
用dp[i][j]表示通过前i个数的运算得到的余数为j可不可能，
先看求a % k，如果a > k，则a ＝ n * k + b，(n * k + b) % k == 0 + b % k = a % k，\
所以当a > k时，对求余数有影响的部分是不能被整除的部分，
因此对于每个数我们可以做a[i] = a[i] > 0 ? (a[i] % k) : -(a[i] % k)的预处理，
然后就是在dp[i - 1][j]的情况下，推出下一状态，下一状态有两种可能，加和减，减的时候防止出现负数加上个k再取余，
初始化dp[0][a[0]] = true最后只要判断dp[n - 1][0]及前n个数通过加减运算能否得到被k整除的值
*/
#include<cstdio>
#include<iostream>

//#define LOCAL

using namespace std;

int data[10002];
bool dp[10002][105];
int N,K;

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i;
    cin>>N>>K;
    memset(dp, false, sizeof(dp));
    for( i = 0; i < N; i++){
        cin>>data[i];
        data[i] = data[i] > 0 ? (data[i] % K) : -(data[i] % K);
    }
    dp[0][data[0]] = true;
    for(int i = 1; i < N; i++){
        for(int j = 0; j <= K; j++){
            if(dp[i - 1][j]){
                dp[i][(j + data[i]) % K] = true;
                dp[i][(K + j - data[i]) % K] = true;
            }
        }
    }
    printf("%s\n", dp[N - 1][0] ? "Divisible" : "Not divisible");
    return 0;
}
