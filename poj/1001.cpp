#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char str[10];
int a[99999],b[99999],ans[99999];
int len_a,len_b,pos_dot = 0;
int N;

void mul(){
    memset(ans,0,sizeof(ans));
    int i,j;
    for( i = 0; i< len_a ;i++){
        for( j = 0; j < len_b;j++){
            ans [ i + j ] = ans [ i + j ] + a[i] * b[j];
            if(ans[i+j] > 9){
                ans[i+j+1] = ans[i+j+1]  + ans[i+j] /10;
                ans[i+j]  = ans[i+j]  %10;
            }
        }
    }

    if( ans[len_a + len_b +1] != 0){
        len_a = len_a + len_b +1;
    }
    else{
        len_a = len_a + len_b;
    }

    for(i =0 ;i < len_a ;i++){
        a[i] = ans[i];
    }

    return;
}

void print(int len ,int* D){
    int first = len -1,last =0;

    while(D[last] == 0 && last <= ((pos_dot) * N) ){
        last  ++;
    }

    while(D[first] == 0 && first >= ((pos_dot) * N) ){
        first  --;
    }

    for(int i=first; i>=last ;i--){
        if(i  ==  pos_dot * N -1 ){
            cout<<'.';
        }
        cout<<D[i];
    }
    cout<<endl;
}

int main(){
    int i,j;
    while(cin>>str>>N){
        pos_dot = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        if( N== 0){
            cout<<"0"<<endl;
            continue;
        }
        len_a = len_b = 6;
        for(i=5,j = 0; i >= 0 ;i --){
            if(str[i] != '.'){
                a[j] = b[j] = str[i] - '0';
                j++;
            }
            else{
                pos_dot = j;
                len_a -- ;
                len_b -- ;
            }
        }

        for(i = 1 ;i <N; i++){
            mul();
        }
        print(len_a,a);
    }
    return 0;
}
