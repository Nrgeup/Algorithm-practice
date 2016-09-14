#include <iostream>
#include <queue>
using namespace std;
typedef pair<unsigned long, int> node_type;
int main(){
    unsigned long result[1500];
    priority_queue< node_type, vector<node_type>,
     greater<node_type> > Q;
    Q.push( make_pair(1, 2) );
    for (int i=0; i<1500; i++){
        node_type node = Q.top();
        Q.pop();
        switch(node.second){
            case 2: Q.push( make_pair(node.first*2, 2) );
            case 3: Q.push( make_pair(node.first*3, 3) );
            case 5: Q.push( make_pair(node.first*5, 5) );
        }
        result[i] = node.first;
    }
    int n;
    cin >> n;
    while (n>0){
        cout << result[n-1] << endl;
        cin >> n;
    }
    return 0;
}
