#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
//#include<cstdlib>
//#include <fstream>

using namespace std;

//T D H
double  param[3];
int check[3];


 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

void func(char c, double d){
    switch (c){
    case 'T':
        check[0] = 1;
        param[0] = d;
        break;
    case 'D':
         check[1] = 1;
        param[1] = d;
        break;
    case 'H':
         check[2] = 1;
        param[2] = d;
        break;
    }
}

void out(){
    int i,n;
    double temp_1,temp_2,d;
    for(i = 0; i < 3; i++)
    if(check[i] == 0){
        n = i;
        break;
    }
    switch(n){
        case 0:{
            temp_1 = 6.11 * exp( (5417.7530 * ((1/273.16) - (1/(param[1] + 273.16)))));
            temp_2 = (0.5555) * (temp_1 - 10.0);
            param[0] = param[2] - temp_2;
            break;
        }
        case 1:{
            temp_1 = param[2] - param[0];
            temp_2 = temp_1 / 0.5555 + 10.0;
            //e = 6.11 × exp [5417.7530 × ((1/273.16) - (1/(dewpoint+273.16)))]
            param[1] =(1 / ((1/273.16)  -  (log(temp_2 / 6.11)  /  5417.7530))) - 273.16;
            break;
        }
        case 2:{
            temp_1 = 6.11 * exp( (5417.7530 * ((1/273.16) - (1/(param[1] + 273.16)))));
            temp_2 = (0.5555) * (temp_1 - 10.0);
            param[2] = param[0] + temp_2;
            break;
        }
    }
    printf("T %.1f D %.1f H %.1f\n",param[0],param[1],param[2] );
}

int main(){
    char ch_temp;
    double d_temp;
    while(cin>>ch_temp){
        memset(check, 0, sizeof(check));
        if(ch_temp == 'E')
            break;
        cin>>d_temp;
        func(ch_temp,d_temp);
        cin>>ch_temp>>d_temp;
        func(ch_temp,d_temp);
        out();
    }

    return 0;
}
