#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
//#include<cstdlib>
#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int MAP[11][11];
int pos[11][11];
int row,col,origin;

int dir[5][2]{
    {0, 0},
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int getDir(char n){
    switch (n){
        case 'N':{
            return 1;
        }
        case 'E':{
            return 2;
        }
        case 'S':{
            return 3;
        }
        case 'W':{
            return 4;
        }
    }
}

void func(){
    memset(pos,-1,sizeof(pos));
    int x = 0,y = origin - 1;
    int n_x,n_y;
    pos[x][y] = 0;
    while(1){
        n_x = x + dir[MAP[x][y]][0];
        n_y = y + dir[MAP[x][y]][1];
        if(n_x >= row || n_x < 0 || n_y >= col || n_y < 0){
             cout<<pos[x][y] + 1<<" step(s) to exit"<<endl;
            return;
        }
        if(pos[n_x][n_y] != -1){
             cout<<pos[n_x][n_y]<<" step(s) before a loop of "<<pos[x][y] - pos[n_x][n_y] + 1<<" step(s)"<<endl;
            return;
        }
        pos[n_x][n_y] = pos[x][y] + 1;
        x = n_x;
        y = n_y;
    }

}

int main(){
    int i,j;
    char temp;
    while(cin>>row>>col>>origin){
        if(row == 0 && col == 0 && origin == 0)
            break;
         for( i = 0; i < row; i ++)
            for(j = 0; j < col; j ++){
                cin>>temp;
                MAP[i][j] = getDir(temp);
            }

        func();

    }
    return 0;
}
