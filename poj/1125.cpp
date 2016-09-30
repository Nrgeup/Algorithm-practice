/*
floyd算法
*/
#include<cstdio>
#include<iostream>
#include<cstring>

const int INF = 0x1f3f3f3f;

//#define LOCAL

using namespace std;

int MAP[102][102];
int N;

void floyd(){
    int i,j,k;
    for( k = 1; k <= N; k++){
        for( i = 1; i <= N; i++){
            for( j = 1; j <= N; j++){
                if(i == j) { MAP[i][j] = 0; continue;}
                MAP[i][j] = MAP[i][j] < (MAP[i][k] + MAP[k][j]) ? MAP[i][j] : (MAP[i][k] + MAP[k][j]);
            }
        }
    }

}

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i,j,temp,temp_n,temp_v,imin,Min,Max;
    while(cin>>N && N){

        for(i = 1; i <= N; i++)
            for(j = 1;j <= N;j++)
                MAP[i][j]=INF;

        for( i = 1; i <= N; i++){
            cin>>temp;
            for(j = 1; j <= temp; j++){
                cin>>temp_n>>temp_v;
                MAP[i][temp_n] = temp_v;
            }
        }
        floyd();
        Min = INF;
        for(i = 1; i <= N; i++){
            Max = 0;
            for( j = 1; j <= N; j++){
                if(Max < MAP[i][j]){
                    Max = MAP[i][j];
                }
            }
            if(Min > Max){
                imin = i;
                Min = Max;
            }
        }
        if(Min == INF){
            cout<<"disjoint\n";
        }
        else{
            cout<<imin<<" "<<Min<<endl;
        }
    }
    return 0;
}
