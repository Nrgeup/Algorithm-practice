#include<iostream>

using namespace std;



int ANS[14];

bool if_m_ok(int m,int K){
    bool ans  = false;
    int n = K*2, last = m%n;
    if(last ==0 ) {last=n;}
    while( (last >= K+1) && (last <= n) ){
        n =n-1;
        last = (m + last - 1) % n;
         if(last ==0 ) {last=n;}
          //cout<<"last = "<<last << "  n = "<< n<<endl;
    }
    return (n == K);
}


int main(){

    for(int nn = 1;nn <14;nn++){
       // cout<<nn<<endl;
        int i ,j;
        bool ok = false;
        for( i = 1 ;;i++){
            //cout<<"xsxsxsxs"<<endl;
            for(j = (2*i -1)*nn+1 ; j <= 2*i*nn ;j++){
            //cout<<"wwwwwwwwwww"<<endl;
                if(if_m_ok(j,nn)){
                   //cout<<j<<endl;
                   ANS[nn] = j;
                    ok = true;
                    break;
                }
            }
            if(ok){break;}
        }
    }

    int K;
    while(cin>>K && K != 0){
    cout<<ANS[K]<<endl;
    }
    return 0;
}
