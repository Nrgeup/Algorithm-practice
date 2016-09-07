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

#define Max  10001

int ans[Max];
int prim[Max];
int length;

bool is_prim(int n){
    int i = 2;
    for( i = 2; i * i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}


int main(){
    int i,j;
    memset(ans, 0, sizeof(ans));
    length = 0;
    for( i = 2; i < Max; i ++){
        if(is_prim(i)){
            prim[length ++] = i;
        }
    }

    int sum;
    for( i = 0; i < length; i++){
        sum = 0;
        for( j = i; j < length; j++){
            sum += prim[j];
            if(sum < Max)
                ans[sum]++;
        }
    }

    while(cin>>i && i != 0){
        cout<<ans[i]<<endl;
    }

    return 0;
}

