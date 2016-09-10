/*
*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
//#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

unsigned int b[16] = {1,  2, 4, 8,
                        16, 32, 64, 128,
                        256, 512, 1024, 2048,
                        4096, 8192, 16384, 32768 };

unsigned int flip[16];

unsigned int Map[65540];
int cache[65590][2];

struct Node{
    unsigned value;
    short i;
    short j;
    short depth;
    unsigned int pre_i;
}ans[65590];

int up,down,ok;

void bfs(unsigned int n){
    unsigned int i,j,temp;
    up = down = 0;
    ans[down].value = n;
    ans[down].pre_i = 0;
    ans[down].depth = 0;
    Map[ans[down++].value] = 1;

    while( down > up){
        if(ans[up].value == 0){
            ok = up;
            break;
        }
        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                 temp = ans[up].value ^ flip[i*4 + j];
                if(!Map[temp]){
                    ans[down].value = temp;
                    ans[down].i = i + 1;
                    ans[down].j = j + 1;
                    ans[down].pre_i = up;
                    ans[down++].depth = ans[up].depth + 1;
                    Map[temp] = 1;
                }
            }
        }
        up++;
    }
    return;
}

void display(){
    int pos=0;
    cout<<ans[ok].depth<<endl;
    while(ans[ok].depth){
        cache[pos][0] = ans[ok].i;
        cache[pos++][1] = ans[ok].j;
        ok = ans[ok].pre_i;
    }
    pos --;
    while(pos >= 0){
        cout<<cache[pos][0]<<" "<<cache[pos][1]<<endl;
        pos -- ;
    }
    return;
}

int main(){
    int i,j,k;
    unsigned int n=0;
    char temp;

    for(i = 0; i < 16; i++){
            cin>>temp;
            if(temp == '+')
                n = n | b[i];
    }
    memset(flip, 0, sizeof(flip));
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            for( k = 0; k < 4; k ++){
                flip[i*4+j] = flip[i*4+j] | b[i*4+k];
                flip[i*4+j] = flip[i*4+j] | b[k*4+j];
            }
        }
    }

    memset(Map,0,sizeof(Map));
    ok = 0;
    bfs(n);
    display();
    return 0;
}
