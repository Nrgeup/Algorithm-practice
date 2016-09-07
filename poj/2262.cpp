/*
水题： 注意记忆化判断素数，否则会超时
*/
#include<iostream>
#include<cstring>
#include<cmath>
//#include<cstdio>
//#include<cstdlib>
//#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

#define Max  1000001

int prim[Max];
int length;

bool is_prim(int n){
    if(prim[n] != -1)
        return prim[n];
    int i = 2;
    for( i = 2; i * i <= n; i++){
        if(n % i == 0){
            prim[n] = 0;
            return false;
        }
    }
    prim[n] = 1;
    return true;
}

int main(){
    int i,j,k;
    memset(prim, -1, sizeof(prim));
    while(cin>> k&& k != 0){
        for( i = 3 ; i < Max; i += 2){
            if(is_prim(i) && is_prim(k - i)){
                cout<<k<<" = "<<i<<" + "<<k-i<<endl;
                break;
            }
        }
    }

    return 0;
}

