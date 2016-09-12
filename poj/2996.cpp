 #include <iostream>
#include <cstring>
//#include <fstream>

using namespace std;


 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int K[65][2],Q[65][2],R[65][2],B[65][2],N[65][2],P[65][2];
int num_K = 0,num_Q = 0,num_R = 0,num_B = 0,num_N = 0,num_P = 0;

char MAP[65][65];

void output(){
    int i;
    for( i = 0; i < num_K; i ++){
        cout<<"K"<<char(K[i][0]+'a')<<K[i][1]+1<<",";
    }
    for( i = 0; i < num_Q; i ++){
        cout<<"Q"<<char(Q[i][0]+'a')<<Q[i][1]+1<<",";
    }
    for( i = 0; i < num_R; i ++){
        cout<<"R"<<char(R[i][0]+'a')<<R[i][1]+1<<",";
    }
    for( i = 0; i < num_B; i ++){
        cout<<"B"<<char(B[i][0]+'a')<<B[i][1]+1<<",";
    }
    for( i = 0; i < num_N; i ++){
        cout<<"N"<<char(N[i][0]+'a')<<N[i][1]+1<<",";
    }
    for( i = 0; i < num_P-1; i ++){
        cout<<char(P[i][0]+'a')<<P[i][1]+1<<",";
    }
    cout<<char(P[i][0]+'a')<<P[i][1]+1<<endl;
}

int main() {
    int i,j;
    char temp_str[65],temp_char;
    cin>>temp_str;
    for( j = 7; j >= 0 ; j --){
        cin>>temp_char;
        for(i = 0; i < 8; i++){
            cin>>temp_char;
            cin>>MAP[i][j];
            cin>>temp_char>>temp_char;
        }
        cin>>temp_str;
    }

    for( j = 0; j < 8; j ++){
        for( i = 0; i < 8; i ++){
            if(MAP[i][j] == 'K'){
                K[num_K][0] = i;
                K[num_K++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'Q'){
                Q[num_Q][0] = i;
                Q[num_Q++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'R'){
                R[num_R][0] = i;
                R[num_R++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'B'){
                B[num_B][0] = i;
                B[num_B++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'N'){
                N[num_N][0] = i;
                N[num_N++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'P'){
                P[num_P][0] = i;
                P[num_P++][1] = j;
                continue;
            }
        }
    }
    cout<<"White: ";
    output();

    num_K = num_Q = num_R = num_B = num_N = num_P = 0;
    for( j = 7; j >= 0; j --){
        for( i = 0; i < 8; i ++
        ){
            if(MAP[i][j] == 'k'){
                K[num_K][0] = i;
                K[num_K++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'q'){
                Q[num_Q][0] = i;
                Q[num_Q++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'r'){
                R[num_R][0] = i;
                R[num_R++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'b'){
                B[num_B][0] = i;
                B[num_B++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'n'){
                N[num_N][0] = i;
                N[num_N++][1] = j;
                continue;
            }
            if(MAP[i][j] == 'p'){
                P[num_P][0] = i;
                P[num_P++][1] = j;
                continue;
            }
        }
    }
    cout<<"Black: ";
    output();
    return 0;
}
