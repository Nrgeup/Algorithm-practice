#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
//#include<cstdlib>
#include <fstream>

using namespace std;


 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int N;
int data[1010];
int Map[1010];

struct node{
    int val;
    int pos;
}AA[1010];

int cmp(node a, node b){
    if(a.val == b.val)
		return a.pos < b.pos;
    return a.val < b.val;
}

void update(int index){
        while(index <= N){
            Map[index] += 1;
            index += (index&(-index));
        }
}

long long sum(int index){
    long long ans = 0;
    while(index >= 1){
        ans += Map[index];
        index -= (index&(-index));
    }
    return ans;
}

int main(){
    int ii,K,i;
    cin>>K;
    for( ii = 1; ii <= K; ii ++){
        cout<<"Scenario #"<<ii<<":"<<endl;
        cin>>N;
        for(i = 1; i <= N; i ++){
            cin>>AA[i].val;
            AA[i].pos = i;
        }
        sort(AA + 1,AA + N + 1,cmp);
        for(i = 1; i <= N; i ++){
            data[AA[i].pos] = i;
        }

        memset(Map,0,sizeof(Map));
        long long  ans = 0;
        for(i = 1; i <= N; i++){
            update(data[i]);
            ans += ( i - sum(data[i]));
        }
        cout<<ans<<endl<<endl;

    }
    return 0;
}
