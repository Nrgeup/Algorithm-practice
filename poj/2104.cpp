#include <algorithm>
#include <cstdio>

using namespace std;

 //从文件读入
//ifstream cin("input.txt");
//ofstream cout("output.txt");

int n,m;

/*
int data[100001];
int temp[100001];

int output(int l, int r, int k){
    int i,j,t,key;
    while(l < r){
        for ( key = temp[ ((i=l) + (j=r)) >> 1 ] ; i < j; ){
            for (; key < temp[j]; j --);
            for(; temp[i] < key; i++);
            if(i<j) t =temp[i],temp[i] = temp[j], temp[j] = t;
        }
        if((k-1)>j) l = j+1;
        else r=j;
    }
    return temp[k-1];
}

int main(){
    int i,up,down,k;
    scanf("%d %d",&n,&m);
    for(i = 0; i < n; i ++)
        scanf("%d",&data[i]);
    for(i = 0; i < m; i ++){
        scanf("%d %d %d",&up,&down,&k);
        copy(data+up-1,data+down,temp);
        printf("%d\n",output(0,down - up,k));
    }
    return 0;
}
*/

struct node{
    int id;
    int val;
}data[100002];

int cmp(node a, node b){
    return a.val < b.val;
}

int main(){
    int i,up,down,k,j;
    scanf("%d %d",&n,&m);
    for(i = 0; i < n; i ++){
        scanf("%d",&data[i].val);
        data[i].id = i;
    }
    sort(data,data+n,cmp);
    for(i = 0; i < m; i ++){
        scanf("%d %d %d",&up,&down,&k);
        up--;
        down--;
        for(j = 0; j < n;j++){
            if(data[j].id>=up&&data[j].id<=down)
                    k--;
            if(!k){
                printf("%d\n",data[j].val);
                break;
            }
        }
    }
    return 0;
}
