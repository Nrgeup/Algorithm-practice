#include<cstdio>
#include<iostream>

using namespace std;

#define LOCAL

int i, j, ok = 0, d, a, b;
long long x,y,m,n,l;
long long t, p, c;

void extend_euild(int a, int b){
    if(b == 0){
        t = 1;
        p = 0;
        c = a;
    }
    else{
        extend_euild(b, a%b);
        int temp = t;
        t = p;
        p = temp - a/b*p;
    }
}


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    while(cin>>x>>y>>m>>n>>l){
//     cout<<x<<"  "<<y<<"  "<<m<<"  "<<n<<"  "<<L<<endl;
     if(n == m)
        ok = 1;
      else{
        a = n-m;
        d = x-y;
        b = l;
        extend_euild(a, b);
        if(d % c !=0)
            ok = 1;
      }
      if(ok)
        cout << "Impossible" << endl;
      else{
        b = b / c;
        d = d / c;
        long long v = d * t;
        cout << (v%b+b)%b << endl;
      }
    }
    return 0;
}
