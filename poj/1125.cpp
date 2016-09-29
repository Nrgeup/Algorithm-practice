#include<cstdio>
#include<iostream>
#include<cstring>


#define LOCAL

using namespace std;


int MAP[102][102];
int N;

int

int main(){
    //从文件读入
    #ifdef  LOCAL
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif

    /* TO DO  HERE!  */
    int i,j,temp,temp_n,temp_v;
    while(cin>>N && N){
        memset(MAP,0,sizeof(MAP));
        for( i = 1; i <= N; i++){
            cin>>temp;
            for(j = 1; j <= temp; j++){
                cin>>temp_n>>temp_v;
                MAP[i][temp_n] = temp_v;
            }
        }

        for(i = 1; i <= N; i++){
            for( j = 1; j <= N; j++){
                cout<<MAP[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
