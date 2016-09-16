#include<cstdio>
#include<cstring>

//#define LOCAL

using namespace std;


int N,M,S;
double V;

struct Edge
{
    int x,y;
    double r, c;
}E[210];

double Distant[105];



int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i,x,y,j;
    bool flag;
    double temp;
    scanf("%d %d %d %lf",&N,&M,&S,&V);

    memset(Distant,0,sizeof(Distant));

    for( i  = 0; i < M; i ++){
        scanf("%d %d",&x,&y);
        scanf("%lf %lf %lf %lf ",&E[2*i].r, &E[2*i].c , &E[2*i+1].r, &E[2*i+1].c );
        E[2*i].x = x;
        E[2*i].y = y;
        E[2*i+1].x = y;
        E[2*i+1].y = x;
    }

    Distant[S] = V;

    flag = true;
    while(flag){
        flag = false;
        for(j = 0; j <= 2*M+1; j ++){
            temp = (Distant[E[j].x] - E[j].c) * E[j].r;
            if(Distant[E[j].y] < temp){
                Distant[E[j].y]  = temp;
                if(E[j].y == S){
                    printf("YES\n");
                    return 0;
                }
                flag = true;
            }
        }
    }
    printf("NO\n");

    return 0;
}
