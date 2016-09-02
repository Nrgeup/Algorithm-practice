/*
    思路：
    N个节点的树具有卡特兰数列个形态，先找到其是第几个节点的第几个形态：
    接下来是来解决这棵二叉树中左子树有多少个节点，右子树有多少节点。
    有题意可知，初始状态下，左子树为空，所有的节点均在右子树上并且所有节点只有右孩子；
    当右子树的所有节点变化完以后，将右子树中的一个节点分配给左子树，
    此时右子树的节点少了一个并且所有右子树的节点全部是初始化状态，依此类推。
*/

#include<iostream>

using namespace std;


//卡特兰数
int catalan[] = {1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012, 742900,2674440,9694845,35357670,129644790,477638700 };

//处理第K个节点第n位的树
void solve(int K,  int cnt){
    //cout<<endl<<" K = "<< K<<"  cnt = " <<cnt<<endl;
    if(K == 1){
        cout<<"X";
        return;
    }
    int L,L_cnt,R,R_cnt;
    for(L = 0 ; ;L++ ){
        if(cnt > catalan[L]*catalan[K - L -1]){
            cnt = cnt - catalan[L]*catalan[K - L -1];
        }
        else{
                R = K - L -1;
                L_cnt = (cnt-1) / catalan[R]+1;
                R_cnt = (cnt-1) % catalan[R]+1;
                if(R_cnt == 0)
                    R_cnt = catalan[R];
                break;
        }
    }

    if( L != 0){
        cout<<"(";
        solve(L,  L_cnt);
        cout<<")";
    }
    cout<<"X";
    if( R != 0){
        cout<<"(";
        solve(R,  R_cnt);
        cout<<")";
    }
    return;
}


int main(){
   int N,i,K;

   while(cin>> N &&  N != 0){
       N++;
        for(i = 0;;i++){
            if(N > catalan[i]){
                N  = N - catalan[i];
            }
            else{
                K = i;
                break;
            }
        }
        solve(K,N);
        cout<<endl;
   }
    return 0;
}
