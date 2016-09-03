#include<iostream>
#include<cstring>

using namespace std;

int mem[201][201];

int f(int n, int m){
    if(mem[n][m]!= -1)
        return mem[n][m];
    cout<<"";

	if (n == 0){
            mem[n][m] = 0;
        	return 0;
	}
   	if(m == 1){
            mem[n][m] = n;
        	return n;
   	}
    int maxx,minn,temp1,temp2;
    for(int i = 1; i < n+1; i++){
        	temp1 = f(i - 1, m - 1);
        	temp2 = f(n - i, m);
        	maxx = temp1 > temp2 ? temp1 : temp2;
        	minn = minn < maxx ? minn : maxx;
        }
        mem[n][m] = minn+1;
        return minn + 1;
}

int main(){
    memset(mem,-1,sizeof(mem));
    cout<<f(100,2)<<endl;
    memset(mem,-1,sizeof(mem));
    cout<<f(200,2)<<endl;
	return 0;
}
