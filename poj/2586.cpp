/*
    思路：贪心法，先假设每个月都亏损，然后逐个假设每个月不亏损，
    即若假设该月盈利，则其不破坏每连续5个月都亏损的条件即可
*/
#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<cmath>
//#include<cstdlib>
//#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int s,d;
int  earn[8];

int main(){
    int i,j,temp,sum;
    while(cin>>s>>d){
        for( i = 0; i < 8; i++)
            earn[i] = 5*(-d);
        sum = 0;
        for( i = 0; i < 12; i ++){
            temp = 1;
            for( j = 0; j < 5; j ++){
                if(i + j < 12 && i + j >= 4 ){
                    earn[i +j - 4] +=  (s + d);
                    if(earn[i + j - 4] > 0){
                        earn[i +j - 4] -=  (s + d);
                        temp = 0;
                        break;
                    }
                }
            }
            if(temp)
                sum += s;
            else
                sum -= d;
        }
        if(sum >= 0)
            cout<<sum<<endl;
        else
            cout<<"Deficit"<<endl;
    }
    return 0;
}
