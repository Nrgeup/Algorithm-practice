#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
//#include<cstdio>
//#include<cstdlib>
//#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

#define Max 1006

struct Node {
    double begin;
    double end;
}N[Max];

int n,d,ok,ans;

int cmp(Node x, Node y){
    if(x.begin != y.begin)
        return x.begin < y.begin;
    else
        return x.end < y.end;
}

void func(int i,int x,int y){
    if(y > d){
        ok = 0;
        return;
    }
    double area = sqrt(d*d - y*y);
    N[i].begin = x - area ;
    N[i].end = x + area;
    //cout<<N[i].begin<<"  "<<N[i].end<<endl;
}

void out(){
    int i;
    sort(N,N+n,cmp);
    double last_x = N[0].begin, last_y = N[0].end;
    ans = 1;
    for(i = 1; i < n; i++){
        if(N[i].begin <= last_y ){
            last_x = N[i].begin;
            last_y = last_y < N[i].end ? last_y : N[i].end;
            continue;
        }
        else{
            ans ++;
            last_x = N[i].begin;
            last_y = N[i].end;
        }
    }
}

int main(){
    int i,x,y,case_i = 1;
    while(cin>>n>>d){
        if(n == 0 && d == 0)
            break;
        ok = 1;
        for( i = 0; i < n; i++){
            cin>>x>>y;
            if(ok)
                func(i,x,y);
        }
        if(ok){
            out();
            cout<<"Case "<<case_i++<<": "<<ans<<endl;
        }
        else{
            cout<<"Case "<<case_i++<<": -1"<<endl;
        }
    }


    return 0;
}

