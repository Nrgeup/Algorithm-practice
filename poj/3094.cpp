#include<iostream>
#include<cstring>
#include<cstdio>
//#include<cstdlib>
//#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int main(){
    char str[256];
    long long ans = 0, i = 0;
    while(1){
        memset(str, 0, sizeof(str));
        cin.getline(str,256);
        ans = 0;
        for(i = 0; ; i++){
            if(str[i] == '\0'){
                cout<<ans<<endl;
                break;
            }
            if(str[i] == '#')
                return 0;
            if(str[i] != ' ')
                ans += (str[i] - 'A' + 1) * (i+1);
        }
    }
    return 0;
}
