#include<iostream>
#include<cstring>
//#include<cstdio>
//#include<cstdlib>
//#include <fstream>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int N;
char preorder[27];
char inorder[27];

void postorder(int l_pre, int r_pre, int l_in, int r_in){
    if((l_pre > r_pre) || (l_in > r_in))
        return;

    if(l_pre == r_pre){
        cout<<preorder[l_pre];
        return;
    }

    int mid;
    for( mid= l_in; mid <= r_in; mid ++){
        if( inorder[mid] == preorder[l_pre]){
            break;
        }
    }
    postorder(l_pre+1, l_pre+mid-l_in, l_in, mid - 1 );
    postorder( l_pre + mid - l_in +1, r_pre, mid+1,r_in);
    cout<<preorder[l_pre];
    return;
}

int main(){
    while(cin>>preorder>>inorder){
        N = 0;
        while(preorder[N] != '\0') N++;
        postorder(0,N-1,0,N-1);
        cout<<endl;
    }
    return 0;
}

