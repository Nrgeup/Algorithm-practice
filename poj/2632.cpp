#include<iostream>
#include<cstring>
#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int K,A,B,N,M,temp,No,ok;
char dir;

//map[i][j]:  0 no robot / robot number i
//ROBOT[i][0]:  1 N, 2  E,3  S ,4 W
int MAP[101][101];
int ROBOT[101][3];

int DIR[4][2]{
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int getDir(char n){
    if(n == 'N')
         return 1;
     else if(n == 'E')
        return 2;
     else if(n == 'S')
        return 3;
    else if(n == 'W')
        return 4;
}

void commend(int robot, char order, int time){

    switch (order){
        case 'L':{
            time = time % 4;
            if(time != 0){
                ROBOT[robot][0] = ROBOT[robot][0]  - time;
                if(ROBOT[robot][0] < 1){
                    ROBOT[robot][0]  += 4;
                }
            }
            break;
        }
        case 'R':{
            time = time % 4;
            if(time != 0){  // 1 2 3 4     (1 2 3)
                ROBOT[robot][0] = ROBOT[robot][0]  + time;
                if(ROBOT[robot][0] > 4){
                    ROBOT[robot][0]  -= 4;
                }
            }
            break;
        }

        case 'F':{

            int n_x =ROBOT[robot][1] ,n_y= ROBOT[robot][2];
            int ii;
            for ( ii = 1; ii <= time; ii ++){
                n_x += DIR[ROBOT[robot][0]-1][0];
                n_y += DIR[ROBOT[robot][0]-1][1];
                if(n_x < 1 || n_x > A || n_y < 1 || n_y > B){
                    cout<<"Robot "<<robot<<" crashes into the wall"<<endl;
                    ok = 0;
                    return;
                }
                if(MAP[n_x][n_y]!=0){
                    cout<<"Robot "<<robot<<" crashes into robot "<<MAP[n_x][n_y]<<endl;
                    ok = 0;
                    return;
                }
            }
            MAP[ROBOT[robot][1]][ROBOT[robot][2]] = 0;
            MAP[n_x][n_y] = robot;
            ROBOT[robot][1] = n_x;
            ROBOT[robot][2] = n_y;

            break;
        }

    }

}

int main(){
    cin>>K;
    while(K--){
        ok = 1;
        memset(MAP,0,sizeof(MAP));
        memset(ROBOT,0,sizeof(ROBOT));
        cin>>A>>B>>N>>M;
        //cout<<" A= "<<A<<"  B= "<<B<<"  N =  "<<N<<"  M =  "<<M<<endl;
        int x,y;
        for(int i = 1; i <= N; i ++){
            cin>>x>>y>>dir;
            MAP[x][y] = i;
            ROBOT[i][0] = getDir(dir);
            ROBOT[i][1] = x;
            ROBOT[i][2] = y;
            //cout<<" i = "<<i<<" x = "<<x<<" y = "<<y <<endl;
        }
/*
        for(int i = 1; i <= N; i++){
            cout<<"robot "<<i<<"  "<<ROBOT[i][0]<<"  "<<ROBOT[i][1]<<"  "<<ROBOT[i][2]<<endl;
        }
*/
        for(int i = 1; i <= M; i++){
            cin>>No>>dir>>temp;
            //cout<<" No = "<<No<<" dir =  "<<dir<<"  temp =  "<<temp<<endl;
            if(ok){
               commend(No,dir,temp);

/*
                int ii,jj;
                for(ii= 1; ii <= A; ii ++){
                    for(jj = 1; jj <= B; jj ++){
                        cout<<"("<<MAP[ii][jj]<<","<<ROBOT[MAP[ii][jj]][0]<<")"<<" ";
                    }
                    cout<<endl;
                }
*/

            }
        }
        if(ok){
            cout<<"OK"<<endl;
        }
    }
    return 0;
}
