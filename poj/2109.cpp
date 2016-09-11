#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double n,p;
    while(cin>>n>>p){
        cout<<pow(p,1/n)<<endl;
    }
    return 0;
}
