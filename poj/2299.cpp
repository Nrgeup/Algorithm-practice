/*
	思路：先坐标离散化，然后树状数组求逆序数
	注意：结果要是long long 类型的;
*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
//#include <fstream>

using namespace std;

 //从文件读入
 //ifstream cin("input.txt");
//ofstream cout("output.txt");

#define Max 500002

struct Node{
    int val;
    int order;
};

int N;
Node a[Max];   //原始数据的数组
int aa[Max];   //离散之后的数组
int c[Max];


int cmp(Node a, Node b){
    return a.val < b.val;
}

int lowbit(int x){
    return x&(-x);
}

void add(int i, int val){
    for(; i <= N; i += lowbit(i))
        c[i] += val;
}

int getSum(int i){
    long long ans = 0;
    for(; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main(){
    int i;
    long long ans;
    while(cin>>N&&N){
        for(i = 1; i <= N; i++){
            cin>>a[i].val;
            a[i].order = i;
        }

        //坐标离散化
        sort(a + 1, a + N + 1, cmp);
        for(i = 1; i <= N; i ++)
            aa[a[i].order] = i;

        //树状数组求逆序树
        memset(c, 0, sizeof(c));
        ans = 0;
        for( i = 1; i <= N; i++){
            add(aa[i], 1);
            ans += (i - getSum(aa[i]) );
        }
        cout<<ans<<endl;
    }
    return 0;
}

