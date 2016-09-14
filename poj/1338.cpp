/*
水题：
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

#define Max  1000005

int prim[Max];

void build_prim(){
    int i,j;
    memset(prim, 1, sizeof(prim));
    for(i = 3 ; i <= 1000 ; i += 2 ){
            for(j = 3 ; j <= Max / i ; j += 2){
                if(prim[i]){
                    prim[i * j] = 0;
                }
            }
    }
    for(i = 4 ; i <= Max ; i += 2 ){
		prim[i] = 0;
	}
	prim[1] = prim[0] = 0;
    return;
}

int main(){
    int a,d,n,i,j;
    build_prim();
    while(cin >> a >> d >> n,a != 0 && d != 0 && n != 0){
		j = 0;
		for (i = a; j < n; i += d){
			if (prim[i])
				j++;
		}
		cout << i - d << endl;
	}

    return 0;
}

