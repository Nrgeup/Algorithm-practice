#include<iostream>
#include<cstring>

using namespace std;

int matrix[101][101];
char M_str[101],N_str[101];
int M,N;

int Value_cmp[5][5]={
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
};

int  map_v(char a){
     switch (a){
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        case ' ':
            return 4;
        default:
            return -1;
     }
}

//  Value_cmp[map_v(a)][map_v(b)];

int get_min(int a, int b,int c){
    int temp = a > b ? a: b;
    return (temp > c ? temp : c);
}

int  dp(){

    int i,j,max_temp;
    matrix[0][0] = 0;
    for(i=0;i<= M;i ++){
        for(j=0;j<= N; j++){
            if(i==0 && j==0){
                    continue;
            }
            if(i==0){
                matrix[i][j] = matrix[i][j-1] + Value_cmp[map_v(' ')][map_v(N_str[j-1])];
                continue;
            }
            if(j==0){
                    matrix[i][j] = matrix[i-1][j] + Value_cmp[map_v(' ')][map_v(M_str[i-1])];
                continue;
            }
            matrix[i][j] = get_min( matrix[i-1][j-1] + Value_cmp[map_v(N_str[j-1])][map_v(M_str[i-1])] , matrix[i][j-1] + Value_cmp[map_v(' ')][map_v(N_str[j-1])]  ,  matrix[i-1][j] + Value_cmp[map_v(' ')][map_v(M_str[i-1])] );

         }
    }
    return matrix[M][N];
}

int main(){
    int times;
    cin>>times;
    while(times--){
        memset(matrix,0,sizeof(matrix));
        memset(M_str,0,sizeof(M_str));
        memset(N_str,0,sizeof(N_str));
        cin>>M>>M_str;
        cin>>N>>N_str;
        cout<<dp()<<endl;
    }
    return 0;
}
