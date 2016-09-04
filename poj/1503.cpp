#include<iostream>
#include<cstring>
//#include <fstream>

using namespace std;

char  str[102];
int temp[102];
int ans[102];
int n_ans;
int n_temp;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

void add(){

    int Max = n_temp > n_ans ? n_temp : n_ans;
    int i;
    for(i = 0; i < Max; i++){
        ans[i] += temp[i];
        if(ans[i] > 9){
            ans[i+1] += ans[i] / 10;
            ans[i] = ans[i] %10;
        }
    }
    if(ans[i]!=0){
        i++;
    }
    n_ans = i;
    return;
}

int main(){
    int i;
    memset(ans, 0, sizeof(ans));
    while(cin>>str){
        if(!strcmp(str ,"0")){
            for( i = n_ans - 1; i >= 0; i--)
                cout<<ans[i];
            cout<<endl;
            break;
        }
        memset(temp,0,sizeof(temp));
        n_ans = 0;
        while(str[n_temp] != '\0' )
            n_temp++;
        for(i = n_temp-1; i >= 0; i --){
            temp[n_temp - i -1] = str[i] - '0';
        }
        add();
    }
    return 0;
}
