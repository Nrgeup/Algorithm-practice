#include<cstdio>
#include<algorithm>
#include<cstring>

//#define LOCAL

using namespace std;

int data[601];
int MAP[1005][1005];
int N,Sum;

int gcd(int x, int y)
{
     if(y == 0) return x;
     if(x < y)      return gcd(y,x);
     else        return gcd(y, x%y);
}

bool  check(int a,int b){
    int ans = true;
    int Min = a,Max = b;
    if(a > b){
        Min = b;
        Max = a;
    }
    if(MAP[Min][Max] != -1)
        return MAP[Min][Max];
    if(gcd(Min,Max)!=1){
        ans = false;
    }
    MAP[Min][Max] = ans;
    return ans;
}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */

    int i,j;
    while(scanf("%d",&N)!=EOF && N!=0){
        memset(MAP,-1,sizeof(MAP));
        for(i = 0; i < N; i ++)
            scanf("%d",&data[i]);
        sort(data,data+N);
        Sum = 0;
        for(i = 0; i < N; i ++){
            for( j = i+1; j < N; j ++){
                if(check(data[i],data[j])){
                    Sum++;
                }
            }
        }
        printf("%d\n",Sum);
    }
    return 0;
}
