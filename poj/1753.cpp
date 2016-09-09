/*


*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");


unsigned int b[16] = {1,  2, 4, 8,
                        16, 32, 64, 128,
                        256, 512, 1024, 2048,
                        4096, 8192, 16384, 32768 };
unsigned int w[16]  = {};

unsigned int flip[16];

int Map[65540];

int dir[4][2] ={
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
} ;

unsigned int ans[65590];
unsigned int depth[65590];
int up,down;
int ok,depth_ans=0;

void bfs(int n){
    int i;
    unsigned int temp;
    up = 0;
    down = 1;
    ans [up] = n;
    depth[up] = 0;

    while( down > up){
        for(i = 0; i < 16; i++){
            if(ans[up] == 0 || ans[up] == 65535){
                ok = 1;
                depth_ans = depth[up];
                return;
            }
            temp = ans[up] ^ flip[i];
            if(!Map[temp]){
                Map[temp] = 1;
                depth[down] = depth[up] +1;
                ans[down++] = temp;
            }
        }
        up++;
    }
}

int main(){
    int i,j,k,new_i,new_j;
    unsigned int n=0;
    char temp;

    for(i = 0; i < 16; i++){
            w[i] = ~b[i];
            cin>>temp;
            if(temp == 'b')
                n = n | b[i];
    }
    memset(flip, 0, sizeof(flip));
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            flip[i*4+j] = flip[i*4+j] | b[i*4+j];
            for(k = 0; k < 4; k++){
                new_i = i + dir[k][0];
                new_j = j + dir[k][1];
                if(new_i >= 0 && new_i < 4&& new_j >= 0 && new_j < 4){
                    flip[i*4+j] = flip[i*4+j] | b[new_i*4+new_j];
                }
            }
        }
    }

    memset(Map,0,sizeof(Map));
    ok = 0;
    bfs(n);
    if(ok){
        cout<<depth_ans<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }
    return 0;
}
