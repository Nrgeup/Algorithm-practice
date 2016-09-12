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
char str[10000];

//a97 - A65 = 32
void func(int up, int down, int diff){
    switch(str[up]){
        case 'K':{
            MAP[str[up+1] - 'a'][str[up+2] - '1'] = 'K' + diff;
            break;
        }
        case 'Q':{
            MAP[str[up+1] - 'a'][str[up+2] - '1'] = 'Q' + diff;
            break;
        }
        case 'R':{
            MAP[str[up+1] - 'a'][str[up+2] - '1'] = 'R' + diff;
            break;
        }
        case 'B':{
            MAP[str[up+1] - 'a'][str[up+2] - '1'] = 'B' + diff;
            break;
        }
        case 'N':{
            MAP[str[up+1] - 'a'][str[up+2] - '1'] = 'N' + diff;
            break;
        }
        default:{
            MAP[str[up] - 'a'][str[up+1] - '1'] = 'P' + diff;
        }
    }
    return;
}


void output(){
    int i = 0,j;
    char temp_char;
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;
    for( j = 7; j >= 0 ; j --){
        cout<<"|";
        for(i = 0; i < 8; i++){
            if((i+j)%2==0)
                temp_char = ':';
            else
                temp_char = '.';
            cout<<temp_char;
            if(MAP[i][j]==' ')
                cout<<temp_char;
            else
                cout<<MAP[i][j];
            cout<<temp_char;
            cout<<"|";
        }
        cout<<endl<<"+---+---+---+---+---+---+---+---+"<<endl;
    }
}

int main() {
    int i,j;
    memset(MAP,' ',sizeof(MAP));
    cin>>str>>str;
    i = j = 0;
    while(1){
        while(str[j] != '\0' && str[j] != ',') j++;
        func(i,j-1,0);
        if(str[j] == '\0')
            break;
        i = j + 1;
        j = i;
    }
    cin>>str>>str;
    i = j = 0;
    while(1){
        while(str[j] != '\0' && str[j] != ',') j++;
        func(i,j-1,32);
        if(str[j] == '\0')
            break;
        i = j + 1;
        j = i;
    }
    output();
    return 0;
}
