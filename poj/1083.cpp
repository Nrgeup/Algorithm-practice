/*
思路：
    水题一个，考虑占用每个空间的最大move即可
    注意s 可能 大于 t
*/

//#include<fstream>
#include<cstring>
#include<iostream>

using namespace std;

int N,K;

int Map[202];  // 1 ~ 200

//从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int main(){
    int i,r,l,j,L,R,ans,temp;
    cin>>N;
    while(N--){
        memset(Map, 0 , sizeof(Map));
        cin>>K;
        for(i = 0; i < K; i ++){
            cin>>l>>r;
            L = (l +1) / 2;
            R = (r + 1) / 2;
            if(L > R){
                temp = L;
                L = R;
                R = temp;
            }
            for(j = L; j <= R; j++)
                Map[j]++;
        }
        ans = 0;
        for( i = 1; i <= 200; i++)
            if(ans < Map[i])
                    ans = Map[i];
        cout<<ans*10<<endl;
    }
	return 0;
}
