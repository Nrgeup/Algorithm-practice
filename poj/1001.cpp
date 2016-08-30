#include <iostream>
#include <cmath>
#include <algorithm>
#include<string>

using namespace std;

string  mul(string a, string b){
    string ans;

   // for(int i=a.begin() ; a<= )

    return ans;
}

int main(){
    string  R;
    int n;
    int number_point;
    while(cin>>R>>n){
        cout<<R<<" "<<n<<endl;
        reverse(R.begin(),R.end());
        cout<<R<<" "<<n<<endl;
        number_point = R.find_first_of('.');
        R.erase('.');
        cout<<R<<" "<<n<<endl;

    }
    return 0;
}
