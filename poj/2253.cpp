#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>


//#define LOCAL

using namespace std;

int n;
int flag[201];

struct stone{
    int x;
    int y;
}S[201];

float calc_distance(int a, int b){
    return sqrt((S[a].x - S[b].x)*(S[a].x - S[b].x) + (S[a].y - S[b].y)*(S[a].y - S[b].y));
}

float dijisk(){
    memset(flag,0,sizeof(flag));
    int i,j,imin_i,ok = 1;
    float temp_l,imin_l = 20000.0,max_l = 0;

    flag[0] = 1;
    while(ok){
        ok = 0;
        for(i = 0; i < n; i++){
            if(flag[i]){
                for(j = 0; j < n; j++){
                    if(i != j && !flag[j]){
                        ok = 1;
                        temp_l = calc_distance(i, j);
                        if(imin_l > temp_l){
                            imin_l = temp_l;
                            imin_i = j;
                        }
                    }
                }
            }
        }
        flag[imin_i] = 1;
        max_l = max_l > imin_l ? max_l : imin_l;
        if(flag[1])
            break;
        imin_l = 20000.0;
    }
    return max_l;
}


int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int T = 1,i;
    while(cin>>n && n){
        for(i = 0; i < n; i++)
            cin>>S[i].x>>S[i].y;
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",T++,dijisk());
    }
    return 0;
}
