#include <iostream>
#include <algorithm>
using namespace std;
int data[10002];
int main() {
    int N,i;
    cin>>N;
    for(i = 0; i < N; i++)
        cin>>data[i];
    sort(data,data+N);
    cout<<data[N/2]<<endl;
    return 0;
}
