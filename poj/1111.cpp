#include<iostream>
#include<cstdio>
#include<cstring>

//#define LOCAL

using namespace std;

int MAP[22][22];
int flag[22][22];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int Ok[8]={1,1,1,1,0,0,0,0};
int r,l,rr,ll;

int ans;

void dfs(int rr,int ll,int ok){
    if(rr < 1 || rr > r || ll < 1 || ll > l || MAP[rr][ll] == 0){
        if(ok)
            ans ++;
        return;
    }
    int t,nx,ny;
    flag[rr][ll] = 1;
    for(t = 0; t < 8; t++){
        nx = rr + dir[t][0];
        ny = ll + dir[t][1];
        if(!flag[nx][ny])
            dfs(nx,ny,Ok[t]);
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // LOCAL

    int i,j;
    char temp;
    while(cin>>r>>l>>rr>>ll){
        if(r ==0 && l == 0 && rr == 0 && ll == 0)
            break;
        memset(MAP,0,sizeof(MAP));
        for(i = 1; i <= r; i++){
            for( j = 1; j <= l ; j++){
                cin>>temp;
                if(temp == 'X')
                    MAP[i][j] = 1;
            }
        }
        ans = 0;
        memset(flag,0,sizeof(flag));
        dfs(rr,ll,1);
        cout<<ans<<endl;
        /*
        for(i = 1; i <= r; i++){
            for(j = 1; j <= l; j++){
                cout<<MAP[i][j]<<" ";
            }
            cout<<endl;
        }
        */
    }


    return 0;
}
