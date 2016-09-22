#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

//#define LOCAL

int n,m,r;

struct Interval{
    int s;
    int e;
    int v;
}N[1002];

int cmp(Interval a, Interval b){
    if(a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}

long long DP[1002],Max,temp;


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>r;

    for(int i = 0; i < m; i ++){
        cin>>N[i].s>>N[i].e>>N[i].v;
        N[i].e += r;
    }

    sort(N,N+m,cmp);

    int i,j;
    Max  = 0;
    for(i = 0; i < m; i ++){
        DP[i] = N[i].v;
        temp = 0;
        for(j = 0; j < i; j++){
            if(N[j].e <= N[i].s){
                temp = temp > DP[j] ? temp : DP[j];
            }
        }
        DP[i] += temp;
        Max = Max > DP[i] ? Max : DP[i];
    }
    cout<<Max<<endl;

    return 0;
}
