#include<iostream>
#include<cstring>

using namespace std;

int n,nn,m,mm,a;

int ans[30];
int A[30];
int n_A;
int n_B;
int B[30];

void  out(int a, int b){
    memset(ans, 0, sizeof(ans));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    n_A = 0;
    while(a>9){
        A[n_A ++] = a % 10;
        a = a / 10;
    }
    A[n_A ++] = a ;
    n_B = 0;
    while(b>9){
        B[n_B ++] = b % 10;
        b = b / 10;
    }
    B[n_B ++] = b;

    int i,j,Max = 0;
    for(i = 0; i < n_A; i++){
        for(j = 0; j < n_B; j++){
            ans[i+j] += A[i]*B[j];
            Max = i + j;
            if(ans[i+j] > 9){
                ans[i+j + 1] += ans[i+j]  / 10;
                Max = i + j +1;
                ans[i+j]  %= 10;
            }
        }
    }

    if(ans[n_A + n_B -1] > 9){
        ans[n_A + n_B ] =  ans[n_A + n_B -1]  / 10;
        ans[n_A + n_B ] %= 10;
        Max ++;
    }

    for( i = Max; i >= 0; i--)
        cout<<ans[i];
    cout<<endl;
    return;
}

int main(){
	cin>>n>>m>>a;
	nn = n /  a ;
	if((n % a) != 0)
        nn++;
	mm = m /  a ;
	if((m % a)!=0)
        mm++;
	out(nn,mm);
	return 0;
}
